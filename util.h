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

//if equal to 0 compute difference using (f(x+h)-f1(x))/h;
//if equal to 1 compute difference using (f(x+h)-f(x-h))/(2*h);
#define USE_DIFF_2H 0

/* Exported types ------------------------------------------------------------*/
#if UTIL_MODE == UTIL_FLOAT_MODE
	typedef float UTILTYPE;
#else
	typedef double UTILTYPE;
#endif

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
UTILTYPE util_trapezoid_integral(UTILTYPE samples[], UTILTYPE h, unsigned int N);
UTILTYPE util_rect_integral(UTILTYPE samples[], UTILTYPE h, unsigned int N);
UTILTYPE util_difference(UTILTYPE samples[], UTILTYPE h, unsigned int point);
#endif /* _H_UTIL */
