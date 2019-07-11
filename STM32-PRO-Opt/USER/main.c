#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "stepper.h"
#include "ssr.h"
#include "loctrans.h"
#include "Sim_Display.h"

#define motor_step_len =5;

int main(void){
	
//	char a_[]={7,25,8,9,12,10,0,7,25,8,8,9,23,10,8,6,9,21,10,9,9,12,23,10,9,9,22,10,7,11,8,0,9,12,22,10,7,11,8,0,9,12,23,10,12,9,12,10,

//12,7,26,8,9,12,10,0,7,24,8,9,7,11,26,8,12,9,23,10,7,9,12,10,3,3,7,24,8,0,3,7,25,8,0,3,6,7,24,8,9,12,10,0,9,12,23,10,0,4,

//9,23,10,0,7,25,8,9,12,10,0,7,24,8,0,9,23,10,0,7,25,8,9,12,10,0,7,25,8,0,3,7,25,8,9,12,10,0,7,24,8,0};
	//char a_[] = {9,21,10,7,11,8,6,7,26,8,3,4,9,12,22,10,7,11,8,6,9,21,10,7,11,8,6,9,21,10,7,11,8,6,3,9,22,10,7,11,8,5,9,12,21,10,7,11,8,6,9,23,10,6,3,9,23,10,6,7,26,8,3,9,21,10,7,11,8,6,9,22,10,7,11,8,6,9,23,10,6};
	//char a_[] = {9,21,10,7,11,8,6,7,26,8,3,9,22,10,7,11,8,6,1,9,21,10,4,9,12,23,10,4,9,12,22,10,7,11,8,4,9,12,22,10,7,11,8,6,9,23,10,6,3,7,26,8,3,9,22,10,7,11,8,4,9,12,23,10,6,9,21,10,7,11,8,4,9,12,22,10,7,11,8,6,9,21,10,7,11,8,6};
	//char a_[] = {7,26,8,1,7,11,26,8,1,7,11,8,5,7,26,8,9,12,10,1,9,22,10,5,9,12,21,10,7,11,8,5,9,12,22,10,7,11,8,5,9,12,21,10,7,11,8,6,9,23,10,4,9,12,21,10,7,11,8,4,7,26,8,9,12,10,3,9,21,10,7,11,8,4,9,12,22,10,7,11,8,4,9,12,22,10,7,11,8,6,9,21,10,7,11,8,6,7,26,8,3};
	//char a_[] = {9,3,10,4,7,6,8,9,12,10,3,9,1,10,7,11,8,6,2,7,11,8,5,9,12,2,10,7,11,8,5,9,12,1,10,7,11,8,4,9,12,1,10,7,11,8,6,9,2,10,7,11,8,5,9,12,2,10,7,11,8,4,9,12,1,10,7,11,8,6,9,1,10,7,11,8,6,9,2,10,7,11,8,4,9,12,1,10,7,11,8,6,9,2,10,7,11,8,6,3};
	 // char a_[] = {7,5,8,9,12,10,3,5,7,5,8,1,9,1,10,5,7,6,8,9,12,10,1,9,3,10,7,11,8,4,7,5,8,3,9,3,10,4,9,12,10,1,9,3,10,7,11,8,5,7,4,8,3,5,7,4,8,1,7,11,8,4,9,12,10,3,4};
    short a_i =0;
	  unsigned char byte_get[1];
   	delay_init(168);
    uart_init(115200); 
	  LED_Init();
	  stepperInit(); //步进电机参数配置
	  ssr_Config();  //继电器参数配置
	  Local_Config();

		SSR_L_O;
		SSR_R_O;	
	  SSR_UP_U;     //使用工装
//		delay_ms(5000);
//			
//		SSR_L_C;
//		SSR_R_C;
//		delay_ms(1000);
//		SSR_UP_D;
//			
//    delay_ms(1000);
//	  
//		delay_ms(2000);
			
	  while(1){
//			
//			delay_ms(1000);
			//DisPlay_StrInt2(0,sizeof(a_) / sizeof(char));
//		if(a_i >= (sizeof(a_) / sizeof(char))){
//		  while(1);
//		}
//		
//		byte_get[0] = a_[a_i];a_i++;

		Queue_Read_NumData(byte_get,1);
			
		if((byte_get[0]) == TURN_FOR_CAMERA){
			
			SSR_R_O;
			delay_handoc;
			stepperRun_L_n(R90,2);	//attention
			SSR_R_C;
			delay_handoc;
			SSR_L_O;
			delay_handoc;
			stepperRun_L_s(R90,2);		 //attention
			SSR_L_C;
			
			delay_ms(100);   //测试后确定
			USART1_SendDatas('R');    //转换面完成信号
			
		}else if((byte_get[0]) == MOTORPOSC){      //电机矫正
			
		  Motor_PosCorrection();
			
		}else if((byte_get[0]) ==AUTO_PUTCUBE){
		
			SSR_L_C;
			SSR_R_C;
			delay_ms(100);
			SSR_UP_D;
		}		
		else{
					
     // DisPlay_StrInt2(0,a_i);
			Run_Func(byte_get[0]);
			if(Queue_DataSize == 0){	
				USART1_SendDatas('S'); 
				SSR_L_O;
				SSR_R_O;	
			}				
	}	
	
	//**********The program below is the code to test the way of the hands's work************************************	

//	delay_ms(2000);
//////	delay_ms(5000);
//	stepperRun_L_n(R180,1);
//DisPlay_StrInt2(L_Encoder,R_Encoder);

//	delay_ms(1000);
//	stepperRun_L_s(R180,1);
//	delay_ms(1000);
//  DisPlay_StrInt2(L_Encoder,R_Encoder);
  //stepperRun_L_n(R180,1);
//	DisPlay_StrInt2(L_Encoder,R_Encoder);
//	delay_ms(1000);
//	stepperRun_R_s(R180,1);
//	delay_ms(1000);
//  DisPlay_StrInt2(L_Encoder,R_Encoder);
//	stepperRun_L_n(R180,2);
//	delay_ms(1000);
	//stepperRun_R_n(R180,2);
//	delay_ms(1000);
//	
     
//		 L_test_();
//		 delay_ms(1000);
//		 
//		R_test_();
//delay_ms(1000);
//		 stepperRun_L_s(R180,2);
//		 delay_ms(1000);
//		 stepperRun_L_n(R180,2);
//		 delay_ms(1000);
//		 stepperRun_L_s(R90,1);
//		 delay_ms(1000);
//		 stepperRun_L_n(R90,1);
//		 delay_ms(1000);
//		 stepperRun_R_s(R90,1);

//		 delay_ms(1000);
//		 stepperRun_R_n(R90,1);
		// DisPlay_StrInt2(R_Encoder,L_Encoder);
//		 delay_ms(1000);
//			delay_ms(300);
//		 

//		 SSR_L_O;
//		 delay_ms(1000);
//		 		 
//		 SSR_R_O;
//		 delay_ms(1000);
//		 
//		 SSR_L_C; 
//		 delay_ms(1000);
//		 SSR_R_C; 
//		 delay_ms(1000); 
// 

}		 
}





