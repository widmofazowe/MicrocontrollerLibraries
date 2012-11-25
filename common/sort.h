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

/* Exported types ------------------------------------------------------------*/
typedef int SORTEDTYPE;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void sort_bubble(SORTEDTYPE tab[], unsigned n, short(*f)(SORTEDTYPE, SORTEDTYPE));
void sort_insertion(SORTEDTYPE tab[], unsigned n, short(*f)(SORTEDTYPE, SORTEDTYPE));
void sort_selection(SORTEDTYPE tab[], unsigned n, short(*f)(SORTEDTYPE, SORTEDTYPE));
void sort_quick(SORTEDTYPE *tab, int n, short(*f)(SORTEDTYPE, SORTEDTYPE));
void sort_hybridquick(SORTEDTYPE *tab, int n, short(*f)(SORTEDTYPE, SORTEDTYPE), void (*sort)(SORTEDTYPE*, int, short(*f)(SORTEDTYPE, SORTEDTYPE)));

__inline short sort_type_asc(SORTEDTYPE a, SORTEDTYPE b);
__inline short sort_type_desc(SORTEDTYPE a, SORTEDTYPE b);

#endif /* SORT_H_ */
