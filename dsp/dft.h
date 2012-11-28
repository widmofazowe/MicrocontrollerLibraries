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
#include "../common/util.h"
#include "../common/complex.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define DEL_ROUND_ERR 0
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void dft(UTILTYPE *aSamples, COMPLEX *spectrum, unsigned int N);
void dft_both(UTILTYPE *aSamples, UTILTYPE *aMagnitude, UTILTYPE *aPhase, unsigned int N);
void dft_mag(UTILTYPE *aSamples, UTILTYPE *aMagnitude, unsigned int N);
void dft_phase(UTILTYPE *aSamples, UTILTYPE *aPhase, unsigned int N);
COMPLEX dft_k(UTILTYPE *aSamples, unsigned k, unsigned N);
void dft_both_k(UTILTYPE *aSamples, UTILTYPE* magnitude, UTILTYPE* phase, unsigned k, unsigned N);
UTILTYPE dft_mag_k(UTILTYPE *aSamples, unsigned k, unsigned N);
UTILTYPE dft_phase_k(UTILTYPE *aSamples, unsigned k, unsigned N);

#endif /* _H_DFT */
