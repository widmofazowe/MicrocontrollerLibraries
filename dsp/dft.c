/*
 * dft.c
 *
 *  Created on: Nov 22, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "dft.h"
#include <math.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : dft
* Description    : Compute spectrum using dft of N points.
* Input          : aSamples:a table with samples
* 				   aResults: a result table with spectrum (complex)
* 				   N: number of points
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft(CPXTYPE aSamples[], COMPLEX aResults[], unsigned int N) {
	unsigned int i, k, steps = N/2;
	CPXTYPE dc = CPX_ZERO;
	for(i = 0; i < N; ++i) {
		aResults[i] = cpx_zero();
		dc += aSamples[i];
	}
	aResults[0].re = dc/(CPXTYPE)N;
	aResults[0].im = CPX_ZERO;

	for(k = 1; k < steps; ++k) {
		for(i = 0; i < N; ++i) {
			COMPLEX x = cpx_e(aSamples[i], -M_TWOPI * (CPXTYPE) (i * k)/((CPXTYPE)(N)));
			cpx_addr(&aResults[k], &x);
		}
#if DEL_ROUND_ERR == 1
		if((int)(aResults[k].re*100000.0) == 0) {
			aResults[k].re = CPX_ZERO;
		}
		if((int)(aResults[k].im*100000.0) == 0) {
			aResults[k].im = CPX_ZERO;
		}
#endif
		cpx_mul_k(&aResults[k], 2/(CPXTYPE)N);
	}
}

/*******************************************************************************
* Function Name  : dft_both
* Description    : Compute spectrum magnitude and phase using dft of N points.
* Input          : aSamples:a table with samples
* 				   aMagnitude: a result table with spectrum magnitude
* 				   aPhase: a result table with spectrum phase
* 				   N: number of points
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft_both(CPXTYPE aSamples[], CPXTYPE aMagnitude[], CPXTYPE aPhase[], unsigned int N) {
	unsigned int i, k, steps = N/2;
	CPXTYPE real = CPX_ZERO, imag = CPX_ZERO;

	for(k = 0; k < steps; ++k) {
		real = imag = CPX_ZERO;

		for(i = 0; i < N; ++i) {
			real += aSamples[i] * cosf(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
			imag -= aSamples[i] * sinf(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
		}

#if DEL_ROUND_ERR == 1
		if((int)(real*100000.0) == 0) {
			real = CPX_ZERO;
		}
		if((int)(imag*100000.0) == 0) {
			imag = CPX_ZERO;
		}
#endif

		aMagnitude[k] = sqrtf(real*real + imag*imag)*2/N;
		aPhase[k] = atanf(imag/real)*CPX_180OVERPI;
		if(real < CPX_ZERO) {
			aPhase[k] = (imag > CPX_ZERO) ? aPhase[k] + M_PI : aPhase[k] - M_PI;
		}
	}
	aMagnitude[0] /= (CPXTYPE)2;
}

/*******************************************************************************
* Function Name  : dft_mag
* Description    : Compute spectrum magnitude using dft of N points.
* Input          : aSamples:a table with samples
* 				   aMagnitude: a result table with spectrum magnitude
* 				   N: number of points
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft_mag(CPXTYPE aSamples[], CPXTYPE aMagnitude[], unsigned int N) {
	unsigned int i, k, steps = N/2;
	CPXTYPE real = CPX_ZERO, imag = CPX_ZERO;

	for(k = 0; k < steps; ++k) {
		real = imag = CPX_ZERO;

		for(i = 0; i < N; ++i) {
			real += aSamples[i] * cosf(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
			imag -= aSamples[i] * sinf(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
		}

#if DEL_ROUND_ERR == 1
		if((int)(real*100000.0) == 0) {
			real = CPX_ZERO;
		}
		if((int)(imag*100000.0) == 0) {
			imag = CPX_ZERO;
		}
#endif
		aMagnitude[k] = sqrtf(real*real + imag*imag)*2/N;
	}
	aMagnitude[0] /= (CPXTYPE)2;
}

/*******************************************************************************
* Function Name  : dft_phase
* Description    : Compute spectrum magnitude and phase using dft of N points.
* Input          : aSamples:a table with samples
* 				   aMagnitude: a result table with spectrum magnitude
* 				   aPhase: a result table with spectrum phase
* 				   N: number of points
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft_phase(CPXTYPE aSamples[], CPXTYPE aPhase[], unsigned int N) {
	unsigned int i, k, steps = N/2;
	CPXTYPE real = CPX_ZERO, imag = CPX_ZERO;

	for(k = 0; k < steps; ++k) {
		real = imag = CPX_ZERO;

		for(i = 0; i < N; ++i) {
			real += aSamples[i] * cosf(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
			imag -= aSamples[i] * sinf(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
		}

#if DEL_ROUND_ERR == 1
		if((int)(real*100000.0) == 0) {
			real = CPX_ZERO;
		}
		if((int)(imag*100000.0) == 0) {
			imag = CPX_ZERO;
		}
#endif
		aPhase[k] = atanf(imag/real)*CPX_180OVERPI;
		if(real < CPX_ZERO) {
			aPhase[k] = (imag > CPX_ZERO) ? aPhase[k] + M_PI : aPhase[k] - M_PI;
		}
	}
}

