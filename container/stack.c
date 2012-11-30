/*
 * stack.c
 *
 *  Created on: Nov 23, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "stack.h"
#include <stdlib.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : stack_create
* Description    : Create a stack and allocate a memory for it.
* Input          : n: size of a stack at initialization,
* 				   iElementSize: element size.
* Output         : None.
* Return         : A pointer to the stack.
*******************************************************************************/
STACK* stack_create(uint16_t size) {
	STACK* st = (STACK*) malloc(sizeof(STACK));
	st->size = size;
	st->n = 0;
	st->top = (STACKTYPE*) malloc(size*sizeof(STACKTYPE));
	return st;
}

/*******************************************************************************
* Function Name  : stack_push
* Description    : Push an element to the top of a stack.
* Input          : stack: a pointer to the stack,
* 				   el: element.
* Output         : None.
* Return         : None.
*******************************************************************************/
void stack_push(STACK* stack, STACKTYPE el) {
	++stack->n;
#if STACK_USEAUTORESIZING == 1
	if(stack->n > stack->size) {
		stack->size += STACK_STEP;
		stack->top = (STACKTYPE*) realloc(stack->top-stack->n+1, (stack->size)*sizeof(STACKTYPE));
		stack->top += stack->n-1;
	}
#endif
	*(stack->top++) = el;
}

/*******************************************************************************
* Function Name  : stack_pop
* Description    : Pop an element from the top of a stack.
* Input          : stack: a pointer to the stack.
* Output         : None.
* Return         : None.
*******************************************************************************/
STACKTYPE stack_pop(STACK* stack) {
	--stack->n;
	return *(--stack->top);
}

/*******************************************************************************
* Function Name  : stack_empty
* Description    : Check if there is anything in stack.
* Input          : stack: a pointer to the stack.
* Output         : None.
* Return         : 1 when stack is empty, 0 in another situation.
*******************************************************************************/
BOOL stack_empty(STACK* stack) {
	return (stack->n == 0);
}

/*******************************************************************************
* Function Name  : stack_destroy
* Description    : Destroy stack and free memory,
* Input          : stack: pointer to the stack.
* Output         : None.
* Return         : None.
*******************************************************************************/
void stack_destroy(STACK* stack) {
	free(stack->top-stack->n);
	free(stack);
}

/*******************************************************************************
* Function Name  : stack_resize
* Description    : Resize stack.
* Input          : q: a pointer to a stack,
* 				   n: a new size of a stack.
* Output         : None.
* Return         : None.
*******************************************************************************/
void stack_resize(STACK* stack, uint16_t n) {
	stack->size = n;
	stack->top = (STACKTYPE*) realloc(stack->top-stack->n+1, (stack->size)*sizeof(STACKTYPE));
	stack->top += stack->n-1;
}

/*******************************************************************************
* Function Name  : stack_num
* Description    : Calculate number of elements in stack.
* Input          : q: a pointer to stack.
* Output         : None.
* Return         : Number of elements in stack.
*******************************************************************************/
unsigned stack_num(STACK* stack) {
	return stack->n;
}
