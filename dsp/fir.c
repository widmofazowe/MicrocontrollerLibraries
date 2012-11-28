/*
 * fir.c
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "fir.h"
#include <malloc.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
volatile FIRTYPE *fir_coeff;
volatile unsigned *fir_coeff_n;
volatile FIRTYPE *fir_samples_history;
volatile unsigned *fir_oldest_sample;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : fir_init
* Description    : Fill table with filter coefficients and samples with zero.
* Input          : coeff: table with filter coeff,
* 				   n: number of coeff.
* Output         : None.
* Return         : None.
*******************************************************************************/
void fir_init(FIRTYPE *coeff, unsigned n) {
	unsigned i;
	fir_coeff = (FIRTYPE*) malloc(n*sizeof(FIRTYPE));
	fir_coeff_n = (unsigned*) malloc(sizeof(unsigned));
	fir_samples_history = (FIRTYPE*) calloc(n, sizeof(FIRTYPE));
	fir_oldest_sample = (unsigned*) malloc(sizeof(unsigned));
	*fir_oldest_sample = 0;
	*fir_coeff_n = n;
	for(i = 0; i < n; i++) {
		*(fir_coeff+i) = *coeff++;
	}
}

/*******************************************************************************
* Function Name  : fir_free
* Description    : Free memory.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void fir_free() {
	free((void*) fir_coeff);
	free((void*) fir_coeff_n);
	free((void*) fir_oldest_sample);
	free((void*) fir_samples_history);
}

/*******************************************************************************
* Function Name  : fit_clear_input
* Description    : Clear history of input samples.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void fit_clear_input() {
	unsigned i, N;
	N = *fir_coeff_n;
	for(i = 0; i < N; i++) {
		*(fir_samples_history+i) = 0;
	}
}

/*******************************************************************************
* Function Name  : fir
* Description    : Compute output value of sample.
* Input          : sample: input sample.
* Output         : None.
* Return         : Output sample.
*******************************************************************************/
FIRTYPE fir(FIRTYPE sample) {
	unsigned i, N;
	*(fir_samples_history+(*fir_oldest_sample)) = sample;
	N = *fir_coeff_n;
	sample = 0;
	for (i = 0; i < N; i++) {
	    sample += *(fir_coeff+i) * (*(fir_samples_history+(((*fir_oldest_sample) + i)%N)));
	}

	*fir_oldest_sample = (*fir_oldest_sample + 1)%N;

	return sample;
}
