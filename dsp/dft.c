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
* Input          : aSamples:a table with samples,
* 				   aResults: a result table with spectrum (complex),
* 				   N: number of points.
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft(UTILTYPE *aSamples, COMPLEX *aResults, unsigned N) {
	unsigned i, k, steps = N/2;
	UTILTYPE dc = UTIL_ZERO;
	for(i = 0; i < N; ++i) {
		*(aResults+i) = cpx_zero();
		dc += *(aSamples+i);
	}
	aResults->re = dc/(UTILTYPE)N;
	aResults->im = UTIL_ZERO;

	for(k = 1; k < steps; ++k) {
		for(i = 0; i < N; ++i) {
			COMPLEX x = cpx_e(*(aSamples+i), -M_TWOPI * (UTILTYPE) (i * k)/((UTILTYPE)(N)));
			cpx_addr(aResults+k, &x);
		}
#if DEL_ROUND_ERR == 1
		if((int)((aResults+k)->re*100000) == 0) {
			aResults[k].re = UTIL_ZERO;
		}
		if((int)((aResult+k)->im*100000) == 0) {
			aResults[k].im = UTIL_ZERO;
		}
#endif
		cpx_mul_k(aResults+k, UTIL_TWO/(UTILTYPE)N);
	}
}

/*******************************************************************************
* Function Name  : dft_both
* Description    : Compute spectrum magnitude and phase using dft of N points.
* Input          : aSamples:a table with samples,
* 				   aMagnitude: a result table with spectrum magnitude,
* 				   aPhase: a result table with spectrum phase,
* 				   N: number of points.
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft_both(UTILTYPE *aSamples, UTILTYPE *aMagnitude, UTILTYPE *aPhase, unsigned N) {
	unsigned i, k, steps = N/2;
	UTILTYPE real, imag;

	for(k = 0; k < steps; ++k) {
		real = imag = UTIL_ZERO;

		for(i = 0; i < N; ++i) {
			real += *(aSamples+i) * cosf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
			imag -= *(aSamples+i) * sinf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
		}

#if DEL_ROUND_ERR == 1
		if((int)(real*100000) == 0) {
			real = UTIL_ZERO;
		}
		if((int)(imag*100000) == 0) {
			imag = UTIL_ZERO;
		}
#endif

		*(aMagnitude+k) = sqrtf(real*real + imag*imag)*2/N;
		*(aPhase+k) = atanf(imag/real)*UTIL_180OVERPI;
		if(real < UTIL_ZERO) {
			*(aPhase+k) = (imag > UTIL_ZERO) ? *(aPhase+k) + M_PI : *(aPhase+k) - M_PI;
		}
	}
	*aMagnitude /= UTIL_TWO;
}

/*******************************************************************************
* Function Name  : dft_mag
* Description    : Compute spectrum magnitude using dft of N points.
* Input          : aSamples:a table with samples,
* 				   aMagnitude: a result table with spectrum magnitude,
* 				   N: number of points.
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft_mag(UTILTYPE *aSamples, UTILTYPE *aMagnitude, unsigned N) {
	unsigned i, k, steps = N/2;
	UTILTYPE real, imag;

	for(k = 0; k < steps; ++k) {
		real = imag = UTIL_ZERO;

		for(i = 0; i < N; ++i) {
			real += *(aSamples+i) * cosf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
			imag -= *(aSamples+i) * sinf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
		}

#if DEL_ROUND_ERR == 1
		if((int)(real*100000.0) == 0) {
			real = CPX_ZERO;
		}
		if((int)(imag*100000.0) == 0) {
			imag = CPX_ZERO;
		}
#endif
		*(aMagnitude+k) = sqrtf(real*real + imag*imag)*UTIL_TWO/(UTILTYPE)N;
	}
	*aMagnitude /= UTIL_TWO;
}

/*******************************************************************************
* Function Name  : dft_phase
* Description    : Compute spectrum magnitude and phase using dft of N points.
* Input          : aSamples:a table with samples,
* 				   aPhase: a result table with spectrum phase,
* 				   N: number of points.
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft_phase(UTILTYPE *aSamples, UTILTYPE *aPhase, unsigned N) {
	unsigned i, k, steps = N/2;
	UTILTYPE real, imag;

	for(k = 0; k < steps; ++k) {
		real = imag = UTIL_ZERO;

		for(i = 0; i < N; ++i) {
			real += *(aSamples+i) * cosf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
			imag -= *(aSamples+i) * sinf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
		}

#if DEL_ROUND_ERR == 1
		if((int)(real*100000) == 0) {
			real = UTIL_ZERO;
		}
		if((int)(imag*100000) == 0) {
			imag = UTIL_ZERO;
		}
#endif
		*(aPhase+k) = atanf(imag/real)*UTIL_180OVERPI;
		if(real < UTIL_ZERO) {
			*(aPhase+k) = (imag > UTIL_ZERO) ? *(aPhase+k) + M_PI : *(aPhase+k) - M_PI;
		}
	}
}

/*******************************************************************************
* Function Name  : dft_k
* Description    : Compute spectrum using dft of N points at point k.
* Input          : aSamples:a table with samples,
* 				   k: point where to compute dft,
* 				   N: number of points.
* Output         : None.
* Return         : Complex number of computed dft.
*******************************************************************************/
COMPLEX dft_k(UTILTYPE *aSamples, unsigned k, unsigned N) {
	unsigned i;
	COMPLEX result;
	result = cpx_zero();

	for(i = 0; i < N; ++i) {
		COMPLEX x = cpx_e(*(aSamples+i), -M_TWOPI * (UTILTYPE) (i * k)/((UTILTYPE)(N)));
		cpx_addr(&result, &x);
	}
#if DEL_ROUND_ERR == 1
	if((int)(result.re*100000) == 0) {
		result.re = UTIL_ZERO;
	}
	if((int)(result.im*100000) == 0) {
		result.im = UTIL_ZERO;
	}
#endif
	cpx_mul_k(&result, UTIL_TWO/(UTILTYPE)N);

	return result;
}

/*******************************************************************************
* Function Name  : dft_both_k
* Description    : Compute spectrum magnitude and phase using dft of N points at
* 				   point k.
* Input          : aSamples:a table with samples,
* 				   magnitude: a pointer where magnitude result is saved,
* 				   phase: a pointer where phase result is saved,
* 				   k: point where to compute dft,
* 				   N: number of points.
* Output         : None.
* Return         : None.
*******************************************************************************/
void dft_both_k(UTILTYPE *aSamples, UTILTYPE *magnitude, UTILTYPE *phase, unsigned k, unsigned N) {
	unsigned i;
	UTILTYPE real = UTIL_ZERO, imag = UTIL_ZERO;

	if(k == 0) {
		for(i = 0; i < N; ++i) {
			real += *(aSamples+i);
		}
	} else {
		for(i = 0; i < N; ++i) {
			real += *(aSamples+i) * cosf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
			imag -= *(aSamples+i) * sinf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
		}
	}


#if DEL_ROUND_ERR == 1
	if((int)(real*100000) == 0) {
		real = UTIL_ZERO;
	}
	if((int)(imag*100000) == 0) {
		imag = UTIL_ZERO;
	}
#endif
	if(k == 0) {
		*phase = UTIL_ZERO;
		*magnitude = real/(UTILTYPE)N;
	} else {
		*magnitude = sqrtf(real*real + imag*imag)*2/N;
		*phase = atanf(imag/real)*UTIL_180OVERPI;
		if(real < UTIL_ZERO) {
			*phase = (imag > UTIL_ZERO) ? *phase + M_PI : *phase - M_PI;
		}
	}
}

/*******************************************************************************
* Function Name  : dft_mag_k
* Description    : Compute spectrum magnitude using dft of N points at point k.
* Input          : aSamples:a table with samples,
* 				   k: point where to compute dft,
* 				   N: number of points.
* Output         : None.
* Return         : None.
*******************************************************************************/
UTILTYPE dft_mag_k(UTILTYPE *aSamples, unsigned k, unsigned N) {
	unsigned i;
	UTILTYPE real = UTIL_ZERO, imag = UTIL_ZERO;

	if(k == 0) {
		for(i = 0; i < N; ++i) {
			real += *(aSamples+i) * cosf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
			imag -= *(aSamples+i) * sinf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
		}
	} else {
		for(i = 0; i < N; ++i) {
			real += *(aSamples+i);
		}
	}
#if DEL_ROUND_ERR == 1
	if((int)(real*100000.0) == 0) {
		real = CPX_ZERO;
	}
	if((int)(imag*100000.0) == 0) {
		imag = CPX_ZERO;
	}
#endif
	if(k == 0) {
		return sqrtf(real*real + imag*imag)/(UTILTYPE)N;
	} else {
		return sqrtf(real*real + imag*imag)*UTIL_TWO/(UTILTYPE)N;
	}
}

/*******************************************************************************
* Function Name  : dft_phase_k
* Description    : Compute spectrum magnitude and phase using dft of N points at
* 				   point k.
* Input          : aSamples:a table with samples,
* 				   k: point where to compute dft,
* 				   N: number of points.
* Output         : None.
* Return         : None.
*******************************************************************************/
UTILTYPE dft_phase_k(UTILTYPE *aSamples, unsigned k, unsigned N) {
	unsigned i;
	UTILTYPE ph, real = UTIL_ZERO, imag = UTIL_ZERO;
	if(k == 0)
		return UTIL_ZERO;
	for(i = 0; i < N; ++i) {
		real += *(aSamples+i) * cosf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
		imag -= *(aSamples+i) * sinf(M_TWOPI * (UTILTYPE) (i * k)/(UTILTYPE)(N));
	}

#if DEL_ROUND_ERR == 1
	if((int)(real*100000) == 0) {
		real = UTIL_ZERO;
	}
	if((int)(imag*100000) == 0) {
		imag = UTIL_ZERO;
	}
#endif
	ph = atanf(imag/real)*UTIL_180OVERPI;
	if(real < UTIL_ZERO) {
		ph = (imag > UTIL_ZERO) ? real + M_PI : real - M_PI;
	}
	return ph;
}


