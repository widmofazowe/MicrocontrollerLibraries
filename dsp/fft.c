/*
 * fft.c
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "fft.h"
#include <malloc.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
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
void fft_init(unsigned N) {
    unsigned i;
    fft_index_table = (unsigned*) malloc(N*sizeof(unsigned));
    fft_w = (COMPLEX*) malloc(N*sizeof(COMPLEX));
    for(i = 0; i < N; ++i) {
        fft_index_table[i] = _fft_sample_index(i, N);
    }

    for(i = 0; i < N/2; ++i) {
        fft_w[i].re = util_cos[i];
        fft_w[i].im = util_cos[i+(N/4)%N];
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
    free((void*) fft_index_table);
    free((void*) fft_w);
}



/*******************************************************************************
* Function Name  : fft
* Description    : Compute fft.
* Input          : samples: index of table,
* 				   N: number of samples.
* Output         : None.
* Return         : None.
*******************************************************************************/
void fft(UTILTYPE samples[], COMPLEX spectrum[], int N) {
	int i = 0, halfstep, k;
	int step = 0;
	COMPLEX a, b;
    int ai, bi;

	for(i = 0; i < N; i += 2) {
#if FFT_USEPRECALCULATION == 1
		spectrum[i].re = samples[fft_index_table[i]] + samples[fft_index_table[i+1]];
		spectrum[i+1].re = samples[fft_index_table[i]] - samples[fft_index_table[i+1]];
		spectrum[i].im = spectrum[i+1].im = UTIL_ZERO;
#else
		spectrum[i].re = samples[_fft_sample_index(i, N)] + samples[_fft_sample_index(i+1, N)];
		spectrum[i+1].re = samples[_fft_sample_index(i, N)] - samples[_fft_sample_index(i+1, N)];
		spectrum[i].im = spectrum[i+1].im = UTIL_ZERO;
#endif
	}


	for(step = 4; step <= N; step *= 2) {
		halfstep = step/2;
		for(i = 0; i < N; i += step) {
			for(k = 0; k < halfstep; ++k) {
#if FFT_USEPRECALCULATION == 0
				COMPLEX x;
#endif
				ai = k + i;
				bi = ai + halfstep;
				a = spectrum[ai];
#if FFT_USEPRECALCULATION == 1
				b = cpx_mul(&spectrum[bi], (COMPLEX*) &fft_w[k*N/step]);
#else
				x = cpx_e(1, k*N/step);
				b = cpx_mul(&spectrum[bi], &x);
#endif
				spectrum[ai] = cpx_add(&a, &b);
				b.re = -b.re;
				b.im = -b.im;
				spectrum[bi] = cpx_add(&a, &b);
			}
		}
	}
	halfstep = N/2;
	cpx_div_k(&spectrum[0], (UTILTYPE)N);
	for(i = 1; i < halfstep; ++i) {
		cpx_div_k(&spectrum[i], (UTILTYPE)halfstep);
	}

}
