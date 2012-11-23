/*
 * util.h
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 *
 *  Notes:
 *  	Spacing in function can be seen as period of a signal.
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _H_UTIL
#define _H_UTIL

/* Includes ------------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define UTIL_FLOAT_MODE  (0)
#define UTIL_DOUBLE_MODE  (1)

//for UTIL_TYPE as float use #define UTIL_MODE UTIL_FLOAT_MODE
//for UTIL_TYPE as double use #define UTIL_MODE UTIL_DOUBLE_MODE
#define UTIL_MODE UTIL_FLOAT_MODE
//define UTIL_MODE UTIL_DOUBLE_MODE

#if UTIL_MODE == UTIL_FLOAT_MODE
	#define UTIL_ZERO 0.0f
	#define UTIL_HALF 0.5f
	#define UTIL_THREE 3.0f
	#ifndef M_PI
		#define M_PI		3.1415927f
	#endif
	#ifndef M_TWOPI
		#define M_TWOPI     6.2831853f
	#endif
	#ifndef M_PI_2
		#define M_PI_2		1.5707963f
	#endif
#else
	#define UTIL_ZERO = 0.0
	#define UTIL_HALF 0.5
	#define UTIL_THREE 3.0
	#ifndef M_PI
		#define M_PI		3.14159265358979323846
	#endif
	#ifndef M_TWOPI
		#define M_TWOPI     6.28318530717958647693
	#endif
	#ifndef M_PI_2
		#define M_PI_2		1.57079632679489661923
	#endif
#endif

/* Exported types ------------------------------------------------------------*/
#if UTIL_MODE == UTIL_FLOAT_MODE
	typedef float UTILTYPE;
#else
	typedef double UTILTYPE;
#endif

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
UTILTYPE util_trapezoid_integral(UTILTYPE samples[], UTILTYPE h, unsigned int start, unsigned int stop);
UTILTYPE util_rect_integral(UTILTYPE samples[], UTILTYPE h, unsigned int start, unsigned int stop);
UTILTYPE util_parabol_integral(UTILTYPE samples[], UTILTYPE h, unsigned int start, unsigned int stop);
UTILTYPE util_difference1(UTILTYPE samples[], UTILTYPE h, unsigned int point);
UTILTYPE util_difference2(UTILTYPE samples[], UTILTYPE h, unsigned int point);
unsigned int util_factorial(unsigned int x);
int util_abs_i(int x);
float util_abs_f(float x);
double util_abs_d(double x);
#endif /* _H_UTIL */
