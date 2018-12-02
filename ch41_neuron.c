/*****************************************************************************/
/* 4-1 neuron */
/* 単体の人工ニューロンを表現する */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*---------------------------------------------------------------------------*/
/* declare constant value */
/*---------------------------------------------------------------------------*/
#define INPUTNO 2
#define MAXINPUTNO 100

/*---------------------------------------------------------------------------*/
/* declare proto type of function */
/*---------------------------------------------------------------------------*/
/*
int    getdata(double e[][INPUTNO]);
void   init_weight(double weight[INPUTNO + 1]);
double func(double u);
double forward(double weight[INPUTNO + 1], double e[INPUTNO]);
*/
int    getdata(double [][INPUTNO]);
void   init_weight(double []);
double activation_func(double);
double forward(double [], double []);

/*---------------------------------------------------------------------------*/
/* sub functions */
/*---------------------------------------------------------------------------*/
/* getdata() */
//int getdata(double e[][INPUTNO]) {
int getdata(double e[][INPUTNO]) {
    int num_of_entry = 0;
    int i = 0;
    int num = 0;

    while (scanf("%lf", &e[num_of_entry][i]) != EOF ) {
        i++;
        if ( i >= INPUTNO ) {
            i = 0;
            num_of_entry++;
        }
    }
    return num_of_entry;
}

/* init_weight() */
void init_weight(double weight[INPUTNO + 1]) {
    /* しきい値 1.5　AND論理素子 */ 
    /* しきい値 0.5　OR論理素子 */ 

    weight[0] = 1;    /* 1st weight element */
    weight[1] = 1;    /* 2nd weight element */
    weight[2] = 0.5;  /* しきい値 threshold  */
}

/* activation function 伝達関数=活性化関数 */
double activation_func(double u) {
    if ( u >= 0 ) {
        return 1.0;
    }
    else {
        return 0.0;
    }
}

/* forward() */
double forward(double weight[INPUTNO + 1], double inputdata[INPUTNO]) {
    int i = 0;
    double u = 0;
    double output = 0;

    for (i=0; i<INPUTNO; i++) {
        u += inputdata[i] * weight[i]; 
        printf("[in forward()] input(%lf) * weight(%lf) = (%lf)\n", inputdata[i], weight[i], u);
    }
    /* しきい値を引く */
    u -= weight[i];

    /* outputの計算を伝達関数(活性化関数)で実行 */
    output = activation_func(u);

    printf("[in forward()] u of result = (%lf) output = (%lf)\n", u, output);
    return output;
}

/*---------------------------------------------------------------------------*/
/* main functoin */
/*---------------------------------------------------------------------------*/
int main(int argc, char *argv[]){
    int i = 0;
    int j = 0;
    int num_of_entry = 0;
    double weight[INPUTNO + 1];   /* 重みとしきい値 */
    double entry[MAXINPUTNO][INPUTNO];
    double output;

    /* 入力データの読み込み */
    num_of_entry = getdata(entry);
    printf("number of entry = %d\n", num_of_entry);

    /* initialize weight value */
    init_weight(weight);

    /* 計算本体 */
    for (i=0; i<num_of_entry; i++) {
        for (j=0; j<INPUTNO; j++) {
            printf(" >>e[%d][%d]=<%lf> \n", i, j, entry[i][j]);
        }
        /* 実行 */
        output = forward(weight, entry[i]);
        printf(" output = %lf \n", output);
    }

    return 0;

}