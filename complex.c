/*
 * complex
 *
 *  Created on: Oct 25, 2012
 *      Author: widmo
 * Description: Complex calculations.
 */

/* Includes ------------------------------------------------------------------*/
#include <math.h>
#include "../Headers/complex.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : cpx
* Description    : Create a complex numbers.
* Input          : a:real part of a COMPLEX number
* 				   b:imaginary part of a COMPLEX number
* Output         : None.
* Return         : COMPLEX variable.
*******************************************************************************/
COMPLEX cpx(CPXTYPE a, CPXTYPE b) {
	COMPLEX tmp;
	tmp.re = a;
	tmp.im = b;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_add
* Description    : Add a complex numbers.
* Input          : a:a pointer to the first COMPLEX varible
* 				   b:a pointer to the second COMPLEX varible
* Output         : None.
* Return         : complex addition of a and b (a+b).
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
* Input          : a:a pointer to the first COMPLEX varible
* 				   b:a pointer to the second COMPLEX varible
* Output         : None.
* Return         : COMPLEX variable of a substraction of a and b (a-b).
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
* Input          : a:a pointer to the first COMPLEX varible
* 				   b:a pointer to the second COMPLEX varible
* Output         : None.
* Return         : COMPLEX variable of a multiplication of a and b (a*b).
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
* Input          : a:a pointer to the first COMPLEX varible
* 				   b:a pointer to the second COMPLEX varible
* Output         : None.
* Return         : COMPLEX variable of a devision of a and b (a/b).
*******************************************************************************/
COMPLEX cpx_div(COMPLEX* a, COMPLEX* b) {
	COMPLEX tmp;
	CPXTYPE tm = b->re * b->re + b->im * b->im;
	cpx_conjugate(b);  //b->im = -b->im;
	tmp.re = (a->re * b->re - a->im * b->im)/tm;
	tmp.im = (a->re * b->im + b->re * a->im)/tm;
	return tmp;
}

/*******************************************************************************
* Function Name  : cpx_abs
* Description    : Calculate magnitude of a complex number.
* Input          : x:a pointer to the COMPLEX varible
* Output         : None.
* Return         : Magnitude of a complex number (sqrt(x.re^2 + x.im^2)).
*******************************************************************************/
inline CPXTYPE cpx_abs(COMPLEX* x) {
	return sqrt(x->re*x->re + x->im*x->im);
}

/*******************************************************************************
* Function Name  : cpx_angle
* Description    : Calculate argument of a complex number.
* Input          : x:a pointer to the COMPLEX varible
* Output         : None.
* Return         : Argument of a complex number in radians (arc tan(x.im/x.re) + [pi when x.re < 0] or - [pi when x.re < 0 and x.im < 0]).
*******************************************************************************/
CPXTYPE cpx_angle(COMPLEX* x) {
	double tmp = atan(x->im/x->re);
	if(x->re < CPX_ZERO)
		if(x->im > CPX_ZERO)
			tmp += M_PI;
		else
			tmp -= M_PI;
	return (CPXTYPE) tmp;
}

/*******************************************************************************
* Function Name  : cpx_cconjugate
* Description    : Gives a complex conjugate of a complex number.
* Input          : x:a pointer to the COMPLEX varible
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
* Input          : x:a pointer to the COMPLEX varible
* Output         : None.
* Return         : None.
*******************************************************************************/
inline void cpx_conjugate(COMPLEX* x) {
	x->im = -x->im;
}

/*******************************************************************************
* Function Name  : cpx_re
* Description    : Gives real part of a complex number.
* Input          : x:a pointer to the COMPLEX varible
* Output         : None.
* Return         : Real part of a complex number (x.re).
*******************************************************************************/
inline CPXTYPE cpx_re(COMPLEX* x) {
	return x->re;
}

/*******************************************************************************
* Function Name  : cpx_im
* Description    : Gives imaginary part of a complex number.
* Input          : x:a pointer to the COMPLEX varible
* Output         : None.
* Return         : Imaginary part of a complex number (x.im).
*******************************************************************************/
inline CPXTYPE cpx_im(COMPLEX* x) {
	return x->im;
}

/*******************************************************************************
* Function Name  : cpx_c2t
* Description    : Convert canonical form to trigonometric form.
* Input          : x:a pointer to a COMPLEX varible
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
* Input          : x:a pointer to a COMPLEX varible
* Output         : None.
* Return         : Canonical form of a complex number (COMPLEX structure) (re+j*im).
*******************************************************************************/
COMPLEX cpx_t2c(COMPLEXtrig* x) {
	COMPLEX tmp;
	tmp.re = cos(x->angle)/x->magnitude;
	tmp.im = sin(x->angle)/x->magnitude;
	return tmp;
}

/*******************************************************************************
* Function Name  : rad2deg
* Description    : Convert radians to degrees.
* Input          : x:a radian value
* Output         : None.
* Return         : Value in degrees.
*******************************************************************************/
inline CPXTYPE rad2deg(CPXTYPE x) {
	return x*CPX_180OVERPI;
}

/*******************************************************************************
* Function Name  : rad2deg
* Description    : Convert degrees to radians.
* Input          : x:a radian value
* Output         : None.
* Return         : Value in radians.
*******************************************************************************/
inline CPXTYPE deg2rad(CPXTYPE x) {
	return x*CPX_PIOVER180;
}

