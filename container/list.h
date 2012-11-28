/*
 * list.h
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 *  Note: bidirectional list
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LIST_H_
#define LIST_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/types.h"
/* Exported types ------------------------------------------------------------*/
typedef char LISTTYPE;
typedef struct _LIST {
	LISTTYPE element;
	struct _LIST* next;
	struct _LIST* previous;
} LIST;
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
LIST* list_create(LISTTYPE x);
void list_destroy(LIST* l);
void list_pushback(LIST* l, LISTTYPE x);
LISTTYPE list_popback(LIST* l);

#endif /* LIST_H_ */
