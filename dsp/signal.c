/*
 * signal.c
 *
 *  Created on: Nov 29, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "signal.h"
#include <math.h>
#include <stdlib.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/*******************************************************************************
* Function Name  : signal_createTestSignal
* Description    : Generate sinusoidal test signal.
* Input          : f: desired frequency of a signal,
*				   fs: sampling frequency,
*				   N: number of samples.
* Output         : None.
* Return         : SIGNAL structure with generated samples at given frequency.
*******************************************************************************/
SIGNAL* signal_createTestSignal(uint16_t f, uint16_t fs, uint16_t N) {
	SIGNAL *s;
	uint16_t n;
	s = (SIGNAL*) malloc(sizeof(SIGNAL));
	s->n = N;
	s->fs = fs;
	s->samples = (UTILTYPE*)malloc(N*sizeof(UTILTYPE));
	for(n = 0; n < N; ++n) {
		*(s->samples+n)	= cosf(M_TWOPI*f*n/N);
	}
	return s;		
}

/*******************************************************************************
* Function Name  : signal_free
* Description    : Free memory.
* Input          : s: a pointer to the SIGNAL.
* Output         : None.
* Return         : None.
*******************************************************************************/
void signal_free(SIGNAL *s) {
	free((void*)s->samples);
	free((void*)s);
}
