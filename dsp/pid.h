/*
 * pid.h
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PID_H_
#define PID_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/util.h"
/* Exported types ------------------------------------------------------------*/
typedef int PIDCONTROLLEDTYPE;
typedef UTILTYPE PIDTYPE;
typedef struct {
	PIDTYPE proportional;
	PIDTYPE integral;
	PIDTYPE derivative;
	PIDTYPE sampling_period;
} PID;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
PIDCONTROLLEDTYPE pid(PIDCONTROLLEDTYPE x, PIDCONTROLLEDTYPE y, PID controller);


#endif /* PID_H_ */
