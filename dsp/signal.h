/*
 * signal.h
 *
 *  Created on: Nov 29, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SIGNAL_H_
#define SIGNAL_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/util.h"
#include <stdint.h>
/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef struct {
	uint16_t fs;
	uint16_t n;
	UTILTYPE *samples;	
} SIGNAL;
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
SIGNAL* signal_createTestSignal(uint16_t f, uint16_t fs, uint16_t N);
void signal_free(SIGNAL *s);
#endif /* SIGNAL_H_ */

