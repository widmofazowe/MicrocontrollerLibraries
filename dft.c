/*
 * dft.c
 *
 *  Created on: Nov 22, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "dft.h"
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
void dft(CPXTYPE aSamples[], COMPLEX aResults[], short unsigned int N) {
	short unsigned int i, k, steps = N/2;
	CPXTYPE dc = CPX_ZERO;
	for(i = 0; i < N; ++i) {
		aResults[i] = cpx_zero();
		dc += aSamples[i];
	}
	aResults[0].re = dc;
	aResults[0].im = CPX_ZERO;

	for(k = 1; k < steps; ++k) {
		for(i = 0; i < N; ++i) {
			COMPLEX x = cpx_e(aSamples[i], M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
			aResults[k] = cpx_add(&aResults[k], &x);
		}
		cpx_div_k(&aResults[k], N);
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
void dft_both(CPXTYPE aSamples[], CPXTYPE aMagnitude[], CPXTYPE aPhase[], short unsigned int N) {
	short unsigned int i, k, steps = N/2;
	CPXTYPE real = CPX_ZERO, imag = CPX_ZERO;

	for(k = 0; k < steps; ++k) {
		real = imag = CPX_ZERO;

		for(i = 0; i < N; ++i) {
			real += aSamples[i] * cos(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
			imag -= aSamples[i] * sin(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
		}
		real /= N;
		imag /= N;
		aMagnitude[k] = sqrt(real*real + imag*imag);
		aPhase[k] = atan(imag/real)*CPX_180OVERPI;
		if(real < CPX_ZERO) {
			aPhase[k] = (imag > CPX_ZERO) ? aPhase[k] + M_PI : aPhase[k] - M_PI;
		}
	}
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
void dft_mag(CPXTYPE aSamples[], CPXTYPE aMagnitude[], short unsigned int N){
	short unsigned int i, k, steps = N/2;
	CPXTYPE real = CPX_ZERO, imag = CPX_ZERO;

	for(k = 0; k < steps; ++k) {
		real = imag = CPX_ZERO;

		for(i = 0; i < N; ++i) {
			real += aSamples[i] * cos(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
			imag -= aSamples[i] * sin(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
		}
		real /= N;
		imag /= N;
		aMagnitude[k] = sqrt(real*real + imag*imag);
	}
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
void dft_phase(CPXTYPE aSamples[], CPXTYPE aPhase[], short unsigned int N) {
	short unsigned int i, k, steps = N/2;
	CPXTYPE real = CPX_ZERO, imag = CPX_ZERO;

	for(k = 0; k < steps; ++k) {
		real = imag = CPX_ZERO;

		for(i = 0; i < N; ++i) {
			real += aSamples[i] * cos(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
			imag -= aSamples[i] * sin(M_TWOPI * (CPXTYPE) (i * k)/(CPXTYPE)(N));
		}
		real /= N;
		imag /= N;

		aPhase[k] = atan(imag/real)*CPX_180OVERPI;
		if(real < CPX_ZERO) {
			aPhase[k] = (imag > CPX_ZERO) ? aPhase[k] + M_PI : aPhase[k] - M_PI;
		}
	}
}

