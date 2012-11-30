/*
 * queue.h
 *
 *  Created on: Nov 24, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef QUEUE_H_
#define QUEUE_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/types.h"
/* Exported types ------------------------------------------------------------*/
typedef char QUEUETYPE;
typedef struct {
	uint16_t size;
	uint16_t read;
	uint16_t write;
	QUEUETYPE* address;
} QUEUE;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
QUEUE* queue_create(uint16_t n);
void enqueue(QUEUE* q, QUEUETYPE x);
QUEUETYPE dequeue(QUEUE* q);
void queue_destroy(QUEUE* q);
void queue_resize(QUEUE* q, uint16_t n);
unsigned queue_num(QUEUE* q);
BOOL queue_empty(QUEUE* q);
#endif /* QUEUE_H_ */
