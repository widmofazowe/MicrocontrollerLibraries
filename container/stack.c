/*
 * stack.c
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "stack.h"
#include <malloc.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : stack_create
* Description    : Create a stack and allocate a memory for it.
* Input          : n: size of a stack at initialization
* 				   iElementSize: element size.
* Output         : None.
* Return         : A pointer to the stack.
*******************************************************************************/
STACK* stack_create(int size) {
	STACK* st = (STACK*) malloc(sizeof(STACK));
	st->size = size;
	st->n = 0;
	st->top = (STACKTYPE*) malloc(size*sizeof(STACKTYPE));
	return st;
}

/*******************************************************************************
* Function Name  : stack_push
* Description    : Push an element to the top of a stack.
* Input          : stack: a pointer to the stack
* 				   el: element.
* Output         : None.
* Return         : None.
*******************************************************************************/
void stack_push(STACK* stack, STACKTYPE el) {
	if(++stack->n > stack->size) {
		stack->size += STACK_STEP;
		stack->top = (STACKTYPE*) realloc(stack->top-stack->n+1, (stack->size)*sizeof(STACKTYPE));
		stack->top += stack->n-1;
	}
	*(stack->top++) = el;
}

/*******************************************************************************
* Function Name  : stack_pop
* Description    : Pop an element from the top of a stack.
* Input          : stack: a pointer to the stack
* Output         : None.
* Return         : None.
*******************************************************************************/
STACKTYPE stack_pop(STACK* stack) {
	stack->n--;
	return *(--stack->top);
}

/*******************************************************************************
* Function Name  : stack_empty
* Description    : Check if there is anything in stack.
* Input          : stack: a pointer to the stack
* Output         : None.
* Return         : 1 when stack is empty, 0 in another situation.
*******************************************************************************/
short int stack_empty(STACK* stack) {
	return (stack->n == 0) ? 1 : 0 ;
}

/*******************************************************************************
* Function Name  : stack_destroy
* Description    : Destroy stack and free memory of it.
* Input          : stack: pointer to the stack.
* Output         : None.
* Return         : None.
*******************************************************************************/
void stack_destroy(STACK* stack) {
	free(stack->top-stack->n);
	free(stack);
}
