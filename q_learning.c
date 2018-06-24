/*****************************************************************************/
/* 002 qlearn */
/* reinforcement learning 強化学習の例 */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define GENMAX 1000
#define NODE_NO  15
#define ALPHA   0.1
#define GAMMA   0.9
#define EPSILON 0.3
#define SEED  32767

/*****************************************************************************/
/* proto type definition */
/*****************************************************************************/
int rand100();
int rand01();
double rand1();

void printqvalue(int qvalue[NODE_NO]);
int selecta(int s, int qvalue[NODE_NO]);
int updateq(int s, int qvalue[NODE_NO]);

/*****************************************************************************/
/* main function */
/*****************************************************************************/
int main() {
    int i;
    int s; /* status */
    int t; /* time   */
    int qvalue[NODE_NO];

    srand(SEED);

    /* initialize Q value */
    for (i=0; i<NODE_NO; i++) {
        qvalue[i] = rand100();
    }
    printqvalue(qvalue);

    /* mein section of learning */
    for (i=0; i<NODE_NO; i++) {
        s = 0;
        for (t=0; t<3; t++) {
            /* select action */
            s = selecta(s, qvalue);

            /* update Q value */
            qvalue[s] = updateq(s, qvalue);
        }
        printqvalue(qvalue);
    }
    return 0;
}

/*****************************************************************************/
/* function : updateq() */
/*****************************************************************************/
int updateq(int s, int qvalue[]) {

}

/*****************************************************************************/
/* function : selecta() */
/*****************************************************************************/
int selecta(int s, int qvalue[]) {

}

/*****************************************************************************/
/* function : printqvalue() */
/*****************************************************************************/
void printqvalue(int qvalue[NODE_NO]) {

}

/*****************************************************************************/
/* function : rand100() */
/*****************************************************************************/
int rand100(void) {

}

/*****************************************************************************/
/* function : rand01() */
/*****************************************************************************/
int rand01(void) {

}

/*****************************************************************************/
/* function : rand1() */
/*****************************************************************************/
double rand1(void) {

}
