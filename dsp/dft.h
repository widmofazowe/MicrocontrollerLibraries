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
#include "../complex.h"
#include <>math.h>
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define DEL_ROUND_ERR 0
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void dft(CPXTYPE aSamples[], COMPLEX spectrum[], unsigned int iPoints);
void dft_both(CPXTYPE aSamples[], CPXTYPE aMagnitude[], CPXTYPE aPhase[], unsigned int iPoints);
void dft_mag(CPXTYPE aSamples[], CPXTYPE aMagnitude[], unsigned int iPoints);
void dft_phase(CPXTYPE aSamples[], CPXTYPE aMagnitude[], unsigned int iPoints);
void dft_both_k(CPXTYPE aSamples[], CPXTYPE aMagnitude[], CPXTYPE aPhase[], unsigned int k, unsigned int iPoints);
CPXTYPE dft_mag_k(CPXTYPE aSamples[], unsigned int k, unsigned int iPoints);
CPXTYPE dft_phase_k(CPXTYPE aSamples[], unsigned int k, unsigned int iPoints);
#endif /* _H_DFT */
