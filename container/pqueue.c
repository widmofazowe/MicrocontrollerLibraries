/*
 * pqueue.c
 *
 *  Created on: Nov 27, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "pqueue.h"
#include <stdlib.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : pqueue_create
* Description    : Create a priority queue (buffer).
* Input          : n: size of priority queue,
* 				   f: a pointer to the function that check priority.
* Output         : None.
* Return         : A pointer to a created priority queue.
*******************************************************************************/
PQUEUE* pqueue_create(uint16_t n, BOOL(*f)(PQUEUETYPE, PQUEUETYPE)) {
	PQUEUE* q;
	q = (PQUEUE*) malloc(sizeof(PQUEUE));
	q->size = n;
	q->pfunc = f;
	q->address = (PQUEUETYPE*) malloc(n*sizeof(PQUEUETYPE));
	q->write = q->read = 0;
	return q;
}

/*******************************************************************************
* Function Name  : penqueue
* Description    : Add an element to priority queue (buffer).
* Input          : q: a pointer to the priority queue,
* 				   x: an element which is added.
* Output         : None.
* Return         : None.
*******************************************************************************/
void penqueue(PQUEUE* q, PQUEUETYPE x) {
	if(pqueue_num(q) < q->size) { //check if buffer is full
		int16_t wr = (int16_t)q->write-1;
		int16_t rd = (int16_t)q->read-1;
		if(rd < 0)
			rd += q->size;
		if(q->write >= q->size) {
			q->write = 0;
		}
		if(wr < 0)
			wr += q->size;
		while(q->pfunc(*(q->address+wr), x) && wr != rd) {
			*(q->address+((wr+1)%q->size)) = *(q->address+wr);
			if(--wr < 0)
				wr += q->size;
		}
		*(q->address+((wr+1)%q->size)) = x;
		q->write++;
	}
}

/*******************************************************************************
* Function Name  : pdequeue
* Description    : Read an element from priority queue (buffer).
* Input          : q: a pointer to the priority queue.
* Output         : None.
* Return         : Element which is read.
*******************************************************************************/
PQUEUETYPE pdequeue(PQUEUE* q) {
	if(q->read >= q->size) {
		q->read -= q->size;
	}

	return *(q->address+(q->read++));
}

/*******************************************************************************
* Function Name  : pqueue_destroy
* Description    : Destroy priority queue and free memory.
* Input          : q: pointer to the priority queue.
* Output         : None.
* Return         : None.
*******************************************************************************/
void pqueue_destroy(PQUEUE* q) {
	free(q->address);
	free(q);
}

/*******************************************************************************
* Function Name  : pqueue_resize
* Description    : Resize priority queue.
* Input          : q: a pointer to priority queue,
* 				   n: a new size of priority queue.
* Output         : None.
* Return         : None.
*******************************************************************************/
void pqueue_resize(PQUEUE* q, uint16_t n) {
	q->size = n;
	q->address = (PQUEUETYPE*) realloc(q->address, n*sizeof(PQUEUETYPE));
}

/*******************************************************************************
* Function Name  : pqueue_num
* Description    : Calculate number of elements in priority queue.
* Input          : q: a pointer to priority queue.
* Output         : None.
* Return         : Number of elements in priority queue.
*******************************************************************************/
unsigned pqueue_num(PQUEUE* q) {
	if(q->write >= q->read)
		return q->write-q->read;
	else
		return q->size-(q->read-q->write);
}

/*******************************************************************************
* Function Name  : pqueue_empty
* Description    : Return TRUE when priority queue is empty.
* Input          : q: a pointer to priority queue.
* Output         : None.
* Return         : TRUE when priority queue is empty, FALSE in otherwise.
*******************************************************************************/
BOOL pqueue_empty(PQUEUE* q) {
	return(q->read == q->write) ? TRUE : FALSE;
}

/*******************************************************************************
* Function Name  : pqueue_asc
* Description    : Compare two elements and return 1 when the element a is less
* 				   then element b.
* Input          : a: first compared element,
* 				   b: second compared element.
* Output         : None.
* Return         : Return 1 when the element a is less then element b.
* 				   0 - otherwise.
*******************************************************************************/
BOOL pqueue_asc(PQUEUETYPE a, PQUEUETYPE b) {
	return (a < b);
}

/*******************************************************************************
* Function Name  : pqueue_desc
* Description    : Compare two elements and return 1 when the element a is
* 				   greater then element b.
* Input          : a: first compared element,
* 				   b: second compared element.
* Output         : None.
* Return         : Return 1 when the element a is greater then element b.
* 				   0 - otherwise.
*******************************************************************************/
BOOL pqueue_desc(PQUEUETYPE a, PQUEUETYPE b) {
	return (a > b);
}
