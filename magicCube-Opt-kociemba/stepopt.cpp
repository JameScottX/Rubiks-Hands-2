#include "stepopt.h"

StepOpt::StepOpt()
{
}


int StepOpt::Opt_Func(std::string solve,short num_){

    short len_ = solve.size();

    int count_num_ =0;
    for (short j = 0; j <= num_;j++) { //0为右手 1 为左手

        short x =0;
        count_=0;
        L_IS_OK = 0;
        R_IS_OK = 0;
        memcpy(local_now2next, local_Init,6);


        for (short i = 0; i < len_; i += 2) {

            short t_ = i + 1;
            char c;
            for (c = 0; c < 6 && FAILURE == sure_word(solve[i], c); c++);
            if (c == 2 || c == 4) {

                if (!((j>>x) & 1)) {
                    opt_tar = R_HAND_FUC;
                    //youhua_ = L_HAND_FUC;
                }
                else {
                    opt_tar = L_HAND_FUC;
                    //youhua_ = R_HAND_FUC;
                }
                x++;
            }
            local_way = solve[t_];
            select_dir_refresh();
        }

        memcpy(opt_re[count_num_], all_func,count_);
        result[count_num_] = count_;
        count_num_++;
    }

    return count_num_;
}

Opt StepOpt::Find(int all){
    Opt opt_;
    short re_id[200],id_c=0;
    short rem_ = 800;
//找到最小值
    for (int i = 0; i < all; i++) {
        if (rem_ > result[i]) {
                rem_ = result[i];
            }
    }

//存储最小值id
    for (int i = 0; i < all; i++) {
            if (rem_ == result[i]) {
                re_id[id_c] = i; id_c++;
            }
     }

qDebug()<<id_c;

//依据气缸动作 找到最优
    short best_ =500,best_id=0;
    for (int i = 0; i < id_c; i++){
            short hand_oc_num = 0;
            short t_i= re_id[i];
            for (short g = 0; g < result[t_i]; g++) { //执行部署循环

                if( (7<=opt_re[re_id[i]][g]) && (opt_re[re_id[i]][g]<=10)){
                    hand_oc_num++;
                }

                //printf_s("%d,", opt_re[re_id[i]][g]);
            }

            if(best_ > hand_oc_num){
                best_ = hand_oc_num;
                best_id = re_id[i];
                }
        }

    QByteArray array;
    array.resize(result[best_id]);
    memcpy(array.data(), opt_re[best_id], result[best_id]);

    opt_.array = array;
    opt_.Original = result[0];
    opt_.after_opt = result[best_id];

    return opt_;
}


char StepOpt::sure_word(char get, char count) {

    if (get == local_now2next[count]) {

        local_num = count;
        return SUCCESS;

    }
    else {
        return FAILURE;
    }
}


void StepOpt::R_way2_Rotate(void) {

    if (L_IS_OK%2!=0) {
        all_func[count_] = L_O; count_++;
        all_func[count_] = L_2LOC; count_++; L_IS_OK = 0;
        all_func[count_] = L_C; count_++;
    }

    switch (local_way) {
    case'1':
        all_func[count_] = R_S_90; count_++; R_IS_OK++; break;
    case'2':
        all_func[count_] = R_180; count_++; break;
    case'3':
        all_func[count_] = R_N_90; count_++; R_IS_OK++; break;
    }
}


void StepOpt::L_way2_Rotate(void) {

    if (R_IS_OK%2!=0) {
        all_func[count_] = R_O; count_++;
        all_func[count_] = R_2LOC; count_++; R_IS_OK = 0;
        all_func[count_] = R_C; count_++;
    }

    switch (local_way) {
    case'1':
        all_func[count_] = L_S_90; count_++; L_IS_OK++; break;
    case'2':
        all_func[count_] = L_180; count_++; break;
    case'3':
        all_func[count_] = L_N_90; count_++; L_IS_OK++; break;
    }

}



void StepOpt::select_dir_refresh(void) {

    switch (local_num) {

    case 1:

        all_func[count_] = R_O; count_ ++;
        if (R_IS_OK%2!=0) {
            all_func[count_] = R_2LOC; count_++; R_IS_OK = 0;
        }
        all_func[count_] = L_180_2; count_++;
        all_func[count_] = R_C; count_++;
        R_way2_Rotate();

        EXCHANGE(local_now2next[1],local_now2next[3]);
        EXCHANGE(local_now2next[2], local_now2next[4]);
        break;

    case 2: //优化目标

        if (opt_tar == R_HAND_FUC) {//右手转面
            all_func[count_] = R_O; count_++;
            if (R_IS_OK % 2 != 0) {
                all_func[count_] = R_2LOC; count_++; R_IS_OK = 0;
            }
            all_func[count_] = L_S_90_2; count_++; L_IS_OK++;
            all_func[count_] = R_C; count_++;
            R_way2_Rotate();

            EXCHANGE(local_now2next[4], local_now2next[3]);
            EXCHANGE(local_now2next[3], local_now2next[2]);
            EXCHANGE(local_now2next[2], local_now2next[1]);

        }
        else {//左手转面

            all_func[count_] = L_O; count_++;
            if (L_IS_OK % 2 != 0) {
                all_func[count_] = L_2LOC; count_++; L_IS_OK = 0;
            }
            all_func[count_] = R_N_90_2; count_++; R_IS_OK++;
            all_func[count_] = L_C; count_++;
            L_way2_Rotate();


            EXCHANGE(local_now2next[2], local_now2next[5]);
            EXCHANGE(local_now2next[0], local_now2next[5]);
            EXCHANGE(local_now2next[4], local_now2next[5]);

        }

        break;

    case 3:
        R_way2_Rotate();
        break;

    case 4: //优化目标

        if (opt_tar == R_HAND_FUC) {
            all_func[count_] = R_O; count_++;
            if (R_IS_OK % 2 != 0) {
                all_func[count_] = R_2LOC; count_++; R_IS_OK = 0;
            }
            all_func[count_] = L_N_90_2; count_++; L_IS_OK++;
            all_func[count_] = R_C; count_++;
            R_way2_Rotate();

            EXCHANGE(local_now2next[1], local_now2next[2]);
            EXCHANGE(local_now2next[2], local_now2next[3]);
            EXCHANGE(local_now2next[3], local_now2next[4]);


        }
        else {

            all_func[count_] = L_O; count_++;
            if (L_IS_OK % 2 != 0) {
                all_func[count_] = L_2LOC; count_++; L_IS_OK = 0;
            }
            all_func[count_] = R_S_90_2; count_++; R_IS_OK++;
            all_func[count_] = L_C; count_++;
            L_way2_Rotate();


            EXCHANGE(local_now2next[2], local_now2next[5]);
            EXCHANGE(local_now2next[0], local_now2next[4]);
            EXCHANGE(local_now2next[2], local_now2next[4]);

        }


        break;

    case 0:
        L_way2_Rotate();

        break;
    case 5:
        all_func[count_] = L_O; count_++;
        if (L_IS_OK % 2 != 0) {
            all_func[count_] = L_2LOC; count_++; L_IS_OK = 0;
        }
        all_func[count_] = R_180_2; count_++;
        all_func[count_] = L_C; count_++;
        L_way2_Rotate();
        EXCHANGE(local_now2next[2],  local_now2next[4]);
        EXCHANGE(local_now2next[0],  local_now2next[5]);

        break;
    default:
        break;
    }

}


