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
#include "util.h"

/* Exported constants --------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

typedef struct {
	UTILTYPE re;
	UTILTYPE im;
} COMPLEX;

typedef struct {
	UTILTYPE magnitude;
	UTILTYPE angle;
} COMPLEXtrig;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
COMPLEX cpx(UTILTYPE a, UTILTYPE b);
COMPLEX cpx_add(COMPLEX* a, COMPLEX* b);
COMPLEX cpx_sub(COMPLEX* a, COMPLEX* b);
COMPLEX cpx_mul(COMPLEX* a, COMPLEX* b);
COMPLEX cpx_div(COMPLEX* a, COMPLEX* b);
__inline UTILTYPE cpx_abs(COMPLEX* x);
UTILTYPE cpx_angle(COMPLEX* x);
COMPLEX cpx_cconjugate(COMPLEX* x);
__inline void cpx_conjugate(COMPLEX* x);
__inline UTILTYPE cpx_re(COMPLEX* x);
__inline UTILTYPE cpx_im(COMPLEX* x);
COMPLEXtrig cpx_c2t(COMPLEX* x);
COMPLEX cpx_t2c(COMPLEXtrig* x);
__inline UTILTYPE rad2deg(UTILTYPE x);
__inline UTILTYPE deg2rad(UTILTYPE x);
COMPLEX cpx_zero();
COMPLEX cpx_e(UTILTYPE mag, UTILTYPE angle);
void cpx_add_re(COMPLEX* a, UTILTYPE re);
void cpx_add_im(COMPLEX* a, UTILTYPE im);
void cpx_sub_re(COMPLEX* a, UTILTYPE re);
void cpx_sub_im(COMPLEX* a, UTILTYPE im);
void cpx_mul_k(COMPLEX* a, UTILTYPE k);
void cpx_div_k(COMPLEX* a, UTILTYPE k);
void cpx_addr(COMPLEX* a, COMPLEX* b);
void cpx_subr(COMPLEX* a, COMPLEX* b);
void cpx_mulr(COMPLEX* a, COMPLEX* b);
void cpx_divr(COMPLEX* a, COMPLEX* b);

#endif /* _H_COMPLEX */
