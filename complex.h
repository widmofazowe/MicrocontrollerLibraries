/*
 * complex.h
 *
 *  Created on: Oct 25, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _H_COMPLEX
#define _H_COMPLEX
/* Includes ------------------------------------------------------------------*/


/* Exported constants --------------------------------------------------------*/
#define CPX_FLOAT_MODE  (0)
#define CPX_DOUBLE_MODE  (1)

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

/* Exported types ------------------------------------------------------------*/
#if CPX_MODE == CPX_FLOAT_MODE
	typedef float CPXTYPE;
#else
	typedef double CPXTYPE;
#endif
typedef struct {
	CPXTYPE re;
	CPXTYPE im;
} COMPLEX;

typedef struct {
	CPXTYPE magnitude;
	CPXTYPE angle;
} COMPLEXtrig;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
COMPLEX cpx(CPXTYPE a, CPXTYPE b);
void cpx_add(COMPLEX* a, COMPLEX* b);
void cpx_sub(COMPLEX* a, COMPLEX* b);
void cpx_mul(COMPLEX* a, COMPLEX* b);
void cpx_div(COMPLEX* a, COMPLEX* b);
__inline CPXTYPE cpx_abs(COMPLEX* x);
CPXTYPE cpx_angle(COMPLEX* x);
COMPLEX cpx_cconjugate(COMPLEX* x);
__inline void cpx_conjugate(COMPLEX* x);
__inline CPXTYPE cpx_re(COMPLEX* x);
__inline CPXTYPE cpx_im(COMPLEX* x);
COMPLEXtrig cpx_c2t(COMPLEX* x);
COMPLEX cpx_t2c(COMPLEXtrig* x);
__inline CPXTYPE rad2deg(CPXTYPE x);
__inline CPXTYPE deg2rad(CPXTYPE x);
COMPLEX cpx_zero();
COMPLEX cpx_e(CPXTYPE mag, CPXTYPE angle);
void cpx_add_re(COMPLEX* a, CPXTYPE re);
void cpx_add_im(COMPLEX* a, CPXTYPE im);
void cpx_sub_re(COMPLEX* a, CPXTYPE re);
void cpx_sub_im(COMPLEX* a, CPXTYPE im);
void cpx_mul_k(COMPLEX* a, CPXTYPE k);
void cpx_div_k(COMPLEX* a, CPXTYPE k);

#endif /* _H_COMPLEX */
