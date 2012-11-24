/*
 * fft.c
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "fft.h"
#include <malloc.h>
#include <math.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//cos(2*pi*x) = cos_table(x)
//sin(2*pi*x) = cos_table((x+N/4)%N)
volatile CPXTYPE *cos_table;
volatile unsigned *fft_index_table;
volatile COMPLEX *fft_w;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : _fft_sample_index
* Description    : Compute the index of a sample in 2-point dft.
* Input          : n: index of table,
* 				   N: number of samples.
* Output         : None.
* Return         : Index of shuffled sample.
*******************************************************************************/
int _fft_sample_index(int n, int N){
	int number = 0 ;
    int i = 0;
	for(i = N/2; i > 1; i /= 2) {
		number += (n&1) * i;
		n /= 2;
	}
	return number + n;
}

/*******************************************************************************
* Function Name  : fft_init
* Description    : Initialize tables used to calculate fft.
* Input          : N: number of points of fft.
* Output         : None.
* Return         : None.
*******************************************************************************/
void fft_init(int N) {
    int i;
    cos_table = (CPXTYPE*) malloc(N*sizeof(CPXTYPE));
    fft_index_table = (unsigned*) malloc(N*sizeof(unsigned));
    fft_w = (COMPLEX*) malloc(N*sizeof(COMPLEX));
    for(i = 0; i < N; ++i) {
        cos_table[i] = (CPXTYPE) cos(M_TWOPI*(CPXTYPE)(i)/(CPXTYPE)N);
        fft_index_table[i] = _fft_sample_index(i, N);
    }

    for(i = 0; i < N/2; ++i) {
        fft_w[i].re = cos_table[i];
        fft_w[i].im = cos_table[i+(N/4)%N];
    }

}

/*******************************************************************************
* Function Name  : fft_free
* Description    : Free memory of tables used to calculate fft.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void fft_free() {
    free((void*) cos_table);
    free((void*) fft_index_table);
    free((void*) fft_w);
}



/*******************************************************************************
* Function Name  : fft
* Description    : Compute fft.
* Input          : samples: index of table,
* 				   N: number of samples.
* Output         : None.
* Return         : Index of shuffled sample.
*******************************************************************************/
void fft(CPXTYPE samples[], COMPLEX spectrum[], int N) {
	int i = 0, halfstep, k;
	int step = 0;
	COMPLEX a, b;
    int ai, bi;

	for(i = 0; i < N; i += 2) {
		spectrum[i].re = samples[fft_index_table[i]] + samples[fft_index_table[i+1]];
		spectrum[i+1].re = samples[fft_index_table[i]] - samples[fft_index_table[i+1]];
		spectrum[i].im = spectrum[i+1].im = CPX_ZERO;
	}


	for(step = 4; step <= N; step *= 2) {
		halfstep = step/2;
		for(i = 0; i < N; i += step) {
			for(k = 0; k < halfstep; ++k) {
				ai = k + i;
				bi = ai + halfstep;
				a = spectrum[ai];
				b = cpx_mul(&spectrum[bi], &fft_w[k*N/step]);
				spectrum[ai] = cpx_add(&a, &b);
				b.re = -b.re;
				b.im = -b.im;
				spectrum[bi] = cpx_add(&a, &b);
			}
		}
	}
	halfstep = N/2;
	cpx_div_k(&spectrum[0], (CPXTYPE)N);
	for(i = 1; i < halfstep; ++i) {
		cpx_div_k(&spectrum[i], (CPXTYPE)halfstep);
	}

}
