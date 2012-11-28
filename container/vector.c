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
* Description    : Create a vector.
* Input          : n: size of vector.
* Output         : None.
* Return         : A pointer to a created vector.
*******************************************************************************/
VECTOR* vector_create(unsigned n) {
	VECTOR* vector;
	vector = (VECTOR*) malloc(sizeof(VECTOR));
	vector->size = n;
	vector->address = (VECTORTYPE*) malloc(n*sizeof(VECTORTYPE));
	return vector;
}

/*******************************************************************************
* Function Name  : vector_set
* Description    : Add an element to vector.
* Input          : vector: a pointer to the vector,
* 				   x: an element which is added.
* Output         : None.
* Return         : None.
*******************************************************************************/
void vector_set(VECTOR* vector, unsigned i, VECTORTYPE x) {
#if VECTOR_USEAUTORESIZING == 1
	if(i >= vector->size) {
		vector->size += VECTOR_STEP;
		vector->address = (VECTORTYPE*) realloc(vector->address, (vector->size)*sizeof(VECTORTYPE));
	}
#endif
	*(vector->address+i) = x;
}

/*******************************************************************************
* Function Name  : vector_get
* Description    : Read an element from vector.
* Input          : vector: a pointer to the vector.
* Output         : None.
* Return         : Element which is read.
*******************************************************************************/
VECTORTYPE vector_get(VECTOR* vector, unsigned i) {
	return *(vector->address+i);
}

/*******************************************************************************
* Function Name  : vector_destroy
* Description    : Destroy vector and free memory.
* Input          : vector: pointer to the vector.
* Output         : None.
* Return         : None.
*******************************************************************************/
void vector_destroy(VECTOR* vector) {
	free(vector->address);
	free(vector);
}

/*******************************************************************************
* Function Name  : vector_resize
* Description    : Resize vector.
* Input          : vector: a pointer to vector,
* 				   n: a new size of vector.
* Output         : None.
* Return         : None.
*******************************************************************************/
void vector_resize(VECTOR* vector, unsigned n) {
	vector->size = n;
	vector->address = (VECTORTYPE*) realloc(vector->address, n*sizeof(VECTORTYPE));
}

/*******************************************************************************
* Function Name  : vector_fill
* Description    : Fill vector with given value.
* Input          : vector: a pointer to vector,
* 				   x: value.
* Output         : None.
* Return         : None.
*******************************************************************************/
void vector_fill(VECTOR* vector, VECTORTYPE x) {
	unsigned i;
	for(i = 0; i < vector->size; ++i)
		*(vector->address+i) = x;
}
