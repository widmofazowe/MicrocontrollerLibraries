/*
 * vector.h
 *
 *  Created on: Nov 27, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef VECTOR_H_
#define VECTOR_H_

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef char VECTORTYPE;
typedef struct {
	unsigned size;
	VECTORTYPE* address;
} VECTOR;

/* Exported constants --------------------------------------------------------*/
#define VECTOR_USEAUTORESIZING 1
//Increases stack by this value every time its size is exceeded when previuos
//option is set to 1.
#define VECTOR_STEP 16
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
VECTOR* vector_create(unsigned n);
void vector_set(VECTOR* q, unsigned i, VECTORTYPE x);
VECTORTYPE vector_get(VECTOR* q, unsigned i);
void vector_destroy(VECTOR* q);
void vector_resize(VECTOR* q, unsigned n);
void vector_fill(VECTOR* q, VECTORTYPE x);
#endif /* VECTOR_H_ */
