#ifndef STEPPPER_H_
#define STEPPPER_H_

#include "stm32f4xx_conf.h"

#define HAND_L_CLOCK_     RCC_AHB1Periph_GPIOE
#define _PORT_HAND_L      GPIOE      //×óÊÖ
#define _PUL_HAND_L       GPIO_Pin_2
#define _DIR_HAND_L       GPIO_Pin_3
#define HAND_L_S          BSRRH
#define HAND_L_N          BSRRL

#define HAND_R_CLOCK_     RCC_AHB1Periph_GPIOE
#define _PORT_HAND_R      GPIOE     //ÓÒÊÖ
#define _PUL_HAND_R       GPIO_Pin_0
#define _DIR_HAND_R       GPIO_Pin_1
#define HAND_R_S          BSRRH
#define HAND_R_N          BSRRL

#define L_Encoder (short)TIM2->CNT
#define R_Encoder (short)TIM3->CNT
	
#define R90     1024
#define R180    2048
#define R270    3072

void stepperInit(void);
void stepperRun_L_s(short num,char func);
void stepperRun_L_n(short num,char func);
void stepperRun_R_s(short num,char func);
void stepperRun_R_n(short num,char func);

void Motor_PosCorrection(void);




#endif









