/* Minseok_Yoon_202170116 */

/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N]) 
{
	int i, j, k, l, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8;
    if (M==32 && N==32) {
    	for(k=0; k<N; k+=8){
        	for(i=0; i<M; i+=8){
            	for(j=0; j<8; j++){
                	tmp1 = A[k+j][i];
                	tmp2 = A[k+j][i+1];
                	tmp3 = A[k+j][i+2];
                	tmp4 = A[k+j][i+3];
                	tmp5 = A[k+j][i+4];
                	tmp6 = A[k+j][i+5];
                	tmp7 = A[k+j][i+6];
   		            tmp8 = A[k+j][i+7];

    	            B[i][k+j] = tmp1;
  	              	B[i+1][k+j] = tmp2;
            	    B[i+2][k+j] = tmp3;
        	        B[i+3][k+j] = tmp4;
    	            B[i+4][k+j] = tmp5;
	                B[i+5][k+j] = tmp6;
                	B[i+6][k+j] = tmp7;
            	    B[i+7][k+j] = tmp8;
        	    }
    	    }
	    }
    } else if (M==64 && N==64) {
        for (i=0; i<N; i+=8) {
            for (j=0; j<M; j+=8) {
                for (k=i; k<i+4; k++) {
                    tmp1 = A[k][j];
                    tmp2 = A[k][j+1];
                    tmp3 = A[k][j+2];
                    tmp4 = A[k][j+3];
                    tmp5 = A[k][j+4];
                    tmp6 = A[k][j+5];
                    tmp7 = A[k][j+6];
                    tmp8 = A[k][j+7];

                    B[j][k] = tmp1;
                    B[j+1][k] = tmp2;
                    B[j+2][k] = tmp3;
                    B[j+3][k] = tmp4;
                    B[j][k+4] = tmp5;
                    B[j+1][k+4] = tmp6;
                    B[j+2][k+4] = tmp7;
                    B[j+3][k+4] = tmp8;
                }

                for (k=j; k<j+4; k++) {
                    tmp5 = B[k][i+4];
                    tmp6 = B[k][i+5];
                    tmp7 = B[k][i+6];
                    tmp8 = B[k][i+7];

                    B[k][i+4] = A[i+4][k];
                    B[k][i+5] = A[i+5][k];
                    B[k][i+6] = A[i+6][k];
                    B[k][i+7] = A[i+7][k];

                    B[k+4][i] = tmp5;
                    B[k+4][i+1] = tmp6;
                    B[k+4][i+2] = tmp7;
                    B[k+4][i+3] = tmp8;

                    B[k+4][i+4] = A[i+4][k+4];
                    B[k+4][i+5] = A[i+5][k+4];
                    B[k+4][i+6] = A[i+6][k+4];
                    B[k+4][i+7] = A[i+7][k+4];
                }
            }
        }
    } else if (M==61 && N==67) {
        tmp1 = 16;	// block_size
        for (i=0; i<N; i+=tmp1) {
            for (j=0; j<M; j+=tmp1) {
                for (k=i; k<i+tmp1 && k<N; k++) {
                    for (l=j; l<j+tmp1 && l<M; l++) {
                        B[l][k] = A[k][l];
                    }
                }
            }
        }
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

