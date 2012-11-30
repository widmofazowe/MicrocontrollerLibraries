/*
 * dft.h
 *
 *  Created on: Nov 22, 2012
 *      Author: widmo
 *
 *  Notes:
 *  	dft function takes 1.5 more time then dft_both.
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _H_DFT
#define _H_DFT

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "../common/util.h"
#include "../common/complex.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define DEL_ROUND_ERR 0
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void dft(UTILTYPE *aSamples, COMPLEX *spectrum, uint16_t N);
void dft_both(UTILTYPE *aSamples, UTILTYPE *aMagnitude, UTILTYPE *aPhase, uint16_t N);
void dft_mag(UTILTYPE *aSamples, UTILTYPE *aMagnitude, uint16_t N);
void dft_phase(UTILTYPE *aSamples, UTILTYPE *aPhase, uint16_t N);
COMPLEX dft_k(UTILTYPE *aSamples, uint16_t k, uint16_t N);
void dft_both_k(UTILTYPE *aSamples, UTILTYPE* magnitude, UTILTYPE* phase, uint16_t k, uint16_t N);
UTILTYPE dft_mag_k(UTILTYPE *aSamples, uint16_t k, uint16_t N);
UTILTYPE dft_phase_k(UTILTYPE *aSamples, uint16_t k, uint16_t N);

#endif /* _H_DFT */
