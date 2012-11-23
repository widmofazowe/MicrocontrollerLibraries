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
* 				   start: number of sample where start the integration
* 				   stop: number of sample where stop the integration
* Output         : None.
* Return         : Integral of given samples.
*******************************************************************************/
UTILTYPE util_trapezoid_integral(UTILTYPE samples[], UTILTYPE h, unsigned int start, unsigned int stop) {
	UTILTYPE ans = UTIL_ZERO;
	unsigned int i;
	for(i = start; i < stop-1; ++i) {
		ans += samples[i] + UTIL_HALF*(samples[i+1]-samples[i]);
	}
	return ans*h;
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
UTILTYPE util_rect_integral(UTILTYPE samples[], UTILTYPE h, unsigned int start, unsigned int stop) {
	UTILTYPE ans = UTIL_ZERO;
	unsigned int i;
	for(i = start; i < stop-1; ++i) {
		ans += (samples[i]+samples[i+1]);
	}
	return ans*h*UTIL_HALF;
}

/*******************************************************************************
* Function Name  : util_parabol_integral
* Description    : Compute integral using rectangular approximation.
* Input          : samples: a table with samples of function which is being integrated
* 				   h: spacing between samples
* 				   N: number of samples
* Output         : None.
* Return         : Integral of given samples.
*******************************************************************************/
UTILTYPE util_parabol_integral(UTILTYPE samples[], UTILTYPE h, unsigned int start, unsigned int stop) {
	UTILTYPE ans = UTIL_ZERO;
	unsigned int i;
	for(i = start; i < stop-1; ++i) {
		ans += (samples[i]+4*samples[i+1]+samples[i+2]);
	}
	return ans*h/UTIL_THREE;
}

/*******************************************************************************
* Function Name  : util_difference1
* Description    : Compute difference at given point with using (f(x+h)-f1(x))/h.
* Input          : samples: a table with samples of function where difference is being calculated
* 				   h: spacing between samples
* 				   point: number of sample where difference is being calculated
* 				   N: number of samples
* Output         : None.
* Return         : Difference of samples at desired point.
*******************************************************************************/
UTILTYPE util_difference1(UTILTYPE samples[], UTILTYPE h, unsigned int point) {
	return (samples[point+1]-samples[point])/h;
}

/*******************************************************************************
* Function Name  : util_difference2
* Description    : Compute difference at given point using (f(x+h)-f(x-h))/(2*h).
* Input          : samples: a table with samples of function where difference is being calculated
* 				   h: spacing between samples
* 				   point: number of sample where difference is being calculated
* 				   N: number of samples
* Output         : None.
* Return         : Difference of samples at desired point.
*******************************************************************************/
UTILTYPE util_difference2(UTILTYPE samples[], UTILTYPE h, unsigned int point) {
	return (samples[point+1]-samples[point-1])/(2*h);
}

/*******************************************************************************
* Function Name  : util_factorial
* Description    : Compute factorial of a number.
* Input          : x: number of which factorial is being computed
* Output         : None.
* Return         : Factorial of a given number.
*******************************************************************************/
unsigned int util_factorial(unsigned int x) {
	int i,w = 1;
	if(x == 0 || x == 1)
		return 1;

	for(i = 2 ;i <= x; ++i)
		w *= i;
	return w;
}

/*******************************************************************************
* Function Name  : util_abs_i
* Description    : Compute absolute of an integer number.
* Input          : x: integer number
* Output         : None.
* Return         : Absolute of an integer number.
*******************************************************************************/
int util_abs_i(int x) {
	if(x < 0)
		x = -x;
	return x;
}

/*******************************************************************************
* Function Name  : util_abs_f
* Description    : Compute absolute of a float number.
* Input          : x: float number
* Output         : None.
* Return         : Absolute of a float number.
*******************************************************************************/
float util_abs_f(float x) {
	if(x < 0.0f)
		x = -x;
	return x;
}

/*******************************************************************************
* Function Name  : util_abs_d
* Description    : Compute absolute of a double number.
* Input          : x: double number
* Output         : None.
* Return         : Absolute of a double number.
*******************************************************************************/
double util_abs_d(double x) {
	if(x < 0.0)
		x = -x;
	return x;
}
