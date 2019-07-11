#include "stm32f4xx.h"

#define SUCCESS  0X01
#define FAILURE  0X02

#define delay_handoc delay_ms(90)

#define EXCHANGE(a,b)   {TEMP = a;a=b;b=TEMP;}

#define SINGNAL_STEP_TOLOC 5
#define MOTORPOSC   0xF1  

#define TURN_FOR_CAMERA  0xF5

#define L_S_90 1
#define L_N_90 2
#define L_180  3
#define R_S_90 4
#define R_N_90 5
#define R_180  6
#define L_O    7
#define L_C    8
#define R_O    9
#define R_C    10
#define L_2LOC 11
#define R_2LOC 12

#define L_S_90_2 21
#define L_N_90_2 22
#define L_180_2  23
#define R_S_90_2 24
#define R_N_90_2 25
#define R_180_2  26


void Local_Config(void);
void L_TURN_Func(short i);
void R_TURN_Func(short i);
short L_State(void);
short R_State(void);
void Run_Func(char func);

void setL_State(short state);
void setR_State(short state);

