/*
 * noise.c
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "noise.h"
#include <stdlib.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : noise_seed
* Description    : Initialize random generator. Should be output from ADC at
* 				   floating input or similar.
* Input          : seed: initialization value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void noise_seed(int seed) {
	srand(seed);
}

/*******************************************************************************
* Function Name  : noise_white
* Description    : Generate white noise when "rand()" returns a random
*                  variable in the range [0, 1] and has good statistical
*                  properties.
*                  (Central Limit Thorem Method)
* Input          : mean: mean value of noise generated,
* 				   variance: variance of noise genereted.
* Output         : None.
* Return         : White noise value.
*******************************************************************************/
NOISETYPE noise_white(NOISETYPE mean, NOISETYPE variance) {
	unsigned i;
	NOISETYPE x = 0;
	for(i = 0; i < N; ++i)
		x += rand();

	/* for randoms in [0,1], mu = 0.5 and var = 1/12 */
	/* adjust X so mu = 0 and var = 1 */

	x -= (NOISETYPE)N/UTIL_TWO;      /* set mean to 0 */
	x *= sqrtf(12/(NOISETYPE)N);     /* adjust variance to 1 */
	return mean + sqrtf(variance)*x;
}
