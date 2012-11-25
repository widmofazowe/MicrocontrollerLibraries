/*
 * windowing.h
 *
 *  Created on: Nov 25, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef WINDOWING_H_
#define WINDOWING_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/util.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define WINDOWING_USEPRECALCULATION 1

#if UTIL_MODE == UTIL_FLOAT_MODE
	#define WINDOWING_HAMMING 0.54f
	#define WINDOWING_BLACKMAN_A0 0.42659f
	#define WINDOWING_BLACKMAN_A1 0.49656f
	#define WINDOWING_BLACKMAN_A2 0.076849f
	#define WINDOWING_GAUSSIAN 2.5f
	#define WINDOWING_CAUCHY 3.0f
	#define WINDOWING_POISSON 1.5f
	#define WINDOWING_HANNPOISSON 0.5f
//from 0 to 4
	#define WINDOWING_KAISERBESSEL 3.0f
#else
	#define WINDOWING_HAMMING 0.54
	#define WINDOWING_BLACKMAN 0.16
	#define WINDOWING_BLACKMAN_A0 0.42659071367
	#define WINDOWING_BLACKMAN_A1 0.49656061909
	#define WINDOWING_BLACKMAN_A2 0.07684866724
	#define WINDOWING_GAUSSIAN 2.5
	#define WINDOWING_CAUCHY 3.0
	#define WINDOWING_POISSON 1.5
	#define WINDOWING_HANNPOISSON 0.5
//from 0 to 4
	#define WINDOWING_KAISERBESSEL 3.0
#endif
#define WINDOWING_COSINE 1


/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void windowing_init(UTILTYPE (*f)(int, int), unsigned N);
void windowing_free();
UTILTYPE rectangular(int n, unsigned N);
UTILTYPE hanning(int n, unsigned N);
UTILTYPE hamming(int n, unsigned N);
UTILTYPE blackman(int n, unsigned N);
UTILTYPE triangular(int n, unsigned N);
UTILTYPE cosine(int n, unsigned N);
UTILTYPE sine(int n, unsigned N);
UTILTYPE lanczos(int n, unsigned N);
UTILTYPE gaussian(int n, unsigned N);
UTILTYPE cauchy(int n, unsigned N);
UTILTYPE poisson(int n, unsigned N);
UTILTYPE hann_poisson(int n, unsigned N);
UTILTYPE bohman(int n, unsigned N);
UTILTYPE riemann(int n, unsigned N);
UTILTYPE parabolic(int n, unsigned N);
//UTILTYPE kaiser_bessel(int n, unsigned N);

#endif /* WINDOWING_H_ */
