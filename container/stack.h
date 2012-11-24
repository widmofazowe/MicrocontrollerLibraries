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
/* Exported types ------------------------------------------------------------*/
typedef char STACKTYPE;
typedef struct {
	STACKTYPE* top;
	unsigned int size;
	unsigned int n;
} STACK;
/* Exported constants --------------------------------------------------------*/
#define STACK_USEAUTORESIZING 0
//Increases stack by this value every time its size is exceeded when previuos
//option is set to 1.
#define STACK_STEP 16
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
STACK* stack_create(int size);
void stack_push(STACK* stack, STACKTYPE el);
STACKTYPE stack_pop(STACK* stack);
short int stack_empty(STACK* stack);
void stack_destroy(STACK* stack);
void stack_resize(STACK* stack, unsigned n);
unsigned stack_num(STACK* stack);

#endif /* _H_STACK */
