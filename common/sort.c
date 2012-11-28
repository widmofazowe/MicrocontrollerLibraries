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
void sort_bubble(SORTEDTYPE tab[], unsigned n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE)) {
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
void sort_insertion(SORTEDTYPE tab[], unsigned n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE)) {
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
void sort_selection(SORTEDTYPE tab[], unsigned n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE)) {
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
* Function Name  : sort_quick
* Description    : Sort table using quick sort algorithm.
* Input          : tab: table which will be sorted,
* 				   n: number of elements in table,
* 				   f: pointer to the function with sorting comparison.
* Output         : None.
* Return         : None.
*******************************************************************************/
void sort_quick(SORTEDTYPE *tab, int n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE)) {
	SORTEDTYPE x = tab[n/2], tmp;
	int i = 0, j = n - 1;
	if(n == 1)
		return;
	do {
		while(f(tab[i], x)) i++;
		while(f(x, tab[j])) j--;
		if(i <= j) {
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			i++;
			j--;
		}
	} while(i < j);
	if (0 < j) sort_quick(&tab[0], j + 1, f);
	if (n > i) sort_quick(&tab[i], n - i, f);
}

/*******************************************************************************
* Function Name  : sort_hybridquick
* Description    : Sort table using hybrid quick sort algorithm with help
*                  algorithm.
* Input          : tab: table which will be sorted,
* 				   n: number of elements in table,
* 				   f: pointer to the function with sorting comparison.
* Output         : None.
* Return         : None.
*******************************************************************************/
void sort_hybridquick(SORTEDTYPE *tab, int n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE), void (*sort)(SORTEDTYPE*, int, BOOL(*f)(SORTEDTYPE, SORTEDTYPE))) {
	SORTEDTYPE x = tab[n/2], tmp;
	int i = 0, j = n - 1;
	if (n > 10) {
		do {
			while(f(tab[i], x)) i++;
			while(f(x, tab[j])) j--;
			if(i <= j) {
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				i++;
				j--;
			}
		} while(i < j);
		if (0 < j) sort_quick(&tab[0], j + 1, f);
		if (n > i) sort_quick(&tab[i], n - i, f);
	} else {
		sort(tab, n, f);
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
__inline BOOL sort_type_asc(SORTEDTYPE a, SORTEDTYPE b) {
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
__inline BOOL sort_type_desc(SORTEDTYPE a, SORTEDTYPE b) {
	return (a > b);
}
