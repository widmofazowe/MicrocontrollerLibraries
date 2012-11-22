/*
 * dft.h
 *
 *  Created on: Nov 22, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _H_DFT
#define _H_DFT

/* Includes ------------------------------------------------------------------*/
#include "complex.h"
#include "math.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void dft_both(CPXTYPE aSamples[], CPXTYPE aMagnitude[], CPXTYPE aPhase[], short unsigned int iPoints);
void dft_mag(CPXTYPE aSamples[], CPXTYPE aMagnitude[], short unsigned int iPoints);
void dft_phase(CPXTYPE aSamples[], CPXTYPE aMagnitude[], short unsigned int iPoints);

#endif /* _H_DFT */
