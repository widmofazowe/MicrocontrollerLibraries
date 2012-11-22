/*
 * complex.h
 *
 *  Created on: Oct 25, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _H_COMPLEX_
#define _H_COMPLEX_
/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef float CPXTYPE; //should be float or double

typedef struct {
	CPXTYPE re;
	CPXTYPE im;
} COMPLEX;

typedef struct {
	CPXTYPE magnitude;
	CPXTYPE angle;
} COMPLEXtrig;
/* Exported constants --------------------------------------------------------*/
#define CPX_FLOAT_MODE  (1)
#define CPX_DOUBLE_MODE  (2)
//for CPX_TYPE as float use #define CPX_MODE CPX_FLOAT_MODE
//for CPX_TYPE as double use #define CPX_MODE CPX_DOUBLE_MODE
#define CPX_MODE CPX_FLOAT_MODE
//define CPX_MODE CPX_DOUBLE_MODE
#if CPX_MODE == CPX_FLOAT_MODE
	#define CPX_ZERO 0.0f
	#define CPX_180OVERPI 57.29578f
	#define CPX_PIOVER180 0.0174533f
#else
	#define CPX_ZERO = 0.0
	#define CPX_180OVERPI 57.295779513082
	#define CPX_PIOVER180 0.01745329252
#endif
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
COMPLEX cpx(CPXTYPE a, CPXTYPE b);
COMPLEX cpx_add(COMPLEX* a, COMPLEX* b);
COMPLEX cpx_sub(COMPLEX* a, COMPLEX* b);
COMPLEX cpx_mul(COMPLEX* a, COMPLEX* b);
COMPLEX cpx_div(COMPLEX* a, COMPLEX* b);
inline CPXTYPE cpx_abs(COMPLEX* x);
CPXTYPE cpx_angle(COMPLEX* x);
COMPLEX cpx_cconjugate(COMPLEX* x);
inline void cpx_conjugate(COMPLEX* x);
inline CPXTYPE cpx_re(COMPLEX* x);
inline CPXTYPE cpx_im(COMPLEX* x);
COMPLEXtrig cpx_c2t(COMPLEX* x);
COMPLEX cpx_t2c(COMPLEXtrig* x);
inline CPXTYPE rad2deg(CPXTYPE x);
inline CPXTYPE deg2rad(CPXTYPE x);

#endif /* COMPLEX_ */
