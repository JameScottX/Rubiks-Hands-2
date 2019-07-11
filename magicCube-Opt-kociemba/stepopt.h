#ifndef STEPOPT_H
#define STEPOPT_H
#include <iostream>
#include <string>
#include <QByteArray >
#include <QDebug>
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

#define R_HAND_FUC 0
#define L_HAND_FUC 1

#define EXCHANGE(a,b)   {a^=b;b^=a;a^=b;}      //交换算法
#define SUCCESS  0X01
#define FAILURE  0X02

typedef struct{

    QByteArray array;
    short Original;
    short after_opt;

}Opt;

class StepOpt
{
public:
    StepOpt();
    int  Opt_Func(std::string solve,short num_);
    Opt Find(int count_);

private:
    char local_Init[6] = { 'F','R','D','L','U','B'};
    char local_now2next[6];
    char local_num = 0;
    char local_way = 0;

    char all_func[1000];
    int count_ = 0;

    char opt_re[1000][500];  //优化结果记录
    short result[1000];      //步长记录

    char  opt_tar = R_HAND_FUC; //初始默认右手优化

    short L_IS_OK = 0;   //手归位标识
    short R_IS_OK = 0;
private:
     char sure_word(char get, char count);
     void R_way2_Rotate(void);
     void L_way2_Rotate(void);
     void select_dir_refresh(void) ;
};

#endif // STEPOPT_H
