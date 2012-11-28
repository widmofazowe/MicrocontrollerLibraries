/*
 * vector.c
 *
 *  Created on: Nov 27, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "vector.h"
#include <malloc.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : vector_create
* Description    : Create a vector (buffer).
* Input          : n: size of vector.
* Output         : None.
* Return         : A pointer to a created vector.
*******************************************************************************/
VECTOR* vector_create(unsigned n) {
	VECTOR* q;
	q = (VECTOR*) malloc(sizeof(VECTOR));
	q->size = n;
	q->address = (VECTORTYPE*) malloc(n*sizeof(VECTORTYPE));
	return q;
}

/*******************************************************************************
* Function Name  : vector_set
* Description    : Add an element to vector (buffer).
* Input          : q: a pointer to the vector,
* 				   x: an element which is added.
* Output         : None.
* Return         : None.
*******************************************************************************/
void vector_set(VECTOR* q, unsigned i, VECTORTYPE x) {
#if VECTOR_USEAUTORESIZING == 1
	if(i >= q->size) {
		q->size += VECTOR_STEP;
		q->address = (VECTORTYPE*) realloc(q->address, (q->size)*sizeof(VECTORTYPE));
	}
#endif
	*(q->address+i) = x;
}

/*******************************************************************************
* Function Name  : vector_get
* Description    : Read an element from vector (buffer).
* Input          : q: a pointer to the vector.
* Output         : None.
* Return         : Element which is read.
*******************************************************************************/
VECTORTYPE vector_get(VECTOR* q, unsigned i) {
	return *(q->address+i);
}

/*******************************************************************************
* Function Name  : vector_destroy
* Description    : Destroy vector and free memory.
* Input          : q: pointer to the vector.
* Output         : None.
* Return         : None.
*******************************************************************************/
void vector_destroy(VECTOR* q) {
	free(q->address);
	free(q);
}

/*******************************************************************************
* Function Name  : vector_resize
* Description    : Resize vector.
* Input          : q: a pointer to vector,
* 				   n: a new size of vector.
* Output         : None.
* Return         : None.
*******************************************************************************/
void vector_resize(VECTOR* q, unsigned n) {
	q->size = n;
	q->address = (VECTORTYPE*) realloc(q->address, n*sizeof(VECTORTYPE));
}

/*******************************************************************************
* Function Name  : vector_fill
* Description    : Fill vector with given value.
* Input          : q: a pointer to vector,
* 				   x: value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void vector_fill(VECTOR* q, VECTORTYPE x) {
	unsigned i;
	for(i = 0; i < q->size; ++i)
		*(q->address+i) = x;
}
