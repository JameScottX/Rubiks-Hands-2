#ifndef SIMDISPLAY_H_
#define  SIMDISPLAY_H_

#include "stm32f4xx.h"

void DisPlay_16(USART_TypeDef * pUSARTx,short data);
void DisPlay_32(USART_TypeDef * pUSARTx,int data);
	
void DisPlay_16S(USART_TypeDef * pUSARTx,short *datas);
void DisPlay_32S(USART_TypeDef * pUSARTx,int *datas);

void DisPlay_F64(USART_TypeDef * pUSARTx,double data);
void DisPlay_F64S(USART_TypeDef * pUSARTx,double *datas,unsigned char size_);



void DisPlay_StrInt2(int val1,int val2);
void DisPlay_StrFloat2(float val1,float val2);
void DisPlay_StrFloat4(float val1,float val2,float val3,float val4);


void Usart_SendByte_( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendArray_(USART_TypeDef * pUSARTx,uint8_t *words,u16 length);

void b16_To_h_(const short *val,char hex[2]);
void b32_To_h_(const int *val,char hex[4]);
void b64_To_h_(const double *val,char hex[8]);




#endif




