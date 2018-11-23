/*****************************************************************************/
/* 001 learn stock */
/* 和。二乗和を求める */
/* Ctrl+Z で終了 */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256    /* input buffer size */

/*****************************************************************************/
/* main function */
/*****************************************************************************/
int main(){
	char linebuf[BUFSIZE];  /* input buffer */
	double data;            /* input data */
	double sum = 0.0;       /* 和 */
	double sum_sq = 0.0;    /* 二乗和 */

	while (fgets(linebuf, BUFSIZE, stdin) != NULL) {
		/* 行の読み取りを繰り返す */
		if (sscanf(linebuf, "%lf", &data) != 0) {
			sum =+ data;
			sum_sq =+ data * data;
			printf("%lf\t%lf\n", sum, sum_sq);
		}
	}
}
