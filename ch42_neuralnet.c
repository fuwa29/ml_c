/*****************************************************************************/
/* 4-2 neural network */
/* 3層の簡単なニューラルネットワークで、XOR（EOR）排他的論理和を実装する */
/* 入力層 2つ */
/* 中間層 2つ */
/* 出力層 1つ */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*---------------------------------------------------------------------------*/
/* declare constant value */
/*---------------------------------------------------------------------------*/
#define INPUTNO 2       /* input number */
#define HIDDENNO 2      /* middle layer */
#define MAXINPUTNO 100

/*---------------------------------------------------------------------------*/
/* declare proto type of function */
/*---------------------------------------------------------------------------*/
int    getdata(double [][INPUTNO]);
void   init_weight_hidden(double [][INPUTNO + 1]);  /* middle layer */
void   init_weight_output(double [HIDDENNO + 1]);  /* output layer */

double activation_func(double);
double forward(double wh[][INPUTNO+1],
               double wo[],
               double hi[],
               double e[]
);

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
void init_weight_hidden(double weight_hidden[][INPUTNO + 1]) {
    weight_hidden[0][0] = -2;   /* 1st weight element */
    weight_hidden[0][1] = 3;    /* 2nd weight element */
    weight_hidden[0][2] = -1;   /* しきい値 threshold  */
    weight_hidden[1][0] = -2;   /* 1st weight element */
    weight_hidden[1][1] = 1;    /* 2nd weight element */
    weight_hidden[1][2] = 0.5;  /* しきい値 threshold  */
}

/* init_weight() */
void init_weight_output(double weight_output[HIDDENNO + 1]) {
    weight_output[0] = -60;    /* 1st weight element */
    weight_output[1] = 94;    /* 2nd weight element */
    weight_output[2] = -1;  /* しきい値 threshold  */
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
double forward(double weight_hidden[][INPUTNO + 1],
               double weight_output[HIDDENNO + 1],
               double hidden_output[],
               double inputdata[INPUTNO]) {
    int i = 0;
    int j = 0;
    double u = 0;
    double output = 0;
    double last_output = 0;

    /* 中間層のアウトプット計算 */
    for (i=0; i<HIDDENNO; i++) {
        u = 0;
        for(j=0; j<INPUTNO; j++) {
            u += inputdata[j] * weight_hidden[i][j];
        }
        /* しきい値を引く */
        u -= weight_hidden[i][j];

        /* outputの計算を伝達関数(活性化関数)で実行 */
        hidden_output[i] = activation_func(u);
    }

    /* 中間層のアウトプットをインプットにして、出力層の計算 */
    for (i=0; i<HIDDENNO; i++) {
        output += hidden_output[i] * weight_output[i]; 
        printf("[in forward()] hidden_output(%lf) * weight_output(%lf) = (%lf)\n", hidden_output[i], weight_output[i], u);
    }
    /* しきい値を引く */
    output -= weight_output[i];

    /* outputの計算を伝達関数(活性化関数)で実行 */
    last_output = activation_func(output);

    printf("[in forward()] u of result = (%lf) output = (%lf)\n", output, last_output);
    return last_output;
}

/*---------------------------------------------------------------------------*/
/* main functoin */
/*---------------------------------------------------------------------------*/
int main(int argc, char *argv[]){
    int i = 0;
    int j = 0;
    int num_of_entry = 0;
    double weight_hidden[HIDDENNO][INPUTNO + 1];   /* middle 重みとしきい値 */
    double weight_output[HIDDENNO + 1];            /* output 重みとしきい値 */
    double entry[MAXINPUTNO][INPUTNO];             /* data set */
    double hidden_output[HIDDENNO + 1];            /* output of hidden layer */
    double output;

    /* initialize weight value */
    init_weight_hidden(weight_hidden);
    init_weight_hidden(weight_output);

    /* 入力データの読み込み */
    num_of_entry = getdata(entry);
    printf("number of entry = %d\n", num_of_entry);

    /* 計算本体 */
    for (i=0; i<num_of_entry; i++) {
        for (j=0; j<INPUTNO; j++) {
            printf(" >>e[%d][%d]=<%lf> \n", i, j, entry[i][j]);
        }
        /* 実行 */
        output = forward(weight_hidden, weight_output, hidden_output, entry[i]);
        printf(" output = %lf \n", output);
    }

    return 0;

}