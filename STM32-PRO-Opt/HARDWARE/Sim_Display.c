#include "Sim_Display.h"
#include "stdio.h"

void DisPlay_16(USART_TypeDef * pUSARTx,short data){

	char NUM16[2];
	Usart_SendByte_(pUSARTx,'R');
	b16_To_h_(&data,NUM16);
	Usart_SendArray_(pUSARTx,NUM16,2);
	Usart_SendByte_(pUSARTx,10);
	
}


void DisPlay_16S(USART_TypeDef * pUSARTx,short *datas){
		
	 u8 size_ =0,i=0;
	 char NUM16[2];
	
	 size_ = sizeof(datas) / sizeof(short);
   	 
	
	 Usart_SendByte_(pUSARTx,'R');
	 
	 for(;i<size_;i++){	 		
		 
			b16_To_h_(&datas[i],NUM16);
	    Usart_SendArray_(pUSARTx,NUM16,2);		 
	 }
	
   Usart_SendByte_(pUSARTx,10);  //"\n"
}


void DisPlay_32(USART_TypeDef * pUSARTx,int data){

	char NUM32[4];
	Usart_SendByte_(pUSARTx,'R');
	b32_To_h_(&data ,NUM32);
	Usart_SendArray_(pUSARTx,NUM32,4);	
	Usart_SendByte_(pUSARTx,10);
	
}



void DisPlay_32S(USART_TypeDef * pUSARTx,int *datas){

	 u8 size_ =0,i=0;
	 char NUM32[4];
	
	 size_ = sizeof(datas) / sizeof(int);
   
	 Usart_SendByte_(pUSARTx,'R');
	 
	 for(;i<size_;i++){	 		
		 
			b32_To_h_(&datas[i],NUM32);
	    Usart_SendArray_(pUSARTx,NUM32,4);		 
	 }
	
   Usart_SendByte_(pUSARTx,10);  //"\n"
}


void DisPlay_F64(USART_TypeDef * pUSARTx,double data){

    char NUM64[8];
		Usart_SendByte_(pUSARTx,'R');
		b64_To_h_(&data ,NUM64);
		Usart_SendArray_(pUSARTx,NUM64,8);	
		Usart_SendByte_(pUSARTx,10);
	
}


void DisPlay_F64S(USART_TypeDef * pUSARTx,double *datas,unsigned char size_ ){

		u8 i=0;
	
		char NUM64[8];
		Usart_SendByte_(pUSARTx,'R');
	
		for(i=0;i<size_;i++){	 		
			 
				b64_To_h_(&datas[i],NUM64);
				Usart_SendArray_(pUSARTx,NUM64,8);		
			
		 }
	
		Usart_SendByte_(pUSARTx,10);  //"\n"

}



 //串口打印数据
void DisPlay_StrInt2(int val1,int val2){

    char front[30];
    sprintf(front,"val1: %d val2: %d\n",val1,val2);
		printf(front);
	
}

void DisPlay_StrFloat2(float val1,float val2){
	
    char front[30];
		sprintf(front,"val1: %f val2: %f\n",val1,val2);
		printf(front);	
	
}

void DisPlay_StrFloat4(float val1,float val2,float val3,float val4){     

    char front[50];
	  sprintf(front,"val1: %f val2: %f val3: %f val4: %f\n",val1,val2,val3,val4);
		printf(front);	
	
}


void b16_To_h_(const short *val,char hex[2]){    
	
    const char *p =(char*)(val);
    hex[0]=*((char * )p);
    hex[1]=*((char * )(p+1));
}

void b32_To_h_(const int *val,char hex[4]){

	const char *p =(char*)(val);
    hex[0]=*((char * )p);
    hex[1]=*((char * )(p+1));
		hex[2]=*((char * )(p+2));
	  hex[3]=*((char * )(p+3));
}

void b64_To_h_(const double *val,char hex[8]){

	const char *p = (char *)(val);
	char i =0;
	
	for(;i<8;i++){
	  hex[i] =*((char *)(p + i));
	}

}


void Usart_SendByte_( USART_TypeDef * pUSARTx, uint8_t ch)
{
		USART_SendData(pUSARTx,ch);		
		while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

void Usart_SendArray_(USART_TypeDef * pUSARTx,uint8_t *words,u16 length){
	
    u16 c;
	  for(c=length;c--;){	
			Usart_SendByte_(pUSARTx,*(words));
			words++;
		}
}



