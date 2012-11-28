/*
 * pqueue.c
 *
 *  Created on: Nov 27, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "pqueue.h"
#include <malloc.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : pqueue_create
* Description    : Create a pqueue (buffer).
* Input          : n: size of pqueue,
* 				   f: a pointer to the function that check priority.
* Output         : None.
* Return         : A pointer to a created pqueue.
*******************************************************************************/
PQUEUE* pqueue_create(unsigned n, BOOL(*f)(PQUEUETYPE, PQUEUETYPE)) {
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
* Description    : Add an element to pqueue (buffer).
* Input          : q: a pointer to the pqueue,
* 				   x: an element which is added.
* Output         : None.
* Return         : None.
*******************************************************************************/
void penqueue(PQUEUE* q, PQUEUETYPE x) {
	if(pqueue_num(q) < q->size) { //check if buffer is full
		int wr = (int)q->write-1;
		int rd = (int)q->read-1;
		if(rd < 0)
			rd += q->size;
		if(q->write >= q->size) {
			q->write = 0;
		}
		if(wr < 0)
			wr += q->size;
		while(q->pfunc(q->address[wr], x) && wr != rd) {
			q->address[(wr+1)%q->size] = q->address[wr];
			if(--wr < 0)
				wr += q->size;
		}
		q->address[(wr+1)%q->size] = x;
		q->write++;
	}
}

/*******************************************************************************
* Function Name  : pdequeue
* Description    : Read an element from pqueue (buffer).
* Input          : q: a pointer to the pqueue.
* Output         : None.
* Return         : Element which is read.
*******************************************************************************/
PQUEUETYPE pdequeue(PQUEUE* q) {
	if(q->read >= q->size) {
		q->read -= q->size;
	}
	return (q->read == q->write) ? NULL : q->address[q->read++];
}

/*******************************************************************************
* Function Name  : pqueue_destroy
* Description    : Destroy pqueue and free memory.
* Input          : q: pointer to the stack.
* Output         : None.
* Return         : None.
*******************************************************************************/
void pqueue_destroy(PQUEUE* q) {
	free(q->address);
	free(q);
}

/*******************************************************************************
* Function Name  : pqueue_resize
* Description    : Resize pqueue.
* Input          : q: a pointer to pqueue,
* 				   n: a new size of pqueue.
* Output         : None.
* Return         : None.
*******************************************************************************/
void pqueue_resize(PQUEUE* q, unsigned n) {
	q->size = n;
	q->address = (PQUEUETYPE*) realloc(q->address, n*sizeof(PQUEUETYPE));
}

/*******************************************************************************
* Function Name  : pqueue_num
* Description    : Calculate number of elements in pqueue.
* Input          : q: a pointer to pqueue.
* Output         : None.
* Return         : Number of elements in pqueue.
*******************************************************************************/
unsigned pqueue_num(PQUEUE* q) {
	if(q->write >= q->read)
		return q->write-q->read;
	else
		return q->size-(q->read-q->write);
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
__inline BOOL pqueue_asc(PQUEUETYPE a, PQUEUETYPE b) {
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
__inline BOOL pqueue_desc(PQUEUETYPE a, PQUEUETYPE b) {
	return (a > b);
}
