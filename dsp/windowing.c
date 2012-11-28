/*
 * windowing.c
 *
 *  Created on: Nov 25, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "windowing.h"
#include <math.h>
#include <malloc.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern volatile UTILTYPE *util_cos;
volatile UTILTYPE *window;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : windowing_init
* Description    : Calculate whole window parameters.
* Input          : f: a pointer to the window function,
* 				   N: number of samples.
* Output         : None.
* Return         : None.
*******************************************************************************/
void windowing_init(UTILTYPE (*f)(int, int), unsigned N) {
	unsigned i;
	window = (UTILTYPE*) malloc(N*sizeof(UTILTYPE*));
	for(i = 0; i < N; ++i) {
		*(window+i) = f(i, N);
	}
}

/*******************************************************************************
* Function Name  : windowing_free
* Description    : Free memory of window table.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void windowing_free() {
	free((void*) window);
}

/*******************************************************************************
* Function Name  : rectangular
* Description    : Compute scale factor of rectangular window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of rectangular window.
*******************************************************************************/
UTILTYPE rectangular(int n, unsigned N) {
	return 1;
}

/*******************************************************************************
* Function Name  : hanning
* Description    : Compute scale factor of hanning window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of hanning window.
*******************************************************************************/
UTILTYPE hanning(int n, unsigned N) {
#if WINDOWING_USEPRECALCULATION == 1
	return UTIL_HALF*(UTIL_ONE - *(util_cos+n));
#else
	return UTIL_HALF*(UTIL_ONE - cosf(M_TWOPI*(UTILTYPE)n/((UTILTYPE)N)));
#endif
}

/*******************************************************************************
* Function Name  : hamming
* Description    : Compute scale factor of hamming window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of hamming window.
*******************************************************************************/
UTILTYPE hamming(int n, unsigned N) {
#if WINDOWING_USEPRECALCULATION == 1
	return (WINDOWING_HAMMING + (UTIL_ONE-WINDOWING_HAMMING)*(*(util_cos+n)));
#else
	return (WINDOWING_HAMMING + (UTIL_ONE-WINDOWING_HAMMING)*cosf(M_TWOPI*(UTILTYPE)n/((UTILTYPE)N)));
#endif
}

/*******************************************************************************
* Function Name  : blackman
* Description    : Compute scale factor of blackman window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of blackman window.
*******************************************************************************/
UTILTYPE blackman(int n, unsigned N) {
#if WINDOWING_USEPRECALCULATION == 1
	return WINDOWING_BLACKMAN_A0+WINDOWING_BLACKMAN_A1*(*(util_cos+n))+WINDOWING_BLACKMAN_A2*(*(util_cos+(2*n%N)));
#else
	return WINDOWING_BLACKMAN_A0+WINDOWING_BLACKMAN_A1*cosf(M_TWOPI*(UTILTYPE)n/((UTILTYPE)N))+WINDOWING_BLACKMAN_A2*cosf(M_FOURPI*(UTILTYPE)n/((UTILTYPE)N));
#endif
}

/*******************************************************************************
* Function Name  : triangular
* Description    : Compute scale factor of triangular window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of triangular window.
*******************************************************************************/
UTILTYPE triangular(int n, unsigned N) {
	return UTIL_ONE-util_abs((UTILTYPE)n-(N/2))/(UTILTYPE)(N/2);
}

/*******************************************************************************
* Function Name  : cosine
* Description    : Compute scale factor of cosine window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of cosine window.
*******************************************************************************/
UTILTYPE cosine(int n, unsigned N) {
	return util_pow(cosf(M_PI*(UTILTYPE)n/((UTILTYPE)N)), WINDOWING_COSINE);
}

/*******************************************************************************
* Function Name  : sine
* Description    : Compute scale factor of sine window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of sine window.
*******************************************************************************/
UTILTYPE sine(int n, unsigned N) {
	return cosine(n, N);
}

/*******************************************************************************
* Function Name  : lanczos
* Description    : Compute scale factor of lanczos window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of lanczos window.
*******************************************************************************/
UTILTYPE lanczos(int n, unsigned N) {
	UTILTYPE x = M_TWOPI*(UTILTYPE)n/(UTILTYPE)N-UTIL_ONE;
	return sinf(x)/x;
}

/*******************************************************************************
* Function Name  : gaussian
* Description    : Compute scale factor of gaussian window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of gaussian window.
*******************************************************************************/
UTILTYPE gaussian(int n, unsigned N) {
	UTILTYPE x = WINDOWING_GAUSSIAN*(UTILTYPE)n/(UTILTYPE)(N/2);
	return expf(-UTIL_HALF*x*x);
}

/*******************************************************************************
* Function Name  : cauchy
* Description    : Compute scale factor of cauchy window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of cauchy window.
*******************************************************************************/
UTILTYPE cauchy(int n, unsigned N) {
	UTILTYPE x = WINDOWING_CAUCHY*util_abs((UTILTYPE)(n-(N/2)))/(UTILTYPE)(N/2);
	return UTIL_ONE/(UTIL_ONE+x*x);
}

/*******************************************************************************
* Function Name  : poison
* Description    : Compute scale factor of poison window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of poison window.
*******************************************************************************/
UTILTYPE poisson(int n, unsigned N) {
	return expf(-WINDOWING_POISSON*util_abs((UTILTYPE)(n-N/2))/(N/2));
}

/*******************************************************************************
* Function Name  : hann_poison
* Description    : Compute scale factor of hann_poison window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of hann_poison window.
*******************************************************************************/
UTILTYPE hann_poisson(int n, unsigned N) {
	return UTIL_HALF*(UTIL_ONE+cosf(M_PI*(UTILTYPE)n/(UTILTYPE)(N/2)))*expf(-WINDOWING_HANNPOISSON*util_abs((UTILTYPE)(n-N/2))/(N/2));
}

/*******************************************************************************
* Function Name  : bohman
* Description    : Compute scale factor of bohman window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of bohman window.
*******************************************************************************/
UTILTYPE bohman(int n, unsigned N) {
	UTILTYPE x = util_abs((UTILTYPE)(n-(N/2)))/(UTILTYPE)(N/2);
	return (UTIL_ONE-x)*cosf(M_PI*x)+M_1_PI*sinf(M_PI*x);
}

/*******************************************************************************
* Function Name  : riemann
* Description    : Compute scale factor of riemann window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of riemann window.
*******************************************************************************/
UTILTYPE riemann(int n, unsigned N) {
#if WINDOWING_USEPRECALCULATION == 1
	int x = util_abs_d(n-(N/2));
	if(n == N/2)
		return UTIL_ONE;
	else
		return *(util_cos+((x+N/4)%N))/(M_TWOPI*(UTILTYPE)x/(UTILTYPE)N);
#else
	UTILTYPE x = util_abs((UTILTYPE)(n-(N/2)));
	if(n == N/2)
		return UTIL_ONE;
	else
		return sin(M_TWOPI*x/(M_TWOPI*x)/(UTILTYPE)N);
#endif
}

/*******************************************************************************
* Function Name  : parabolic
* Description    : Compute scale factor of parabolic window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of parabolic window.
*******************************************************************************/
UTILTYPE parabolic(int n, unsigned N) {
	UTILTYPE x = util_abs((UTILTYPE)(n-(N/2)))/(UTILTYPE)(N/2);
	return UTIL_ONE-x*x;
}

/*******************************************************************************
* Function Name  : kaiser_bessel
* Description    : Compute scale factor of kaiser_bessel window at sample n of N.
* Input          : n: sample number,
* 				   N: number of samples
* Output         : None.
* Return         : Scale factor of kaiser_bessel window.
*******************************************************************************/
UTILTYPE kaiser_bessel(int n, unsigned N) {
	//TODO
	return 1;
}
