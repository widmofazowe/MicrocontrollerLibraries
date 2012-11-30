/*
 * util.c
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "util.h"
#include <math.h>
#include <stdlib.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//cos(2*pi*x) = cos_table(x)
//sin(2*pi*x) = cos_table((x+N/4)%N)
volatile UTILTYPE *util_cos;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : util_trapezoid_int16_tegral
* Description    : Compute int16_tegral using trapezoid approximation.
* Input          : samples: a table with samples of function which is being
*                           int16_tegrated,
* 				   h: spacing between samples,
* 				   start: number of sample where start the int16_tegration,
* 				   stop: number of sample where stop the int16_tegration.
* Output         : None.
* Return         : Integral of given samples.
*******************************************************************************/
UTILTYPE util_trapezoid_int16_tegral(UTILTYPE *samples, UTILTYPE h, uint16_t start, uint16_t stop) {
	UTILTYPE ans = UTIL_ZERO;
	uint16_t i;
	for(i = start; i < stop-1; ++i) {
		ans += *(samples+i) + UTIL_HALF*(*(samples+i+1)-*(samples+i));
	}
	return ans*h;
}

/*******************************************************************************
* Function Name  : util_rect_int16_tegral
* Description    : Compute int16_tegral using rectangular approximation.
* Input          : samples: a table with samples of function which is being
*                           int16_tegrated,
* 				   h: spacing between samples,
* 				   N: number of samples.
* Output         : None.
* Return         : Integral of given samples.
*******************************************************************************/
UTILTYPE util_rect_int16_tegral(UTILTYPE *samples, UTILTYPE h, uint16_t start, uint16_t stop) {
	UTILTYPE ans = UTIL_ZERO;
	uint16_t i;
	for(i = start; i < stop-1; ++i) {
		ans += ((*(samples+i))+(*(samples+i+1)));
	}
	return ans*h*UTIL_HALF;
}

/*******************************************************************************
* Function Name  : util_parabol_int16_tegral
* Description    : Compute int16_tegral using rectangular approximation.
* Input          : samples: a table with samples of function which is being
*                           int16_tegrated,
* 				   h: spacing between samples,
* 				   N: number of samples.
* Output         : None.
* Return         : Integral of given samples.
*******************************************************************************/
UTILTYPE util_parabol_int16_tegral(UTILTYPE *samples, UTILTYPE h, uint16_t start, uint16_t stop) {
	UTILTYPE ans = UTIL_ZERO;
	uint16_t i;
	for(i = start; i < stop-1; ++i) {
		ans += ((*(samples+i))+4*(*(samples+i+1))+(*(samples+i+2)));
	}
	return ans*h/UTIL_THREE;
}

/*******************************************************************************
* Function Name  : util_difference1
* Description    : Compute difference at given point16_t with using (f(x+h)-f1(x))/h.
* Input          : samples: a table with samples of function where difference
*                           is being calculated,
* 				   h: spacing between samples,
* 				   point16_t: number of sample where difference is being calculated,
* 				   N: number of samples.
* Output         : None.
* Return         : Difference of samples at desired point16_t.
*******************************************************************************/
UTILTYPE util_difference1(UTILTYPE *samples, UTILTYPE h, uint16_t point16_t) {
	return ((*(samples+point16_t+1))-(*(samples+point16_t)))/h;
}

/*******************************************************************************
* Function Name  : util_difference2
* Description    : Compute difference at given point16_t using (f(x+h)-f(x-h))/(2*h).
* Input          : samples: a table with samples of function where difference is
*                           being calculated,
* 				   h: spacing between samples,
* 				   point16_t: number of sample where difference is being calculated,
* 				   N: number of samples.
* Output         : None.
* Return         : Difference of samples at desired point16_t.
*******************************************************************************/
UTILTYPE util_difference2(UTILTYPE samples[], UTILTYPE h, uint16_t point16_t) {
	return ((*(samples+point16_t+1))-(*(samples+point16_t-1)))/(2*h);
}

/*******************************************************************************
* Function Name  : util_factorial
* Description    : Compute factorial of a number.
* Input          : x: number of which factorial is being computed.
* Output         : None.
* Return         : Factorial of a given number.
*******************************************************************************/
uint16_t util_factorial(uint16_t x) {
	uint16_t i,w = 1;
	if(x == 0 || x == 1)
		return 1;

	for(i = 2 ; i <= x; ++i)
		w *= i;
	return w;
}

/*******************************************************************************
* Function Name  : util_abs
* Description    : Compute absolute of an UTILTYPE number.
* Input          : x: UTILTYPE number.
* Output         : None.
* Return         : Absolute of an UTILTYPE number.
*******************************************************************************/
UTILTYPE util_abs(UTILTYPE x) {
	if(x < UTIL_ZERO)
		x = -x;
	return x;
}

/*******************************************************************************
* Function Name  : util_abs_i
* Description    : Compute absolute of an int16_teger number.
* Input          : x: int16_teger number.
* Output         : None.
* Return         : Absolute of an int16_teger number.
*******************************************************************************/
int16_t util_abs_i(int16_t x) {
	if(x < 0)
		x = -x;
	return x;
}

/*******************************************************************************
* Function Name  : util_abs_f
* Description    : Compute absolute of a float number.
* Input          : x: float number.
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
* Input          : x: double number.
* Output         : None.
* Return         : Absolute of a double number.
*******************************************************************************/
double util_abs_d(double x) {
	if(x < 0.0)
		x = -x;
	return x;
}

/*******************************************************************************
* Function Name  : util_fpow
* Description    : Fast power of natural number.
* Input          : x: number,
				   n: power.
* Output         : None.
* Return         : x to the power of n.
*******************************************************************************/
uint16_t util_fpow(uint16_t x, uint16_t n) {
	uint16_t ans = 1;
	while(n > 0) {
		if(n & 1) {
			ans *= x;
		}
		x *= x;
		n >>= 1;
	}
	return ans;
}

/*******************************************************************************
* Function Name  : util_pow
* Description    : Compute x to the power of n.
* Input          : x: number,
				   n: power.
* Output         : None.
* Return         : x to the power of n.
*******************************************************************************/
UTILTYPE util_pow(UTILTYPE x, int16_t n) {
	UTILTYPE ans = 1;
	if (n == 0) {
		return 1;
	} else if(n > 0) {
		while(n-- > 0) {
			ans *= x;
		}
	} else {
		while(n++ < 0) {
			ans *= x;
		}
		ans = 1/ans;
	}
	return ans;
}

/*******************************************************************************
* Function Name  : util_root
* Description    : Compute n-th degree root of x.
* Input          : x: number,
				   n: degree.
* Output         : None.
* Return         : n-th degree root of x.
*******************************************************************************/
UTILTYPE util_root(UTILTYPE x, int16_t n) {
	UTILTYPE result = x;
	UTILTYPE tmp;
	UTILTYPE e = M_PI;
	int16_t nt;
	tmp = 1;
	nt = n - 1;
	while(nt-- > 0) {
		tmp *= result;
	}
	while(e >= UTIL_ERR) {
		result = (((UTILTYPE)n-1)*result + (x/tmp))/(UTILTYPE)n;
		tmp = 1;
		nt = n - 1;
		while(nt-- > 0) {
			tmp *= result;
		}
		e = (x - tmp * result);
		if(e < UTIL_ZERO)
			e = -e;
	}
	return result;
}

/*******************************************************************************
* Function Name  : util_sqrt
* Description    : Compute square root of x.
* Input          : x: number.
* Output         : None.
* Return         : Square root of x.
*******************************************************************************/
UTILTYPE util_sqrt(UTILTYPE x) {
	UTILTYPE result = x;
	UTILTYPE e = M_PI;
	while(e >= UTIL_ERR) {
		result = (result + (x/result))/UTIL_TWO;
		e = (x - result * result);
		if(e < UTIL_ZERO)
			e = -e;
	}
	return result;
}

/*******************************************************************************
* Function Name  : util_initcos
* Description    : Initialize cos table.
* Input          : N: number of derived point16_ts (spacing - 2pi/N).
* Output         : None.
* Return         : None.
*******************************************************************************/
void util_initcos(uint16_t N) {
	uint16_t i;
	util_cos = (UTILTYPE*) malloc(N*sizeof(UTILTYPE));
    for(i = 0; i < N; ++i) {
    	util_cos[i] = (UTILTYPE) cosf(M_TWOPI*(UTILTYPE)(i)/(UTILTYPE)N);
    }
}

/*******************************************************************************
* Function Name  : util_free
* Description    : Free memory of cosinus table.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void util_free() {
	free((void*) util_cos);
}

/*******************************************************************************
* Function Name  : util_mod
* Description    : Compute the rest from dividing.
* Input          : x: number,
* 				   n: dividend.
* Output         : None.
* Return         : Rest from dividing x over n.
*******************************************************************************/
uint16_t util_mod(int16_t x, uint16_t n) {
	x %= n;
	return (x < 0) ? x+n : x;
}
