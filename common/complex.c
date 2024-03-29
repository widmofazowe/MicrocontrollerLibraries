/*
 * complex
 *
 *  Created on: Oct 25, 2012
 *      Author: widmo
 * Description: Complex calculations.
 */

/* Includes ------------------------------------------------------------------*/
#include <math.h>
#include "complex.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : cpx
* Description    : Create a complex numbers.
* Input          : a:real part of a COMPLEX number,
* 				   b:imaginary part of a COMPLEX number.
* Output         : None.
* Return         : COMPLEX variable.
*******************************************************************************/
COMPLEX cpx(UTILTYPE a, UTILTYPE b) {
	COMPLEX tmp;
	tmp.re = a;
	tmp.im = b;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_add
* Description    : Add a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible,
* 				   b:a pointer to the second COMPLEX varible.
* Output         : None.
* Return         : Sum of two complex numbers.
*******************************************************************************/
COMPLEX cpx_add(COMPLEX* a, COMPLEX* b) {
	COMPLEX tmp;
	tmp.re = a->re + b->re;
	tmp.im = a->im + b->im;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_sub
* Description    : Substract a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible and a pointer to the
* 					 result,
* 				   b:a pointer to the second COMPLEX varible.
* Output         : None.
* Return         : Substraction of two complex numbers.
*******************************************************************************/
COMPLEX cpx_sub(COMPLEX* a, COMPLEX* b) {
	COMPLEX tmp;
	tmp.re = a->re - b->re;
	tmp.im = a->im - b->im;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_mul
* Description    : Multiply a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible and a pointer to the
*                    result,
* 				   b:a pointer to the second COMPLEX varible.
* Output         : None.
* Return         : Multiplication of two complex numbers..
*******************************************************************************/
COMPLEX cpx_mul(COMPLEX* a, COMPLEX* b) {
	COMPLEX tmp;
	tmp.re = a->re * b->re - a->im * b->im;
	tmp.im = a->re * b->im + b->re * a->im;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_div
* Description    : Divide a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible and a pointer to the
*                    result,
* 				   b:a pointer to the second COMPLEX varible.
* Output         : None.
* Return         : Division of two complex numbers..
*******************************************************************************/
COMPLEX cpx_div(COMPLEX* a, COMPLEX* b) {
	COMPLEX tmp;
	UTILTYPE tm = b->re * b->re + b->im * b->im;
	tmp.re = (a->re * b->re + a->im * b->im)/tm;
	tmp.im = (a->im * b->re - a->re * b->im)/tm;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_abs
* Description    : Calculate magnitude of a complex number.
* Input          : x:a pointer to the COMPLEX varible.
* Output         : None.
* Return         : Magnitude of a complex number (sqrt(x.re^2 + x.im^2)).
*******************************************************************************/
UTILTYPE cpx_abs(COMPLEX* x) {
	return (UTILTYPE) util_sqrt(x->re*x->re + x->im*x->im);
}

/*******************************************************************************
* Function Name  : cpx_angle
* Description    : Calculate argument of a complex number.
* Input          : x:a pointer to the COMPLEX varible.
* Output         : None.
* Return         : Argument of a complex number in radians (arc tan(x.im/x.re) + [pi when x.re < 0] or - [pi when x.re < 0 and x.im < 0]).
*******************************************************************************/
UTILTYPE cpx_angle(COMPLEX* x) {
	UTILTYPE tmp;
	if(x->im == UTIL_ZERO)
		return M_PI_2;
	tmp = (UTILTYPE) atanf(x->im/x->re);
	if(x->re < UTIL_ZERO) {
		tmp = (x->im > UTIL_ZERO) ? tmp + M_PI : tmp - M_PI;
	}
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_cconjugate
* Description    : Gives a complex conjugate of a complex number.
* Input          : x:a pointer to the COMPLEX varible.
* Output         : None.
* Return         : Complex conjugate of a complex number (x*).
*******************************************************************************/
COMPLEX cpx_cconjugate(COMPLEX* x) {
	COMPLEX tmp;
	tmp.re = x->re;
	tmp.im = -x->im;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_conjugate
* Description    : Converts a complex number to its complex conjugate.
* Input          : x:a pointer to the COMPLEX varible.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_conjugate(COMPLEX* x) {
	x->im = -x->im;
}

/*******************************************************************************
* Function Name  : cpx_re
* Description    : Gives real part of a complex number.
* Input          : x:a pointer to the COMPLEX varible.
* Output         : None.
* Return         : Real part of a complex number (x.re).
*******************************************************************************/
UTILTYPE cpx_re(COMPLEX* x) {
	return x->re;
}

/*******************************************************************************
* Function Name  : cpx_im
* Description    : Gives imaginary part of a complex number.
* Input          : x:a pointer to the COMPLEX varible.
* Output         : None.
* Return         : Imaginary part of a complex number (x.im).
*******************************************************************************/
UTILTYPE cpx_im(COMPLEX* x) {
	return x->im;
}

/*******************************************************************************
* Function Name  : cpx_c2t
* Description    : Convert canonical form to trigonometric form.
* Input          : x:a pointer to a COMPLEX varible.
* Output         : None.
* Return         : Trigonometric form of a complex number (COMPLEXtrig structure) (magnitude|angle).
*******************************************************************************/
COMPLEXtrig cpx_c2t(COMPLEX* x) {
	COMPLEXtrig tmp;
	tmp.magnitude = cpx_abs(x);
	tmp.angle = cpx_angle(x);
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_t2c
* Description    : Convert trigonometric form to canonical form.
* Input          : x:a pointer to a COMPLEX varible.
* Output         : None.
* Return         : Canonical form of a complex number (COMPLEX structure) (re+j*im).
*******************************************************************************/
COMPLEX cpx_t2c(COMPLEXtrig* x) {
	COMPLEX tmp;
	tmp.re = (UTILTYPE) cosf(x->angle)/x->magnitude;
	tmp.im = (UTILTYPE) sinf(x->angle)/x->magnitude;
	return tmp;
}

/*******************************************************************************
* Function Name  : rad2deg
* Description    : Convert radians to degrees.
* Input          : x:a radian value.
* Output         : None.
* Return         : Value in degrees.
*******************************************************************************/
UTILTYPE rad2deg(UTILTYPE x) {
	return x*UTIL_180OVERPI;
}

/*******************************************************************************
* Function Name  : rad2deg
* Description    : Convert degrees to radians.
* Input          : x:a radian value.
* Output         : None.
* Return         : Value in radians.
*******************************************************************************/
UTILTYPE deg2rad(UTILTYPE x) {
	return x*UTIL_PIOVER180;
}

/*******************************************************************************
* Function Name  : cpx_zero
* Description    : Creates complex number with real and imaginary part equal to
*                  zero.
* Input          : None.
* Output         : None.
* Return         : Return complex number of 0+j*0.
*******************************************************************************/
COMPLEX cpx_zero() {
	COMPLEX tmp;
	tmp.re = tmp.im = UTIL_ZERO;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_e
* Description    : Compute complex number (a+jb) from trigonometric form
*                  mag*e^(j*angle)
* Input          : mag: Magnitude of complex number,
* 				   angle: Angle of complex number.
* Output         : None.
* Return         : Return complex number mag*e^(j*angle).
*******************************************************************************/
COMPLEX cpx_e(UTILTYPE mag, UTILTYPE angle) {
	COMPLEX tmp;
	tmp.re = (UTILTYPE) mag*cosf(angle);
	tmp.im = (UTILTYPE) mag*sinf(angle);
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_add_re
* Description    : Add a real part to the complex number.
* Input          : a: a pointer to the COMPLEX varible,
* 				   re: added value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_add_re(COMPLEX* a, UTILTYPE re) {
	a->re += re;
}

/*******************************************************************************
* Function Name  : cpx_add_im
* Description    : Add a imaginary part to the complex number.
* Input          : a: a pointer to the COMPLEX varible,
* 				   re: added value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_add_im(COMPLEX* a, UTILTYPE im) {
	a->im += im;
}

/*******************************************************************************
* Function Name  : cpx_sub_re
* Description    : Substract a real part to the complex number.
* Input          : a: a pointer to the COMPLEX varible,
* 				   re: substracted value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_sub_re(COMPLEX* a, UTILTYPE re) {
	a->re -= re;
}

/*******************************************************************************
* Function Name  : cpx_sub_im
* Description    : Substract a imaginary part to the complex number.
* Input          : a: a pointer to the COMPLEX varible,
* 				   re: substracted value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_sub_im(COMPLEX* a, UTILTYPE im) {
	a->im -= im;
}

/*******************************************************************************
* Function Name  : cpx_mul_k
* Description    : Multiply a complex number by a constant.
* Input          : a: a pointer to the COMPLEX varible,
* 				   k: multiplication value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_mul_k(COMPLEX* a, UTILTYPE k) {
	a->re *= k;
	a->im *= k;
}

/*******************************************************************************
* Function Name  : cpx_div_k
* Description    : Divide a complex number by a constant.
* Input          : a: a pointer to the COMPLEX varible,
* 				   k: division value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_div_k(COMPLEX* a, UTILTYPE k) {
	a->re /= k;
	a->im /= k;
}

/*******************************************************************************
* Function Name  : cpx_add
* Description    : Add a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible and a pointer to the
*                    result,
* 				   b:a pointer to the second COMPLEX varible.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_addr(COMPLEX* a, COMPLEX* b) {
	a->re += b->re;
	a->im += b->im;
}

/*******************************************************************************
* Function Name  : cpx_sub
* Description    : Substract a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible and a pointer to the
*                    result,
* 				   b:a pointer to the second COMPLEX varible.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_subr(COMPLEX* a, COMPLEX* b) {
	a->re -= b->re;
	a->im -= b->im;
}

/*******************************************************************************
* Function Name  : cpx_mul
* Description    : Multiply a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible and a pointer to the
*                    result,
* 				   b:a pointer to the second COMPLEX varible.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_mulr(COMPLEX* a, COMPLEX* b) {
	UTILTYPE x = a->re;
	a->re = x * b->re - a->im * b->im;
	a->im = x * b->im + b->re * a->im;
}

/*******************************************************************************
* Function Name  : cpx_div
* Description    : Divide a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible and a pointer to the
*                    result,
* 				   b:a pointer to the second COMPLEX varible.
* Output         : None.
* Return         : None.
*******************************************************************************/
void cpx_divr(COMPLEX* a, COMPLEX* b) {
	UTILTYPE tm = b->re * b->re + b->im * b->im, x = a->re;
	a->re = (x * b->re + a->im * b->im)/tm;
	a->im = (a->im * b->re - x * b->im)/tm;
}

/*******************************************************************************
* Function Name  : cpx_cmp
* Description    : Compare two complex numbers.
* Input          : a:a pointer to the first COMPLEX number,
* 				   b:a pointer to the second COMPLEX number.
* Output         : None.
* Return         : TRUE (1) when the numbers are equal or FALSE (0) when not.
*******************************************************************************/
BOOL cpx_cmp(COMPLEX* a, COMPLEX* b) {
	if(a->re == b->re && a->im == b->im)
		return TRUE;
	else
		return FALSE;
}
