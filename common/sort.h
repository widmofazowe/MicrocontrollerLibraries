/*
 * sort.h
 *
 *  Created on: Nov 24, 2012
 *      Author: widmo
 *  Note:
 *  	Usage e.q. sort_bubble(tab, 10, sort_type_asc);
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SORT_H_
#define SORT_H_

/* Includes ------------------------------------------------------------------*/
#include "types.h"
/* Exported types ------------------------------------------------------------*/
typedef int SORTEDTYPE;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void sort_bubble(SORTEDTYPE *tab, uint16_t n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE));
void sort_insertion(SORTEDTYPE *tab, uint16_t n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE));
void sort_selection(SORTEDTYPE *tab, uint16_t n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE));
void sort_quick(SORTEDTYPE *tab, uint16_t n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE));
void sort_hybridquick(SORTEDTYPE *tab, uint16_t n, BOOL(*f)(SORTEDTYPE, SORTEDTYPE), void (*sort)(SORTEDTYPE*, uint16_t, BOOL(*f)(SORTEDTYPE, SORTEDTYPE)));

BOOL sort_type_asc(SORTEDTYPE a, SORTEDTYPE b);
BOOL sort_type_desc(SORTEDTYPE a, SORTEDTYPE b);

#endif /* SORT_H_ */
