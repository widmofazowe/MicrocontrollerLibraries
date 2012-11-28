/*
 * noise.h
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef NOISE_H_
#define NOISE_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/util.h"
/* Exported types ------------------------------------------------------------*/
typedef UTILTYPE NOISETYPE;
/* Exported constants --------------------------------------------------------*/
// recommend N >=20 for good results
#define N 30
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void noise_seed(int seed);
NOISETYPE noise_white(NOISETYPE mean, NOISETYPE variance);


#endif /* NOISE_H_ */
