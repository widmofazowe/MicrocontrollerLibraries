/*
 * util.c
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "util.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : util_trapezoid_integral
* Description    : Compute integral using trapezoid approximation.
* Input          : samples: a table with samples of function which is being integrated
* 				   h: spacing between samples
* 				   N: number of samples
* Output         : None.
* Return         : Integral of given samples.
*******************************************************************************/
UTILTYPE util_trapezoid_integral(UTILTYPE samples[], UTILTYPE h, unsigned int N) {
	UTILTYPE ans = UTIL_ZERO;
	unsigned int i;
	for(i = 0; i < N-1; ++i) {
		ans += h*samples[i] + 0.5*h*(samples[i+1]-samples[i]);
	}
	return ans;
}

/*******************************************************************************
* Function Name  : util_rect_integral
* Description    : Compute integral using rectangular approximation.
* Input          : samples: a table with samples of function which is being integrated
* 				   h: spacing between samples
* 				   N: number of samples
* Output         : None.
* Return         : Integral of given samples.
*******************************************************************************/
UTILTYPE util_rect_integral(UTILTYPE samples[], UTILTYPE h, unsigned int N) {
	UTILTYPE ans = UTIL_ZERO;
	unsigned int i;
	for(i = 0; i < N-1; ++i) {
		ans += h*samples[i];
	}
	return ans;
}

/*******************************************************************************
* Function Name  : util_difference
* Description    : Compute difference at given point.
* Input          : samples: a table with samples of function where difference is being calculated
* 				   h: spacing between samples
* 				   point: number of sample where difference is being calculated
* 				   N: number of samples
* Output         : None.
* Return         : Difference of samples at desired point.
*******************************************************************************/
UTILTYPE util_difference(UTILTYPE samples[], UTILTYPE h, unsigned int point) {
#if USE_DIFF_2H == 0
	return (samples[point+1]-samples[point])/h;
#else
	return (samples[point+1]-samples[point-1])/(2*h);
#endif
}
