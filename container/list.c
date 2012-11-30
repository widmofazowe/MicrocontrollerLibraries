/*
 * list.c
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "list.h"
#include <stdlib.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : list_create
* Description    : Create a list.
* Input          : x: first element of a list.
* Output         : None.
* Return         : A pointer to a created vector.
*******************************************************************************/
LIST* list_create(LISTTYPE x) {
	LIST* l;
	l = (LIST*) malloc(sizeof(LIST));
	l->previous = l->next = NULL;
	l->element = x;
	return l;
}

/*******************************************************************************
* Function Name  : list_destroy
* Description    : Destroy list and free memory.
* Input          : l: pointer to the list.
* Output         : None.
* Return         : None.
*******************************************************************************/
void list_destroy(LIST* l) {
	LIST* node, *t;
	node = l->next;
	while(node != NULL) {
		t = node->next;
		free(node);
		node = t;
	}
	free(l);
}

/*******************************************************************************
* Function Name  : list_pushback
* Description    : Add list element at the end.
* Input          : l: pointer to the list,
* 				   x: pushed element.
* Output         : None.
* Return         : None.
*******************************************************************************/
void list_pushback(LIST* l, LISTTYPE x) {
	LIST* last = l, *t = NULL;  //t - element before the last (to set previous pointer)
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = list_create(x);
	t = last->next;
	t->previous = last;
}

/*******************************************************************************
* Function Name  : list_popback
* Description    : Remove list element at the end and return its value.
* Input          : l: pointer to the list..
* Output         : None.
* Return         : Popped element.
*******************************************************************************/
LISTTYPE list_popback(LIST* l) {
	LIST* last = l, *t = l;
	LISTTYPE ans;
	while(last->next != NULL) {
		t = last;
		last = last->next;
	}
	ans = last->element;
	t->next = NULL;
	free(last);
	return ans;
}
