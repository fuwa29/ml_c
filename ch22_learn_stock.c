/*****************************************************************************/
/* 001 learn stock */
/* 単純な機能的学習の例題プログラム */
/* 100個の学習データを読み込んで、適合する10桁の2進数パターンを答える */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define NG 0

#define SETSIZE 100    /* 学習データセットの大きさ */
#define CNO 10         /* 学習データの桁数 */
#define GENMAX 50000   /* 解候補 生成回数 */
#define SEED 32767     /* 乱数のシード */

/*****************************************************************************/
/* proto type definition */
/*****************************************************************************/
void read_data(int data[SETSIZE][CNO], int teacher[SETSIZE]);
void print_data(int data[SETSIZE][CNO], int teacher[SETSIZE]);
int rand012();
int calc_score(int data[SETSIZE][CNO], int teacher[SETSIZE], int answer[CNO]);

/*****************************************************************************/
/* main function */
/*****************************************************************************/
int main(){
    int i, j;
    int score = 0;
    int answer[CNO];
    int data[SETSIZE][CNO];
    int teacher[SETSIZE];
    int best_score = 0;
    int best_answer[CNO];

    /* 乱数の初期化 */
    srand(SEED);

    /* 学習データセットの読み込み from stdin */
    read_data(data, teacher);
    print_data(data, teacher);

    /* START learning */
    printf("\n");
    printf("**************** START learning ********************\n");
    for (i=0; i< GENMAX; i++) {
        /* 解候補生成 */
//        printf("answer[%2d] ", i);
        for (j=0; j < CNO; j++) {
            answer[j] = rand012();
//            printf("%d ",answer[j]);
        }
//        printf("\n");

        /* check */
        score = calc_score(data, teacher, answer);

        /* update best score */
//        printf("[genno = %3d]:score = %2d  best_score = %2d \n", i, score, best_score);
        if (score > best_score) {
            for (j=0; j < CNO; j++) {
                best_answer[j] = answer[j];
            }
            best_score = score;

            printf("No %5d:", i);
            for (j=0; j < CNO; j++) {
                printf("%d ", best_answer[j]);
            }
            printf(":score=%d\n", best_score);
        }
    }

    /* output best score */
    printf("\n");
    printf("BEST SCORE\n");
    for (j=0; j < CNO; j++) {
        printf("%ld ", best_answer[j]);
    }
    printf(":score=%d\n", best_score);

    return 0;
}

/*****************************************************************************/
/* function cals_score() */
/* 解候補パターンのスコア（0～SETSIZE）の計算 */
/*****************************************************************************/
int calc_score(int data[SETSIZE][CNO], int teacher[SETSIZE], int answer[CNO]) {
    int score = 0;
    int point = 0;
    int i, j;

    for (i=0; i < SETSIZE; i++) {
        /* 一致度計算 */
        point = 0;
        for (j=0; j < CNO; j++) {
            if (answer[j] == 2) {
                point++;    /* wild card */
            } else if (answer[j] == data[i][j]) {
                point++;    /* 一致 */
            } else {
                ;
            }
        }

        if ( (point == CNO) && (teacher[i] == 1) ){
            score++;
        } else if ( (point != CNO) && (teacher[i] == 0) ) {
            score++;
        }
    }
    return score;
}
/*****************************************************************************/
/* function read_data() */
/* 学習データセットの読み込み */
/*****************************************************************************/
void read_data(int data[SETSIZE][CNO], int teacher[SETSIZE]) {
    int i, j;

    for (i=0; i < SETSIZE; i++) {
        for (j=0; j < CNO; j++) {
            scanf("%d", &data[i][j]);
        }
        scanf("%d", &teacher[i]);
    }
}
/*****************************************************************************/
/* function print_data() */
/* 読み込んだ学習データセットを出力 */
/*****************************************************************************/
void print_data(int data[SETSIZE][CNO], int teacher[SETSIZE]) {
    int i, j;

    for (i=0; i < SETSIZE; i++) {
        printf("No[%2d] ", i);
        for (j=0; j < CNO; j++) {
            printf("%d ", data[i][j]);
        }
        printf(" --> teacher[%2d]=%d\n", i, teacher[i]);
    }
    printf("\n");
}

/*****************************************************************************/
/* function rand012() */
/* return random number 0 or 1 or 2  */
/*****************************************************************************/
int rand012() {
    int rnd;


    /* 乱数の最大値を除く */
    while ( (rnd = rand()) == RAND_MAX);

    /* 乱数の計算 */
    return (double)rnd / RAND_MAX * 3;

}
