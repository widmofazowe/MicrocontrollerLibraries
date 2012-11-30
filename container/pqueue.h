/*
 * pqueue.h
 *
 *  Created on: Nov 27, 2012
 *      Author: widmo
 *  Note: priority queue
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PQUEUE_H_
#define PQUEUE_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/types.h"
/* Exported types ------------------------------------------------------------*/
typedef char PQUEUETYPE;
typedef struct {
	unsigned size;
	unsigned read;
	unsigned write;
	PQUEUETYPE* address;
	BOOL (*pfunc)(PQUEUETYPE, PQUEUETYPE);
} PQUEUE;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
PQUEUE* pqueue_create(uint16_t n, BOOL(*f)(PQUEUETYPE, PQUEUETYPE));
void penqueue(PQUEUE* q, PQUEUETYPE x);
PQUEUETYPE pdepqueue(PQUEUE* q);
void pqueue_destroy(PQUEUE* q);
void pqueue_resize(PQUEUE* q, uint16_t n);
unsigned pqueue_num(PQUEUE* q);
BOOL pqueue_empty(PQUEUE* q);

BOOL pqueue_asc(PQUEUETYPE a, PQUEUETYPE b);
BOOL pqueue_desc(PQUEUETYPE a, PQUEUETYPE b);

#endif /* PQUEUE_H_ */
