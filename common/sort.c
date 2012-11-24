/*
 * sort.c
 *
 *  Created on: Nov 24, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "sort.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : sort_bubble
* Description    : Sort table using bubble algorithm.
* Input          : tab: table which will be sorted,
* 				   n: number of elements in table,
* 				   f: pointer to the function with sorting comparison.
* Output         : None.
* Return         : None.
*******************************************************************************/
void sort_bubble(SORTEDTYPE tab[], unsigned n, short(*f)(SORTEDTYPE a, SORTEDTYPE b)) {
	unsigned i, j;
	SORTEDTYPE tmp;
	n--;
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n-i; ++j) {
			if(f(tab[j+1], tab[j])) {
				//swap
				tmp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = tmp;
			}
		}
	}
}

/*******************************************************************************
* Function Name  : sort_insertion
* Description    : Sort table using insertion algorithm.
* Input          : tab: table which will be sorted,
* 				   n: number of elements in table,
* 				   f: pointer to the function with sorting comparison.
* Output         : None.
* Return         : None.
*******************************************************************************/
void sort_insertion(SORTEDTYPE tab[], unsigned n, short(*f)(SORTEDTYPE a, SORTEDTYPE b)) {
	unsigned i, j;
	SORTEDTYPE tmp;
	for (i = 1; i < n; ++i) {
		j = i;
		tmp = tab[i];
		while(f(tmp, tab[j-1]) && (j > 0)) {
			tab[j] = tab[j-1];
			j--;
		}
		tab[j] = tmp;
	}
}

/*******************************************************************************
* Function Name  : sort_selection
* Description    : Sort table using selection algorithm.
* Input          : tab: table which will be sorted,
* 				   n: number of elements in table,
* 				   f: pointer to the function with sorting comparison.
* Output         : None.
* Return         : None.
*******************************************************************************/
void sort_selection(SORTEDTYPE tab[], unsigned n, short(*f)(SORTEDTYPE a, SORTEDTYPE b)) {
	unsigned i, j, min = 0;
	SORTEDTYPE tmp;
	for (i = 0; i < n-1; ++i) {
		for(min = i, j = i+1; j < n; ++j) {
			if(f(tab[j], tab[min])) {
				min = j;
			}
		}
		//swap
		tmp = tab[i];
		tab[i] = tab[min];
		tab[min] = tmp;
	}
}


/*******************************************************************************
* Function Name  : sort_type_asc
* Description    : Compare two elements and return 1 when the element a is less
* 				   then element b.
* Input          : a: first compared element,
* 				   b: second compared element.
* Output         : None.
* Return         : Return 1 when the element a is less then element b.
* 				   0 - otherwise.
*******************************************************************************/
__inline short sort_type_asc(SORTEDTYPE a, SORTEDTYPE b) {
	return (a < b);
}

/*******************************************************************************
* Function Name  : sort_type_desc
* Description    : Compare two elements and return 1 when the element a is
* 				   greater then element b.
* Input          : a: first compared element,
* 				   b: second compared element.
* Output         : None.
* Return         : Return 1 when the element a is greater then element b.
* 				   0 - otherwise.
*******************************************************************************/
__inline short sort_type_desc(SORTEDTYPE a, SORTEDTYPE b) {
	return (a > b);
}
