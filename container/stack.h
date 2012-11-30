/*
 * stack.h
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 *
 *  Note: No checking if stack is empty
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _H_STACK
#define _H_STACK

/* Includes ------------------------------------------------------------------*/
#include "../common/types.h"
/* Exported types ------------------------------------------------------------*/
typedef char STACKTYPE;
typedef struct {
	STACKTYPE* top;
	uint16_t size;
	uint16_t n;
} STACK;
/* Exported constants --------------------------------------------------------*/
#define STACK_USEAUTORESIZING 0
//Increases stack by this value every time its size is exceeded when previuos
//option is set to 1.
#define STACK_STEP 16
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
STACK* stack_create(uint16_t size);
void stack_push(STACK* stack, STACKTYPE el);
STACKTYPE stack_pop(STACK* stack);
BOOL stack_empty(STACK* stack);
void stack_destroy(STACK* stack);
void stack_resize(STACK* stack, uint16_t n);
unsigned stack_num(STACK* stack);

#endif /* _H_STACK */
