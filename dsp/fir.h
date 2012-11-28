/*
 * fir.h
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FIR_H_
#define FIR_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/util.h"
/* Exported types ------------------------------------------------------------*/
typedef UTILTYPE FIRTYPE;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void fir_init(FIRTYPE *coeff, unsigned n);
void fir_free();
void fit_clear_input();
FIRTYPE fir(FIRTYPE sample);

#endif /* FIR_H_ */
