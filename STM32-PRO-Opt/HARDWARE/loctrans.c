#include "loctrans.h"
#include "stepper.h"
#include "ssr.h"
#include "delay.h"
#include "usart.h"
#include "Sim_Display.h"

char TEMP;

void R_return_Loc(char way);
void L_return_Loc(char way);

typedef struct{
	
	 char local_way;                   //旋转方式

	 short local_handL_State;
	 short local_handR_State;
	 
	 short local_opt;
	
}local_;


local_ cubeloc;

void Local_Config(void){
	
   cubeloc.local_handL_State  = 0;
	 cubeloc.local_handR_State  = 0;
}

void L_TURN_Func(short i){  //旋转记录状态 左手
	
    cubeloc.local_handL_State +=i;
}

void R_TURN_Func(short i){  //旋转记录状态 右手

		cubeloc.local_handR_State +=i;
}

void setL_State(short state){
		cubeloc.local_handL_State =0;
}
void setR_State(short state){
		cubeloc.local_handR_State =0;
}
short L_State(){

    return cubeloc.local_handL_State;
}

short R_State(){

    return cubeloc.local_handR_State;
}


__inline void L_RotateWay_S(short num){

	   stepperRun_L_s(num,1);	 	//顺时针记录旋转表示量    
}

__inline void L_RotateWay_N(short num){

	   stepperRun_L_n(num,1);	 	  //逆时针记录旋转表示量     
}

__inline void R_RotateWay_S(short num){

	   stepperRun_R_s(num,1);	 	
}

__inline void R_RotateWay_N(short num){

	   stepperRun_R_n(num,1);	 	

}


void L_way2_Rotate(void){        //旋转方式
	
	 R_return_Loc(1);         //这里的 归位 操作 需要进行下一次旋转进行与判处  可以优化的地方
	
   switch(cubeloc.local_way){
		 
		 case '1':
			 
		 if(cubeloc.local_handL_State <= -4){
				L_RotateWay_N(R270);
		 }else{
				L_RotateWay_S(R90);
		 }	 
		 
		 break;
		 
		 case '3':
     if(cubeloc.local_handL_State >= 4){
				L_RotateWay_S(R270);
		 }else{
				L_RotateWay_N(R90);
		 }		 
		 break;
		 
		 case '2':
		 
		 if(cubeloc.local_handL_State >0){L_RotateWay_S(R180);}
		 else if(cubeloc.local_handL_State <=0){L_RotateWay_N(R180);}

		 break;

		 default:
			 break;
	 }
}

void R_way2_Rotate(void){        //旋转方式
	 
	 L_return_Loc(1);    //这里的 归位 操作 需要进行下一次旋转进行与判处  可以优化的地方
	
   switch(cubeloc.local_way){
		 case '1':
			 
		 if(cubeloc.local_handR_State <= -4){
				R_RotateWay_N(R270);
		 }else{
				R_RotateWay_S(R90);
		 }	 
     
		 break;
		 
		 case '3':
			 
		 if(cubeloc.local_handR_State >= 4){
				R_RotateWay_S(R270);
		 }else{
				R_RotateWay_N(R90);
		 }		 
		 
		 break;		 
		 case '2':
			 
		 if(cubeloc.local_handR_State>0){R_RotateWay_S(R180);}
		 else if(cubeloc.local_handR_State<=0){R_RotateWay_N(R180);}	 
		 
		 break;
		 default:
			 break;
	 }
}


void R_return_Loc(char way){      //右手归位
				
	if(cubeloc.local_handR_State%2 != 0){			
		
		if(way ==1){    //右手自回归
				SSR_R_O;
				delay_handoc;
		}
		
		if(cubeloc.local_handR_State > 0){		
      		
				 R_RotateWay_S(R90);
				
		}else if(cubeloc.local_handR_State < 0){
		  
				R_RotateWay_N(R90);
		}
		
		if(way ==1){    //判断使用方式
				SSR_R_C;
				delay_handoc;
		}
	}
}


void L_return_Loc(char way){    //左手归位

		if(cubeloc.local_handL_State%2 != 0){
				
		if(way ==1){    //判断使用方式
			
				SSR_L_O;
				delay_handoc;
		}
		
		if(cubeloc.local_handL_State >0){		
      
					 L_RotateWay_S(R90);
			
			}else if(cubeloc.local_handL_State < 0 ){

					 L_RotateWay_N(R90);

		}
		
		if(way ==1){    //判断使用方式
				SSR_L_C;
				delay_handoc;
			}
	}
}




void L_func(char func){
	
	if(func == L_S_90){
		if(cubeloc.local_handL_State <= -4){
					L_RotateWay_N(R270);
		}else{
					L_RotateWay_S(R90);
		}
	}else if(func == L_N_90){
		if(cubeloc.local_handL_State >= 4){
				L_RotateWay_S(R270);
		 }else{
				L_RotateWay_N(R90);
		 }		
	}else if(func == L_180){
			if(cubeloc.local_handL_State>0){L_RotateWay_S(R180);}
			else if(cubeloc.local_handL_State<=0){L_RotateWay_N(R180);}	
			
	}else if (func == L_S_90_2){
		
	  if(cubeloc.local_handL_State <= -4){
					stepperRun_L_n(R270,2);
		}else{
					stepperRun_L_s(R90,2);
		}
	
	}else if(func == L_N_90_2){
		if(cubeloc.local_handL_State >= 4){
			stepperRun_L_s(R270,2);
		}else{
			stepperRun_L_n(R90,2);
		}
		
	}else if(func ==L_180_2){
	
		if(cubeloc.local_handL_State>0){stepperRun_L_s(R180,2);}
		else if(cubeloc.local_handL_State<=0){stepperRun_L_n(R180,2);}	
	}else if(func == L_2LOC){	
		
		if(cubeloc.local_handL_State >0){	
			 L_RotateWay_S(R90);			
		}else if(cubeloc.local_handL_State < 0 ){
			 L_RotateWay_N(R90);
			}
	 }
}

void R_func(char func){
	
	if(func == R_S_90){
		if(cubeloc.local_handR_State <= -4){
					R_RotateWay_N(R270);
		}else{
					R_RotateWay_S(R90);
		}
	}else if(func == R_N_90){
		if(cubeloc.local_handR_State >= 4){
				R_RotateWay_S(R270);
		 }else{
				R_RotateWay_N(R90);
		 }		
	}else if(func == R_180){
			if(cubeloc.local_handR_State>0){R_RotateWay_S(R180);}
			else if(cubeloc.local_handR_State<=0){R_RotateWay_N(R180);}	
			
	}else if (func == R_S_90_2){
		
	  if(cubeloc.local_handR_State <= -4){
					stepperRun_R_n(R270,2);
		}else{
					stepperRun_R_s(R90,2);
		}
	
	}else if(func == R_N_90_2){
		
		if(cubeloc.local_handR_State >= 4){
			stepperRun_R_s(R270,2);
		}else{
			stepperRun_R_n(R90,2);
		}
		
	}else if(func ==R_180_2){	
		if(cubeloc.local_handR_State>0){stepperRun_R_s(R180,2);}
		else if(cubeloc.local_handR_State<=0){stepperRun_R_n(R180,2);}	
	}else if(func == R_2LOC){	
		
		if(cubeloc.local_handR_State >0){	
			 R_RotateWay_S(R90);			
		}else if(cubeloc.local_handR_State < 0 ){
			 R_RotateWay_N(R90);
			}
	  }
}


void Run_Func(char func){

	if((1<=func&& func <=3) || 
		(21<=func && func <=23) || 
      func == L_2LOC){
	    L_func(func);
	}else if((4<=func&& func <=6) || 
		(24<=func&& func <=26) ||
	  func == R_2LOC){
		  R_func(func);
	}else if(func == L_O){
		SSR_L_O;
		delay_handoc;		
	}else if(func == L_C){
	  SSR_L_C;
		delay_handoc;
	}else if(func == R_O){
	  SSR_R_O;
		delay_handoc;	
	}else if(func == R_C){
	  SSR_R_C;
		delay_handoc;	
	}
}





