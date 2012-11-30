/*
 * pid.c
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "pid.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : pid
* Description    : Computes output value of PID controller.
* Input          : x: desired value,
* 				   y: actual value,
* 				   controller: a pointer to the pid controller settings.
* Output         : None.
* Return         : Output of a controller.
*******************************************************************************/
PIDCONTROLLEDTYPE pid(PIDCONTROLLEDTYPE x, PIDCONTROLLEDTYPE y, PID* controller) {
	static PIDCONTROLLEDTYPE pid_output_history = 0;
	static PIDCONTROLLEDTYPE pid_err_history[2] = {0};
	PIDCONTROLLEDTYPE output, err = x-y;
	output = pid_output_history;
	output += (controller->proportional+controller->integral*controller->sampling_period/UTIL_TWO + controller->derivative/controller->sampling_period)*err;
	output += (-controller->proportional+controller->integral*controller->sampling_period/UTIL_TWO - UTIL_TWO*controller->derivative/controller->sampling_period)*(*(pid_err_history));
	output += (controller->derivative/controller->sampling_period)*(*(pid_err_history+1));
	*(pid_err_history+1) = *pid_err_history;
	*(pid_err_history) = err;
	pid_output_history = output;
	return output;
}
