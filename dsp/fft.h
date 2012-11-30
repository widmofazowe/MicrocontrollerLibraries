/*
 * fft.h
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 *  Notes:
 *  	DFT computes in 27.882 (dft_both function), 41.823 (dft function).
 *  	FFT computes in 0.025 (fft function)
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FFT_H_
#define FFT_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/util.h"
#include "../common/complex.h"
#include <stdint.h>
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define FFT_USEPRECALCULATION 1
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void fft_init(uint16_t N);
void fft_free(void);
void fft(UTILTYPE *samples, COMPLEX *spectrum, uint16_t N);

#endif /* FFT_H_ */
