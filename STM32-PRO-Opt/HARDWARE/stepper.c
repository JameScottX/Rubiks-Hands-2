#include "stepper.h"
#include "delay.h"
#include "encoder.h"
#include "math.h"
#include "loctrans.h"

#define MINITIME   22   //6实验最小  
#define MINITIME2  22  //防止魔方错位
#define CONTROL_AREA  200
#define CONTROL_AREA2 200

#define delay_2    5//4
#define delay_3    2

const short Acc_Len2 =200;
const short Sld_Len2 =200;
const short Acc_Len =200;
const short Sld_Len =200;

//400 32 
//const short R90_acc_delay2[] = {39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32};
//32
//const short R90_acc_delay2[] = {39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32};
//30
//	const short R90_acc_delay2[] = {39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
	//const short R90_acc_delay2[] = {39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,34,34,34,34,34,34,34,34,33,33,33,33,33,33,33,32,32,32,32,32,32,32,31,31,31,31,31,31,31,30,30,30,30,30,30,30,30,30,29,29,29,29,29,29,29,29,29,28,28,28,28,28,28,28,28,28,28,28,28,28,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26};
//const short R90_acc_delay2[] = {39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,34,34,34,34,34,34,34,34,33,33,33,33,33,33,32,32,32,32,32,32,32,31,31,31,31,31,31,31,30,30,30,30,30,30,30,29,29,29,29,29,29,29,29,28,28,28,28,28,28,28,28,28,27,27,27,27,27,27,27,27,27,27,27,27,27,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25};

//稳定
//const short R90_acc_delay2[] = {39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,34,34,34,34,34,34,34,33,33,33,33,33,33,32,32,32,32,32,32,32,31,31,31,31,31,31,30,30,30,30,30,30,30,29,29,29,29,29,29,28,28,28,28,28,28,28,28,27,27,27,27,27,27,27,27,27,26,26,26,26,26,26,26,26,26,26,26,26,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24};	
//稳定
const short R90_acc_delay[]={39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,34,34,34,34,34,34,33,33,33,33,33,33,32,32,32,32,32,31,31,31,31,31,31,30,30,30,30,30,29,29,29,29,29,28,28,28,28,28,28,27,27,27,27,27,27,26,26,26,26,26,26,25,25,25,25,25,25,25,24,24,24,24,24,24,24,24,24,23,23,23,23,23,23,23,23,23,23,23,23,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21};
const short R90_acc_delay2[]={39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,34,34,34,34,34,34,33,33,33,33,33,33,32,32,32,32,32,31,31,31,31,31,31,30,30,30,30,30,29,29,29,29,29,28,28,28,28,28,28,27,27,27,27,27,27,26,26,26,26,26,26,25,25,25,25,25,25,25,24,24,24,24,24,24,24,24,24,23,23,23,23,23,23,23,23,23,23,23,23,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21};

	
void stepperInit(void){

	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(HAND_L_CLOCK_, ENABLE);
  RCC_AHB1PeriphClockCmd(HAND_R_CLOCK_, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = _PUL_HAND_L|_DIR_HAND_L; //点击这里查看接线
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(_PORT_HAND_L, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = _PUL_HAND_R|_DIR_HAND_R;  //点击这里查看接线
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(_PORT_HAND_R, &GPIO_InitStructure);
	
	EncoderInit();     //编码器配置
  TIM_SetCounter(TIM2,0);
	TIM_SetCounter(TIM3,0);
	
}

short count_for_pos = 0;
short count_num =5;

void L_Hand_GoOri(short delay_,short area_){
	
		count_for_pos=0;
		while(1){
				
			 if(count_for_pos >= count_num){
					break;
				}else if(L_Encoder < 0){
					
					_PORT_HAND_L->HAND_L_N = _DIR_HAND_L;count_for_pos =0;
				
				}else if(L_Encoder > 0){
					
					_PORT_HAND_L->HAND_L_S = _DIR_HAND_L;count_for_pos =0;
				
				}else if(abs(0 - L_Encoder)<area_){			
					count_for_pos++;
				}
				
				if(count_for_pos==0){
				_PORT_HAND_L->BSRRL = _PUL_HAND_L;
				delay_us(5);	
				_PORT_HAND_L->BSRRH = _PUL_HAND_L;
				delay_us(delay_);	
				}else {
				delay_us(10);	
				}	
			}
}
void R_Hand_GoOri(short delay_,short area_){
	
	
	  count_for_pos=0;		
		while(1){
			
	    if(count_for_pos >= count_num){
			   break;
			}else if(R_Encoder > 0){
				_PORT_HAND_R->HAND_R_S = _DIR_HAND_R;count_for_pos =0;
			}else if(R_Encoder < 0 ){
			  _PORT_HAND_R->HAND_R_N = _DIR_HAND_R;count_for_pos =0;
			}else if(abs(0 - R_Encoder)<area_){
			  count_for_pos++;
			} 
			
	    if(count_for_pos ==0){			
				_PORT_HAND_R->BSRRL = _PUL_HAND_R;
				delay_us(5);
				_PORT_HAND_R->BSRRH = _PUL_HAND_R;
				delay_us(delay_);
			}else {
			  delay_us(10);
			}	
		}	

}	
	
void Motor_PosCorrection(){ //先给编码器上电，在给电机上电

	if(L_State() !=0 || R_State() !=0){				
		if(L_State() %2!=0 && R_State() %2==0){
     L_Hand_GoOri(100,200);	setL_State(0);		
		 R_Hand_GoOri(100,200); setR_State(0);	
		}else{
		 R_Hand_GoOri(100,200); setR_State(0);
		 L_Hand_GoOri(100,200);	setL_State(0);
		}
	}
	//精定位
	L_Hand_GoOri(900,2);	setL_State(0);
	R_Hand_GoOri(900,2);	setR_State(0);
	
}


short Speed_Control_list(short nowpos,short targetpos,short earlypos){
    
	  short all_len = fabs(targetpos - earlypos);
		short dir_now = fabs(targetpos - nowpos);
	  short i = all_len - dir_now;
	
	  if(i<Acc_Len){				
			return R90_acc_delay[i];		
		}else if(Acc_Len<=i && i<= all_len - Sld_Len){
		  return R90_acc_delay[Acc_Len-1];                  //最小速度
		}else if(i> all_len - Sld_Len){	
		  if(i >= all_len){
			 return R90_acc_delay[0];
			}else{			
			 return R90_acc_delay[all_len - i];
			}		
		}		
}


short Speed_Control_list2(short nowpos,short targetpos,short earlypos){
    
	  short all_len = fabs(targetpos - earlypos);
		short dir_now = fabs(targetpos - nowpos);
	  short i = all_len - dir_now;
	
	  if(i<Acc_Len2){				
			return R90_acc_delay2[i];		
		}else if(Acc_Len2<=i && i<= all_len - Sld_Len2){
		  return R90_acc_delay2[Acc_Len2-1];                  //最小速度
		}else if(i> all_len - Sld_Len2){	
		  if(i >= all_len){
			 return R90_acc_delay2[0];
			}else{			
			 return R90_acc_delay2[all_len - i];
			}		
		}
}


short SpeedControl(short nowpos,short targetpos,short earlypos){

    short i=0;
	  short dif_z =0;
	  short dir_compare = fabs(targetpos - earlypos) - CONTROL_AREA;
			
	  dif_z = fabs(targetpos - nowpos);

	  
		if(dif_z > dir_compare){
	
			 i = (short)(dif_z * 0.04);   //加减速 衔接 计算公式  MINITIME  /  dir_compare
			 
		}else if(dif_z < CONTROL_AREA){
	
			 i = (short)(fabs(nowpos - earlypos)*0.8);
		}
				
		if(i<MINITIME){			
			i = MINITIME;
		}
		
	  return i;
}


short SpeedControl2(short nowpos,short targetpos,short earlypos){

    short i=0;
	  short dif_z =0;
	  short dir_compare = fabs(targetpos - earlypos) - CONTROL_AREA2;
			
	  dif_z = fabs(targetpos - nowpos);
	  
		if(dif_z > dir_compare){
	
			 i = (short)(dif_z * 0.04);   //加减速 衔接 计算公式  MINITIME  /  dir_compare
			 
		}else if(dif_z < CONTROL_AREA2){
	
			 i = (short)(fabs(nowpos - earlypos)*0.8);
			 
		}
				
		if(i<MINITIME2){			
			i = MINITIME2;
		}
		
	  return i;
}


void stepperRun_L_s(short num,char func){        //左手顺势针
	
	  short delay_ =0;
	  short eraly_ = L_Encoder;
	  short target_ =0; 
	  char c_=0;
	  if(num == R90){	
			
			L_TURN_Func(-1);                     //************
	   	target_ =(L_State()*R90);	
      			
		}else if(num == R180){
			L_TURN_Func(-2);                    //************
  	  target_ = (L_State()*R90);		
		}else if(num ==R270){
			L_TURN_Func(-3);                    //************
  	  target_ = (L_State()*R90);	
		}
	
  	_PORT_HAND_L->HAND_L_S = _DIR_HAND_L;
		

    while(1){

			if(L_Encoder < target_){
				
				_PORT_HAND_L->HAND_L_N = _DIR_HAND_L;


			}else if(L_Encoder > target_){
				
				_PORT_HAND_L->HAND_L_S = _DIR_HAND_L;
   
				
			}else if(abs(target_ -L_Encoder)<20){	
        c_ =1;				
				delay_us(1);
				if(abs(target_ -L_Encoder)<20){
				break;
			}
			}
	
			if(func ==1){delay_ = Speed_Control_list(L_Encoder,target_,eraly_);
			delay_ -=delay_3;}
			else if(func ==2){delay_ = Speed_Control_list2(L_Encoder,target_,eraly_);
			
			}
			if(c_){
			delay_us(1);
			}
				_PORT_HAND_L->BSRRL = _PUL_HAND_L;
				delay_us(delay_2);	
				_PORT_HAND_L->BSRRH = _PUL_HAND_L;
				delay_us(delay_);	
		}
}


void stepperRun_L_n(short num, char func){        //左手逆时针
	
		short delay_ =0;
		short eraly_ = L_Encoder;
		short target_ =0;
	  char c_=0;
    
	  if(num == R90){	
			L_TURN_Func(1);                   //************       
	   	target_ =(L_State()*R90);			
		}else if(num == R180){
			L_TURN_Func(2);                   //************
  	  target_ = (L_State()*R90);
		}else if(num == R270){
		  L_TURN_Func(3);                   //************
  	  target_ = (L_State()*R90);
		}
	
  	_PORT_HAND_L->HAND_L_N = _DIR_HAND_L;
	
    while(1){
			
		 if(L_Encoder > target_){
			_PORT_HAND_L->HAND_L_S = _DIR_HAND_L;
		}else if(L_Encoder < target_){
			_PORT_HAND_L->HAND_L_N = _DIR_HAND_L;
		}else if(abs(target_ -L_Encoder)<20){
			c_=1;
			delay_us(1);
			if(abs(target_ -L_Encoder)<20){
			break;
			}
			
		}
		
		if(func ==1){delay_ = Speed_Control_list(L_Encoder,target_,eraly_);delay_ -=delay_3;}
		else if(func ==2){delay_ = Speed_Control_list2(L_Encoder,target_,eraly_);}
		if(c_){
			delay_us(1);
			}
		_PORT_HAND_L->BSRRL = _PUL_HAND_L;
		delay_us(delay_2);
			
		_PORT_HAND_L->BSRRH = _PUL_HAND_L;
		delay_us(delay_);
		}
}


void stepperRun_R_s(short num,char func){           //右手顺时针
	
	  short delay_ =0;
		short eraly_ = R_Encoder;
		short target_ =0;
		char c_=0;
		if(num == R90){	
			R_TURN_Func(-1);                 //************
			target_ =(R_State()*R90);			
		}else if(num == R180){      
			R_TURN_Func(-2);                  //************
			target_ = (R_State()*R90);
		}else if(num == R270){
			R_TURN_Func(-3);                  //************
			target_ = (R_State()*R90);
		}
		
  	_PORT_HAND_R->HAND_R_S = _DIR_HAND_R;
	  
		while(1){
			if(R_Encoder > target_){
				_PORT_HAND_R->HAND_R_S = _DIR_HAND_R;
			}else if(R_Encoder < target_ ){
			  _PORT_HAND_R->HAND_R_N = _DIR_HAND_R;
			}else if(abs(target_ -R_Encoder)<20){
				c_=1;
				delay_us(1);
				if(abs(target_ -R_Encoder)<20){
					break;
				}			
			}
			
			if(func ==1){delay_ = Speed_Control_list(R_Encoder,target_,eraly_);delay_ -=delay_3;}
		  else if(func ==2){delay_ = Speed_Control_list2(R_Encoder,target_,eraly_);}
		  if(c_){
			delay_us(1);
			}
			_PORT_HAND_R->BSRRL = _PUL_HAND_R;
			delay_us(delay_2);
			_PORT_HAND_R->BSRRH = _PUL_HAND_R;
			delay_us(delay_);	
		}
}

void stepperRun_R_n(short num,char func){           //右手逆时针
	
	  short delay_ =0;
		short eraly_ = R_Encoder;
		short target_ =0;	
	  char c_=0;
		if(num == R90){	
			R_TURN_Func(1);                 //************
			target_ =(R_State()*R90);			
		}else if(num == R180){      
			R_TURN_Func(2);                  //************
			target_ = (R_State()*R90);
		}else if(num == R270){
			R_TURN_Func(3);                  //************
			target_ = (R_State()*R90);
		}
		
  	_PORT_HAND_R->HAND_R_N = _DIR_HAND_R;
	  
		while(1){
			
			if(R_Encoder < target_){
				_PORT_HAND_R->HAND_R_N = _DIR_HAND_R;
			}else if(R_Encoder > target_){
				_PORT_HAND_R->HAND_R_S = _DIR_HAND_R;
			}else if(abs(target_ -R_Encoder)<20){
				c_=1;
				delay_us(1);
				if(abs(target_ -R_Encoder)<20){
					break;
				}				
			}
			
			if(func ==1){delay_ = Speed_Control_list(R_Encoder,target_,eraly_);delay_ -=delay_3;}
		  else if(func ==2){delay_ = Speed_Control_list2(R_Encoder,target_,eraly_);}
			if(c_){
			delay_us(1);
			}
			_PORT_HAND_R->BSRRL = _PUL_HAND_R;
			delay_us(delay_2);
			_PORT_HAND_R->BSRRH = _PUL_HAND_R;
			delay_us(delay_);			
		}
}

