#ifndef MAGIC_H
#define MAGIC_H

#include <QMainWindow>
#include <QTimer>
#include "colorhandle.h"
#include "core.h"
#include <QMessageBox>
#include "cameraset.h"
#include "stepopt.h"


namespace Ui {
class Magic;
}


class Magic : public QMainWindow
{
    Q_OBJECT

public:

    explicit Magic(QWidget *parent = 0);
    ~Magic();

private:

    Ui::Magic *ui;
    QThread *imageTh;      //图片处理线程
    QTimer *refreshIge =new QTimer();

    serial *Mserial;   //串口通讯

    QPixmap mp;

    colorhandle *mImage; //视觉处理
    core *magic_core;   //模仿求解核心算法

    StepOpt *step_opt;  //优化类

    cv::Mat tempimg;
    cv::Mat tempimg2;
    void UI_Config(void);
    QTimer *serial_refresh = new QTimer();
    void area2_Show(char cho);
    QByteArray array;
    void turn2_code();
    char judge_(char get);
    std::string codeSetIn[20];
    char element_central[6];
    short element_count_judge[6];
    short turn4_otherelement = 0;
    void turn4_other();
    void box_pullBack();
    QTimer time2_count;
    unsigned short s_ =0;
    unsigned short ms_ =0;
    unsigned char Camera_Params_Adjust = 0;

    void ALLReady();
    void num_show(QString loc,char *get);

private:
	char judge_pix2(cv::Vec3b pix_get);
    CameraSet myCamera;
    void CameraSetInit();
    bool showParams_Flag = true;
    char cameraFNum = 1;
    char cameraBNum = 2;
    char listCamera[3] = {0,1,2};

	void start_func_1();
	void start_func_2();
	void start_func_3();

    bool start_func_all_flag = false;
    short start_func_all_count = 0;
    void start_func_all();

private slots:

    void imageRefresh();

    void info_clear();
    void serial_dector();
    void serial_connect();
    void Motor_PosCorrection();
    void time_refresh();
    void myCamera_setParams();
    void serial_getBits();

    void showParams();
    void OpenCamera();
    bool eventFilter(QObject *obj,QEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

};

#endif // MAGIC_H
