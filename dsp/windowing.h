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
#include <stdint.h>
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

void windowing_init(UTILTYPE (*f)(int16_t, int16_t), uint16_t N);
void windowing_free(void);
UTILTYPE rectangular(int16_t n, uint16_t N);
UTILTYPE hanning(int16_t n, uint16_t N);
UTILTYPE hamming(int16_t n, uint16_t N);
UTILTYPE blackman(int16_t n, uint16_t N);
UTILTYPE triangular(int16_t n, uint16_t N);
UTILTYPE cosine(int16_t n, uint16_t N);
UTILTYPE sine(int16_t n, uint16_t N);
UTILTYPE lanczos(int16_t n, uint16_t N);
UTILTYPE gaussian(int16_t n, uint16_t N);
UTILTYPE cauchy(int16_t n, uint16_t N);
UTILTYPE poisson(int16_t n, uint16_t N);
UTILTYPE hann_poisson(int16_t n, uint16_t N);
UTILTYPE bohman(int16_t n, uint16_t N);
UTILTYPE riemann(int16_t n, uint16_t N);
UTILTYPE parabolic(int16_t n, uint16_t N);
//UTILTYPE kaiser_bessel(int n, uint16_t N);

#endif /* WINDOWING_H_ */
