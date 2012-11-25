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
//#define UTIL_MODE UTIL_DOUBLE_MODE

#if UTIL_MODE == UTIL_FLOAT_MODE
	#define UTIL_ZERO 0.0f
	#define UTIL_HALF 0.5f
	#define UTIL_ONE 1.0f
	#define UTIL_TWO 2.0f
	#define UTIL_THREE 3.0f
	#define UTIL_ERR 0.00001f
	#define UTIL_180OVERPI 57.2957795f
	#define UTIL_PIOVER180 0.0174533f
	#ifndef M_1_PI
		#define M_1_PI		0.31830989f
	#endif
	#ifndef M_E
		#define M_E			2.71828183f
	#endif
	#ifndef M_PI
		#define M_PI		3.1415927f
	#endif
	#ifndef M_TWOPI
		#define M_TWOPI     6.2831853f
	#endif
	#ifndef M_FOURPI
		#define M_FOURPI	12.5663706f
	#endif
	#ifndef M_PI_2
		#define M_PI_2		1.5707963f
	#endif
#else
	#define UTIL_ZERO 0.0
	#define UTIL_HALF 0.5
	#define UTIL_ONE 1.0
	#define UTIL_TWO 2.0
	#define UTIL_THREE 3.0
	#define UTIL_ERR 0.000001
	#define UTIL_180OVERPI 57.2957795f13082321
	#define UTIL_PIOVER180 0.0174532925199433
	#ifndef M_1_PI
		#define M_1_PI		0.3183098861837906715
	#endif
	#ifndef M_E
		#define M_E			2.7182818284590452354
	#endif
	#ifndef M_PI
		#define M_PI		3.1415926535897932385
	#endif
	#ifndef M_TWOPI
		#define M_TWOPI     6.2831853071795864769
	#endif
	#ifndef M_FOURPI
		#define M_FOURPI	12.5663706143591729539
	#endif
	#ifndef M_PI_2
		#define M_PI_2		1.5707963267948966192
	#endif
#endif

/* Exported types ------------------------------------------------------------*/
#if UTIL_MODE == UTIL_FLOAT_MODE
	typedef float UTILTYPE;
#else
	typedef double UTILTYPE;
#endif


/* Exported macro ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
extern volatile UTILTYPE *util_cos;
/* Exported functions ------------------------------------------------------- */
UTILTYPE util_trapezoid_integral(UTILTYPE samples[], UTILTYPE h, unsigned start, unsigned stop);
UTILTYPE util_rect_integral(UTILTYPE samples[], UTILTYPE h, unsigned start, unsigned stop);
UTILTYPE util_parabol_integral(UTILTYPE samples[], UTILTYPE h, unsigned start, unsigned stop);
UTILTYPE util_difference1(UTILTYPE samples[], UTILTYPE h, unsigned point);
UTILTYPE util_difference2(UTILTYPE samples[], UTILTYPE h, unsigned point);
unsigned int util_factorial(unsigned x);
UTILTYPE util_abs(UTILTYPE x);
int util_abs_i(int x);
float util_abs_f(float x);
double util_abs_d(double x);
unsigned util_fpow(unsigned x, unsigned n);
UTILTYPE util_pow(UTILTYPE x, int n);
UTILTYPE util_root(UTILTYPE x, int n);
UTILTYPE util_sqrt(UTILTYPE x);
void util_initcos();
void util_free();
#endif /* _H_UTIL */
