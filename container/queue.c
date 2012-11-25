/*
 * queue.c
 *
 *  Created on: Nov 24, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "queue.h"
#include <malloc.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : queue_create
* Description    : Create a queue (buffer).
* Input          : n: size of queue.
* Output         : None.
* Return         : A pointer to a created queue.
*******************************************************************************/
QUEUE* queue_create(unsigned n) {
	QUEUE* q;
	q = (QUEUE*) malloc(sizeof(QUEUE));
	q->size = n;
	q->address = (QUEUETYPE*) malloc(n*sizeof(QUEUETYPE));
	q->write = q->read = 0;
	return q;
}

/*******************************************************************************
* Function Name  : enqueue
* Description    : Add an element to queue (buffer).
* Input          : q: a pointer to the queue,
* 				   x: an element which is added.
* Output         : None.
* Return         : None.
*******************************************************************************/
void enqueue(QUEUE* q, QUEUETYPE x) {
	if(q->write > q->size-1) {
		q->write = 0;
	}
	*(q->address+q->write++) = x;
}

/*******************************************************************************
* Function Name  : dequeue
* Description    : Read an element from queue (buffer).
* Input          : q: a pointer to the queue.
* Output         : None.
* Return         : Element which is read.
*******************************************************************************/
QUEUETYPE dequeue(QUEUE* q) {
	if(q->read > q->size-1) {
		q->read = 0;
	}
	return *(q->address+q->read++);
}

/*******************************************************************************
* Function Name  : queue_destroy
* Description    : Destroy queue and free memory.
* Input          : q: pointer to the stack.
* Output         : None.
* Return         : None.
*******************************************************************************/
void queue_destroy(QUEUE* q) {
	free(q->address);
	free(q);
}

/*******************************************************************************
* Function Name  : queue_resize
* Description    : Resize queue.
* Input          : q: a pointer to queue,
* 				   n: a new size of queue.
* Output         : None.
* Return         : None.
*******************************************************************************/
void queue_resize(QUEUE* q, unsigned n) {
	q->size = n;
	q->address = (QUEUETYPE*) realloc(q->address, n*sizeof(QUEUETYPE));
}

/*******************************************************************************
* Function Name  : queue_num
* Description    : Calculate number of elements in queue.
* Input          : q: a pointer to queue.
* Output         : None.
* Return         : Number of elements in queue.
*******************************************************************************/
unsigned queue_num(QUEUE* q) {
	if(q->write >= q->read)
		return q->write-q->read;
	else
		return q->size-(q->read-q->write);
}
