﻿#include "magic.h"
#include "ui_magic.h"
#include <QFileDialog>
#include <QDebug>
#include <QMouseEvent>
#include "stepopt.h"
#include "solve.h"

#define OPT 1
#define SHOW_COLOR_HSV_VAL

Magic::Magic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Magic)
{

    ui->setupUi(this);
    UI_Config();
    ui->camera_f->setValue(0);
    ui->camera_b->setValue(2);

    imageTh =new QThread();
    mImage  = new colorhandle();
    //串口初始化
    Mserial = new serial();

    //开启图片处理线程
    mImage->moveToThread(imageTh);
    imageTh->start();
    //初始化核心算法
    magic_core = new core();

    step_opt = new StepOpt();

    //开启图片动态获取线程
    connect(refreshIge,SIGNAL(timeout()),this,SLOT(imageRefresh()));

    //开启串口端口扫描
    connect(serial_refresh,SIGNAL(timeout()),this,SLOT(serial_dector()));
    serial_refresh->start(2000);
    //串口获取数据信号槽
    connect(Mserial,SIGNAL(serial_GetBits()),this,SLOT(serial_getBits()));

    ui->label_f->installEventFilter(this);
    ui->label_b->installEventFilter(this);

#ifdef OPT
    array.resize(1);
#else
    array.resize(1);
#endif
    //计数显示器初始化
    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    connect(&time2_count,SIGNAL(timeout()),this,SLOT(time_refresh()));

    setAttribute(Qt::WA_DeleteOnClose);
    OpenCamera();
}

Magic::~Magic()
{
    delete imageTh;
    delete refreshIge;
    delete Mserial;
    delete mImage;
    delete magic_core;
    delete serial_refresh;
    delete step_opt;
    delete ui;

}


void Magic::OpenCamera(){

   //打开摄像头
    mImage->capture_f.open(ui->camera_f->value());
    mImage->capture_b.open(ui->camera_b->value());

    mImage->cameraInit();  //摄像头初始化
    mImage->get_Camera_params();//初始化参数
    CameraSetInit();    //初始化 摄像头调参界面

    refreshIge->start(40); //获取图像后进行刷新
}

//串口指令集
void Magic::serial_getBits(){             //这里判断接收的字节

    if(!Mserial->buffer_.isEmpty()){      //‘S’判断是否走完，走完停止计时

        if(Mserial->buffer_.size() == 1){

				if(Mserial->buffer_.at(0) == 'S'){
					Mserial->buffer_.clear();
					time2_count.stop();
                    s_ =0;ms_=0;
                    ui->lcdNumber->display(QString::number(s_) + "." + QString::number(ms_));
				}
				else if (Mserial->buffer_.at(0) == 'R') {    //魔方转换面信号
                    Mserial->buffer_.clear();
                    turn4_otherelement++;
                    if(start_func_all_flag){start_func_all();}	   //一键启动功能
				}
           }
	}
}


//摄像头调参数界面初始化
void Magic::CameraSetInit(){

    myCamera.Slider_SpinInit(mImage->Camera_EXPOSURE_param,//进行摄像头参数的初始赋值，方便在GUI中显示
                             mImage->Camera_SATURATION_param,
                             mImage->Camera_CONTRAST_param,
                             mImage->Camera_BRIGHTNESS_param,
                             mImage->Camera_HUE_param);

    connect(&myCamera,SIGNAL(params_change()),this,SLOT(myCamera_setParams()));      //这里进行GUI设置Camera参数

    myCamera.show();     //显示设置界面

}


void Magic::time_refresh(){      //计时操作

    ms_++;
    if(ms_ >= 100){

       ms_ =0;
       s_++;
    }

     ui->lcdNumber->display(QString::number(s_)+"."+QString::number(ms_));

}


void Magic::Motor_PosCorrection(){

    array.clear();
#ifdef OPT
    array[0] = 0xF1;
#else
    array[0] = 0xF0;
    array[1] = 0x01;

#endif

    Mserial->serialSendData_(array);
}

void Magic::turn4_other(){

    array.clear();
#ifdef OPT
    array[0] = 0xF5;
#else
    array[0] = 0xF0;
    array[1] = 0x05;
#endif
    Mserial->serialSendData_(array);

}

void Magic::box_pullBack(){

    array.clear();
#ifdef OPT
    array[0] = 0xF6;
#else
    array[0] = 0xF0;
    array[1] = 0x06;
#endif
    Mserial->serialSendData_(array);

}

//串口扫描函数
static bool flag =false;
void Magic::serial_dector(){

    QString serial_portName;
    QString serial_systemLocation;
    QString serial_description;
    QString temp;

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){

        serial_portName=info.portName();
        serial_systemLocation=info.systemLocation();
        serial_description=info.description();

        QString tempOut = serial_portName+serial_systemLocation+serial_description;

        if(!flag){

            ui->comboBox_port->addItem(serial_portName);
            flag =true;
        } else {

            for(char i =ui->comboBox_port->count();i>1;i--){

                if(serial_portName != ui->comboBox_port->itemText(i)){
                    ui->comboBox_port->addItem(serial_portName);
                }
           }

        }
        ui->textBrowser_info->setText(temp+tempOut);
        temp = tempOut;
    }
}


//串口链接槽函数
void Magic::serial_connect(){

    static bool serial_flag = false;

    if(!serial_flag){

        Mserial->setSerial(ui->comboBox_port->currentText(),115200,8,0,0);
        serial_refresh->stop();
        ui->textBrowser_info->setText("Done!");
        ui->pushButton_connect->setText(QStringLiteral("断开"));
        serial_flag = true;

    }else{

        disconnect(Mserial->mserial,SLOT(readyRead),Mserial,SIGNAL(serialRevData()));
        Mserial->mserial->clear();
        Mserial->mserial->close();

        ui->textBrowser_info->setText("Shut Down!");
        serial_refresh->start();
        ui->pushButton_connect->setText(QStringLiteral("链接"));
        serial_flag = false;
        ui->comboBox_port->clear();
        flag = false;
    }
}


void Magic::UI_Config(void){

   ui->label_f->setScaledContents(true);
   ui->label_b->setScaledContents(true);
   ui->label_L->setScaledContents(true);
   ui->label_U->setScaledContents(true);
   ui->label_D->setScaledContents(true);
   ui->label_R->setScaledContents(true);
   ui->label_F->setScaledContents(true);
   ui->label_B->setScaledContents(true);

}

//图片刷新
void Magic::imageRefresh(){

    cv::Mat temp_img_f;
    cv::Mat temp_img_b;

    temp_img_f = mImage->imageModel_F;
    temp_img_b = mImage->imageModel_B;

    cv::line(temp_img_f,mImage->_L_U[0],mImage->_L_D[0],cv::Scalar(255,255,0),2,8);
    cv::line(temp_img_f,mImage->_L_U[0],mImage->_C_U[0],cv::Scalar(255,0,0),2,8);
    cv::line(temp_img_f,mImage->_C_U[0],mImage->_R_U[0],cv::Scalar(255,0,255),2,8);
    cv::line(temp_img_f,mImage->_C_U[0],mImage->_C_D[0],cv::Scalar(255,0,255),2,8);
    cv::line(temp_img_f,mImage->_R_U[0],mImage->_R_D[0],cv::Scalar(0,255,255),2,8);
    cv::line(temp_img_f,mImage->_R_D[0],mImage->_C_D[0],cv::Scalar(255,0,0),2,8);
    cv::line(temp_img_f,mImage->_L_D[0],mImage->_C_D[0],cv::Scalar(255,0,0),2,8);

    cv::line(temp_img_b,mImage->_L_U[1],mImage->_L_D[1],cv::Scalar(255,255,0),2,8);
    cv::line(temp_img_b,mImage->_L_U[1],mImage->_C_U[1],cv::Scalar(255,0,0),2,8);
    cv::line(temp_img_b,mImage->_C_U[1],mImage->_R_U[1],cv::Scalar(255,0,255),2,8);
    cv::line(temp_img_b,mImage->_C_U[1],mImage->_C_D[1],cv::Scalar(255,0,255),2,8);
    cv::line(temp_img_b,mImage->_R_U[1],mImage->_R_D[1],cv::Scalar(0,255,255),2,8);
    cv::line(temp_img_b,mImage->_R_D[1],mImage->_C_D[1],cv::Scalar(255,0,0),2,8);
    cv::line(temp_img_b,mImage->_L_D[1],mImage->_C_D[1],cv::Scalar(255,0,0),2,8);

    QImage temp =mImage -> mat2QImage(temp_img_f);
    mp = mp.fromImage(temp);
    ui->label_f->setPixmap(mp);
    ui->label_f->show();

    temp =mImage ->mat2QImage(temp_img_b);
    mp= mp.fromImage(temp);
    ui->label_b->setPixmap(mp);
    ui->label_b->show();

}


void Magic::num_show(QString loc,char *get){

    QString temp;
    QString temp2;

    for(short i =0;i<9;i++){

        switch(get[i]){

        case RED:
           temp2 = "r";
        break;
        case GREEN:
           temp2 = "g";
        break;
        case BLUE:
            temp2 = "b";
            break;
        case YELLOW:
            temp2 = "y";
            break;
         case CHE:
            temp2 = "c";
            break;
        case WHITE:
            temp2 = "w";
            break;
        }
       temp +=  temp2;
    }

    ui->textBrowser_info->append(loc+": "+temp);

}


//将信息面展示出来
void Magic::area2_Show(char cho){ //这里提取对应的面信息

    cv::Mat frame_b_, frame_f_;
    QPixmap element_img;
    QImage tmp;
    cv::Mat hand_last;
    cv::Point point;
    char sf[16];

    frame_b_ = mImage->imageModel_B;
    frame_f_ = mImage->imageModel_F;

    cv::Mat area_quad = cv::Mat::zeros(200,200,CV_8UC3);
    cv::Vec3b HSV_;

    if(cho == 0){//U OK

        mImage -> mWrapHandle(frame_f_, mImage -> U_L_area_corner, area_quad);
        hand_last = mImage->mwrap_area_handle_last(area_quad);

        num_show("U",mImage->part_info);

        for(short x=0;x<3;x++){
            point.x = mImage->length_part3+x* mImage->length_part2;
            for(short y=0;y<3;y++){
                point.y=  mImage->length_part3+y* mImage->length_part2;

                HSV_ = mImage->getPartAeraHSV(hand_last,point);

                if(showParams_Flag){
#ifdef SHOW_COLOR_HSV_VAL
                    sprintf_s(sf,"%d %d %d", HSV_[0],HSV_[1],HSV_[2]);
#else
                    sprintf_s(sf,"%c", "RGBYCW"[mImage -> judge_pix2(HSV_)]);
#endif
                    cvPutText(&(CvMat)hand_last, sf,cv::Point(point.x,point.y), &(mImage->fontcompare), CV_RGB(0, 0, 0));
                }

                cv::circle(hand_last, point, 2,cv::Scalar(0,255,0),2);

            }
        }

        tmp = mImage ->mat2QImage(hand_last);
        element_img= mp.fromImage(tmp);
        ui->label_U->setPixmap(element_img);
        ui->label_U->show();

        memcpy(mImage->tmp_element[cho],mImage->part_info,9);

    }else if(cho ==1){//D OK

        mImage ->mWrapHandle(frame_b_, mImage->D_R_area_corner, area_quad);
        hand_last = mImage->mwrap_area_handle_last(area_quad);

        num_show("D",mImage->part_info);

        for(short x=0;x<3;x++){
            point.x = mImage->length_part3+x* mImage->length_part2;
            for(short y=0;y<3;y++){
                point.y=  mImage->length_part3+y* mImage->length_part2;

                HSV_ = mImage->getPartAeraHSV(hand_last,point);

                if(showParams_Flag){
#ifdef SHOW_COLOR_HSV_VAL
                    sprintf_s(sf,"%d %d %d", HSV_[0],HSV_[1],HSV_[2]);
#else
                    sprintf_s(sf,"%c", "RGBYCW"[mImage -> judge_pix2(HSV_)]);
#endif
                    cvPutText(&(CvMat)hand_last, sf,cv::Point(point.x,point.y), &(mImage->fontcompare), CV_RGB(0, 0, 0));
                }

               cv::circle(hand_last, point, 2,cv::Scalar(0,255,0),2);

            }
        }

        tmp = mImage ->mat2QImage(hand_last);
        element_img= mp.fromImage(tmp);
        ui->label_D->setPixmap(element_img);
        ui->label_D->show();

        memcpy(mImage->tmp_element[cho],mImage->part_info,9);

    }else if(cho ==2){//F OK

        mImage ->mWrapHandle(frame_b_, mImage->D_L_area_corner, area_quad);
        hand_last = mImage->mwrap_area_handle_last(area_quad);

        num_show("F",mImage->part_info);

        for(short x=0;x<3;x++){
            point.x = mImage->length_part3+x* mImage->length_part2;
            for(short y=0;y<3;y++){
                point.y=  mImage->length_part3+y* mImage->length_part2;
                HSV_ = mImage->getPartAeraHSV(hand_last,point);
                if(showParams_Flag){
#ifdef SHOW_COLOR_HSV_VAL
                    sprintf_s(sf,"%d %d %d", HSV_[0],HSV_[1],HSV_[2]);
#else
                    sprintf_s(sf,"%c", "RGBYCW"[mImage -> judge_pix2(HSV_)]);
#endif
                    cvPutText(&(CvMat)hand_last, sf,cv::Point(point.x,point.y), &(mImage->fontcompare), CV_RGB(0, 0, 0));
                }

               cv::circle(hand_last, point, 2,cv::Scalar(0,255,0),2);

            }
        }

        tmp = mImage ->mat2QImage(hand_last);
        element_img= mp.fromImage(tmp);
        ui->label_F->setPixmap(element_img);
        ui->label_F->show();

        memcpy(mImage->tmp_element[cho],mImage->part_info,9);

      }else if(cho ==3){//B OK

        mImage ->mWrapHandle(frame_f_, mImage->U_R_area_corner, area_quad);
        hand_last = mImage->mwrap_area_handle_last(area_quad);

        num_show("B",mImage->part_info);

        for(short x=0;x<3;x++){
            point.x = mImage->length_part3+x* mImage->length_part2;
            for(short y=0;y<3;y++){
                point.y=  mImage->length_part3+y* mImage->length_part2;
                HSV_ = mImage->getPartAeraHSV(hand_last,point);

                if(showParams_Flag){
#ifdef SHOW_COLOR_HSV_VAL
                    sprintf_s(sf,"%d %d %d", HSV_[0],HSV_[1],HSV_[2]);
#else
                    sprintf_s(sf,"%c", "RGBYCW"[mImage -> judge_pix2(HSV_)]);
#endif
                    cvPutText(&(CvMat)hand_last, sf,cv::Point(point.x,point.y), &(mImage->fontcompare), CV_RGB(0, 0, 0));
                }

               cv::circle(hand_last, point, 2,cv::Scalar(0,255,0),2);

            }
        }

       tmp = mImage ->mat2QImage(hand_last);
       element_img= mp.fromImage(tmp);
       ui->label_B->setPixmap(element_img);
       ui->label_B->show();

       memcpy(mImage->tmp_element[cho],mImage->part_info,9);

    }else if(cho ==4){//R OK       //注意*****************************************************************************************

        mImage ->mWrapHandle(frame_f_, mImage->for_R_area_corner, area_quad);
        hand_last = mImage->mwrap_area_handle_last(area_quad);

        num_show("R",mImage->part_info);

        for(short x=0;x<3;x++){
            point.x = mImage->length_part3+x* mImage->length_part2;
            for(short y=0;y<3;y++){
                point.y=  mImage->length_part3+y* mImage->length_part2;
                HSV_ = mImage->getPartAeraHSV(hand_last,point);
                if(showParams_Flag){
#ifdef SHOW_COLOR_HSV_VAL
                    sprintf_s(sf,"%d %d %d", HSV_[0],HSV_[1],HSV_[2]);
#else
                    sprintf_s(sf,"%c", "RGBYCW"[mImage -> judge_pix2(HSV_)]);
#endif
                    cvPutText(&(CvMat)hand_last, sf,cv::Point(point.x,point.y), &(mImage->fontcompare), CV_RGB(0, 0, 0));
                }

               cv::circle(hand_last, point, 2,cv::Scalar(0,255,0),2);

            }
        }

         tmp = mImage ->mat2QImage(hand_last);
        element_img= mp.fromImage(tmp);
        ui->label_R->setPixmap(element_img);
        ui->label_R->show();

        memcpy(mImage->tmp_element[cho],mImage->part_info,9);

    }else if(cho ==5){//L OK

        mImage ->mWrapHandle(frame_b_, mImage->D_R_area_corner, area_quad);
        hand_last = mImage->mwrap_area_handle_last(area_quad);

        num_show("L",mImage->part_info);

        for(short x=0;x<3;x++){
            point.x = mImage->length_part3+x* mImage->length_part2;
            for(short y=0;y<3;y++){
                point.y=  mImage->length_part3+y* mImage->length_part2;
                HSV_ = mImage->getPartAeraHSV(hand_last,point);
                if(showParams_Flag){
#ifdef SHOW_COLOR_HSV_VAL
                    sprintf_s(sf,"%d %d %d", HSV_[0],HSV_[1],HSV_[2]);
#else
                    sprintf_s(sf,"%c", "RGBYCW"[mImage -> judge_pix2(HSV_)]);
#endif
                    cvPutText(&(CvMat)hand_last, sf,cv::Point(point.x,point.y), &(mImage->fontcompare), CV_RGB(0, 0, 0));
                }

               cv::circle(hand_last, point, 2,cv::Scalar(0,255,0),2);

            }
        }

        tmp = mImage ->mat2QImage(hand_last);
        element_img= mp.fromImage(tmp);
        ui->label_L->setPixmap(element_img);
        ui->label_L->show();

        memcpy(mImage->tmp_element[cho],mImage->part_info,9);
    }
}


char Magic::judge_(char get){    //Success 这里判断颜色，形成魔方编码

    for(short i =0 ;i<6;i++){
        if(get == element_central[i] ){
            switch(i){
              case 0:
                element_count_judge[i]++;
                return 'U';              
              case 1:
                element_count_judge[i]++;
                return 'D';               
              case 2:
                element_count_judge[i]++;
                return 'F';               
              case 3:
                element_count_judge[i]++;
                return 'B';
              case 4:
                element_count_judge[i]++;
                return 'R';
              case 5:
                element_count_judge[i]++;
                return 'L';
            }
        }
    }
}


//将信息面转化为魔方编码
void Magic::turn2_code(){             //Success

    char two_[2];
    char three_[3];
    for(short i =0;i<6;i++){
       element_central[i] =  mImage->tmp_element[i][4];   //初始中心
       element_count_judge[i]=0;                          //计数清零
    }

    two_[0] = judge_(mImage->tmp_element[0][3]);        //UF
    two_[1] = judge_(mImage->tmp_element[2][1]);        
    codeSetIn[0] = two_;

    two_[0] = judge_(mImage->tmp_element[0][7]);        //UR
    two_[1] = judge_(mImage->tmp_element[4][1]);
    codeSetIn[1] = two_;

    two_[0] = judge_(mImage->tmp_element[0][5]);
    two_[1] = judge_(mImage->tmp_element[3][1]);
    codeSetIn[2] = two_;

    two_[0] = judge_(mImage->tmp_element[0][1]);
    two_[1] = judge_(mImage->tmp_element[5][1]);
    codeSetIn[3] = two_;


    two_[0] = judge_(mImage->tmp_element[1][5]);        //DF
    two_[1] = judge_(mImage->tmp_element[2][7]);
    codeSetIn[4] = two_;

    two_[0] = judge_(mImage->tmp_element[1][7]);
    two_[1] = judge_(mImage->tmp_element[4][7]);
    codeSetIn[5] = two_;

    two_[0] = judge_(mImage->tmp_element[1][3]);
    two_[1] = judge_(mImage->tmp_element[3][7]);
    codeSetIn[6] = two_;

    two_[0] = judge_(mImage->tmp_element[1][1]);
    two_[1] = judge_(mImage->tmp_element[5][7]);
    codeSetIn[7] = two_;



    two_[0] = judge_(mImage->tmp_element[2][5]);
    two_[1] = judge_(mImage->tmp_element[4][3]);
    codeSetIn[8] = two_;

    two_[0] = judge_(mImage->tmp_element[2][3]);
    two_[1] = judge_(mImage->tmp_element[5][5]);
    codeSetIn[9] = two_;

    two_[0] = judge_(mImage->tmp_element[3][3]);
    two_[1] = judge_(mImage->tmp_element[4][5]);
    codeSetIn[10] = two_;

    two_[0] = judge_(mImage->tmp_element[3][5]);
    two_[1] = judge_(mImage->tmp_element[5][3]);
    codeSetIn[11] = two_;


    three_[0] = judge_(mImage->tmp_element[0][6]);
    three_[1] = judge_(mImage->tmp_element[2][2]);
    three_[2] = judge_(mImage->tmp_element[4][0]);
    codeSetIn[12] = three_;

    three_[0] = judge_(mImage->tmp_element[0][8]);
    three_[1] = judge_(mImage->tmp_element[4][2]);
    three_[2] = judge_(mImage->tmp_element[3][0]);
    codeSetIn[13] = three_;

    three_[0] = judge_(mImage->tmp_element[0][2]);
    three_[1] = judge_(mImage->tmp_element[3][2]);
    three_[2] = judge_(mImage->tmp_element[5][0]);
    codeSetIn[14] = three_;


    three_[0] = judge_(mImage->tmp_element[0][0]);
    three_[1] = judge_(mImage->tmp_element[5][2]);
    three_[2] = judge_(mImage->tmp_element[2][0]);
    codeSetIn[15] = three_;



    three_[0] = judge_(mImage->tmp_element[1][8]);
    three_[1] = judge_(mImage->tmp_element[4][6]);
    three_[2] = judge_(mImage->tmp_element[2][8]);
    codeSetIn[16] = three_;

    three_[0] = judge_(mImage->tmp_element[1][2]);
    three_[1] = judge_(mImage->tmp_element[2][6]);
    three_[2] = judge_(mImage->tmp_element[5][8]);
    codeSetIn[17] = three_;

    three_[0] = judge_(mImage->tmp_element[1][0]);
    three_[1] = judge_(mImage->tmp_element[5][6]);
    three_[2] = judge_(mImage->tmp_element[3][8]);
    codeSetIn[18] = three_;

    three_[0] = judge_(mImage->tmp_element[1][6]);
    three_[1] = judge_(mImage->tmp_element[3][6]);
    three_[2] = judge_(mImage->tmp_element[4][8]);
    codeSetIn[19] = three_;

}


void Magic::start_func_1(){   //逐步进行 获取颜色面  //W

    if(turn4_otherelement ==0){   //第一次，读取四个面
        area2_Show(0);
        area2_Show(3);
        area2_Show(2);
        area2_Show(1);
        turn4_other();        //发送反转面信号
        turn4_otherelement+=1;
		qDebug() << " 4面读取";
    }
}


void Magic::start_func_2(){
	
    if(turn4_otherelement==2){

        area2_Show(4);
        area2_Show(5);
        turn2_code();     
        turn4_otherelement  ++;
		qDebug() << " 2面读取";
	}
}

void Magic::start_func_3(){

    if(turn4_otherelement==3){
        turn4_otherelement  =0;
        ALLReady();  //执行解魔方计算
        qDebug() << " GO NOW !";
    }
}


void Magic::start_func_all(){

    start_func_1();
    start_func_2();
    start_func_3();

}

/********此处优化核心算法重复问题**********/
char QCharToChar(QChar input) {
    return input.toLatin1();
}

QString CubeCodeOptimize(QString input) {
    QString output = input;
    uint8_t previousPointer = 0;
    char count;
    for (int i = 2; i < output.size(); i += 2) {
        if (output[previousPointer] == output[i]) {
            count = 0;
            count = QCharToChar(output[previousPointer + 1]) + QCharToChar(output[i + 1]) - '0' * 2;
            count = count % 4;
            output.remove(previousPointer + 1, 3);
            output.insert(previousPointer + 1, count + '0');
            i -= 2;
        }

        else {
            previousPointer = (uint8_t)i;
        }
    }
    return output;
}

/************************/

void Magic::ALLReady(){

    Opt opt_;
    std::string  temp_out;

//程序保护判断
    try{
        for(short i =0;i<6;i++){
            if(element_count_judge[i] != 8 ){
                throw invalid_argument("!!!!!Corlor is error!!!!");
                break;
            }
        }

    }
    catch(invalid_argument& e){
        ui->textBrowser_info->append(QString::fromStdString(e.what()));
        return;
    }


    for(short i=0 ;i<20;i++){
       temp_out+= codeSetIn[i]+' ';
       //std::cout << codeSetIn[i] << endl;
    }

    ui->lineEdit_get->setText(QString::fromStdString(temp_out));


    QString get = QString::fromStdString(Solve::_Slove(codeSetIn));
    //QString get = CubeCodeOptimize(magic_core->core_caculate(codeSetIn));        //这里计算编码

    int all = step_opt->Opt_Func(get.toStdString(),0xff);
    opt_ =step_opt->Find(all);
    Mserial->serialSendData_(opt_.array);
    ui->textBrowser_info->append("Ori: "+QString::number((opt_.Original)) + " OPT: "+ QString::number((opt_.after_opt)) );

    ui->lineEdit_answer->setText(get);
    time2_count.start(10);

}

void Magic::showParams(){

    if(ui->checkBox_2->isChecked()){
        showParams_Flag = true;
    }else{
        showParams_Flag = false;
    }
}

void Magic::info_clear(){      //简单清除数据
    ui->textBrowser_info->clear();
}


void Magic::myCamera_setParams(){   //设置摄像头参数

    mImage->Camera_BRIGHTNESS_param = myCamera.get_Camera_BRIGHTNESS_param;
    mImage->Camera_SATURATION_param = myCamera.get_Camera_SATURATION_param;
    mImage->Camera_CONTRAST_param = myCamera.get_Camera_CONTRAST_param;
    mImage->Camera_EXPOSURE_param = myCamera.get_Camera_EXPOSURE_param;
    mImage->Camera_HUE_param = myCamera.get_Camera_HUE_param;
    mImage->set_Camera_params();

}

int last_X=0, last_Y =0;
int dir_x =0,dir_y =0;
bool temp_flag =false;
double size_step =0.05;

bool Magic::eventFilter(QObject *obj,QEvent *event){

    if(obj == ui->label_f){  //简单的坐标移动

        if(event->type() == QEvent::MouseButtonPress ){
			QMouseEvent *mousevent = static_cast<QMouseEvent*>(event);
            temp_flag = true;
			last_X = mousevent->pos().x();
			last_Y = mousevent->pos().y();
            return true;

		}
		else if (event->type() == QEvent::MouseButtonRelease) {
			temp_flag = false;
			return true;
		}
		else if (event->type() == QEvent::MouseMove) {
           QMouseEvent *mousevent = static_cast<QMouseEvent*>(event);
             dir_x =0;dir_y =0;

            if(temp_flag){   //第一次进来刷新坐标
                dir_x = (mousevent->pos().x()-last_X);
                dir_y = (mousevent->pos().y()-last_Y);				
            }     

             last_X = mousevent->pos().x();
             last_Y = mousevent->pos().y();

             mImage->point_Config(dir_x, dir_y);

            return true;

        }else if(event->type() == QEvent::Wheel){

           QWheelEvent *wheelevent = static_cast<QWheelEvent*>(event);

           if(wheelevent->delta()>0){

               mImage->point_Config(0,0,0.05);

           }else{

               mImage->point_Config(0,0,-0.05);

           }
           return true;

        }else{
            return false;
        }

    }else if(obj == ui->label_b){
		if (event->type() == QEvent::MouseButtonPress) {
			QMouseEvent *mousevent = static_cast<QMouseEvent*>(event);
			temp_flag = true;
            last_X = mousevent->pos().x();
			last_Y = mousevent->pos().y();
			return true;
		}else
        if(event->type() == QEvent::MouseButtonRelease){
            temp_flag = false;
            return true;

        }else if(event->type() == QEvent::MouseMove){
           QMouseEvent *mousevent = static_cast<QMouseEvent*>(event);
             dir_x =0;dir_y =0;

            if(temp_flag){
                dir_x = mousevent->pos().x()-last_X;
				dir_y = mousevent->pos().y() - last_Y;
            }
             last_X = mousevent->pos().x();
             last_Y = mousevent->pos().y();

             mImage->point_Config2(dir_x,dir_y);

            return true;
        }else if(event->type() == QEvent::Wheel){

            QWheelEvent *wheelevent = static_cast<QWheelEvent*>(event);

            if(wheelevent->delta()>0){

                mImage->point_Config2(0,0,0.05);

            }else{

                mImage->point_Config2(0,0,-0.05);
            }
            return true;

         }else{
            return false;
        }
    }

    return QMainWindow::eventFilter(obj,event);
}


void Magic::keyPressEvent(QKeyEvent *event){

    if (event->key() ==Qt::Key_W){//四面读取并翻转

          start_func_1();

    }else if(event->key() ==Qt::Key_R){  //按键R读取接下来的两个面

           start_func_2();

    }else if(event->key() ==Qt::Key_G){ //开始运行

            start_func_3();

    }else if(event->key() ==Qt::Key_K){  //从头到尾一直运行

        if(!start_func_all_flag){  //防止连续按
            start_func_all_flag = true;
            start_func_all();

        }

	}
	else if (event->key() ==Qt::Key_P) {//从新置位

        start_func_all_flag = false;
		turn4_otherelement = 0;
        time2_count.stop();
        s_ =0;ms_=0;
        ui->lcdNumber->display(QString::number(s_) + "." + QString::number(ms_));
	}
	else if (event->key() == Qt::Key_A) {//工装收回       
        box_pullBack();
	}
	else if (event->key() == Qt::Key_M) {//电机矫正	
		Motor_PosCorrection();
	}
}



void Magic::closeEvent(QCloseEvent *event){

    QMessageBox::StandardButton button;
    button = QMessageBox::question(this,tr("QUIT"),tr("Are you sure to quit?"),QMessageBox::Yes|QMessageBox::No);
    if(button == QMessageBox::No){
        event->ignore();
    }else if (button == QMessageBox::Yes){
        imageTh->quit();
        imageTh->wait();
        event->accept();

    }
}
