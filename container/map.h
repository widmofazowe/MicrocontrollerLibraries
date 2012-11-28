/*
 * map.h
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MAP_H_
#define MAP_H_

/* Includes ------------------------------------------------------------------*/
#include "../common/util.h"
/* Exported types ------------------------------------------------------------*/
typedef char MAPTYPE;
typedef char MAPKEY;
typedef struct {
	MAPKEY key;
	MAPTYPE value;
	BOOL active;
} MAP_ELEMENT;
typedef struct {
	unsigned size;
	MAP_ELEMENT* elements;
} MAP;

/* Exported constants --------------------------------------------------------*/
#define MAP_USEAUTORESIZING 1
//Increases stack by this value every time its size is exceeded when previuos
//option is set to 1.
#define MAP_STEP 16
/* Exported macro ------------------------------------------------------------*/
//function which compares keys (for a string key it should be !strcmp(x, y)
#define MAP_CMP(x, y) (x == y)
/* Exported functions ------------------------------------------------------- */
MAP* map_create(unsigned n);
void map_set(MAP* map, MAPKEY i, MAPTYPE x);
void map_erase(MAP* map, MAPKEY key);
MAPTYPE map_get(MAP* map, MAPKEY i);
BOOL map_isset(MAP* map, MAPKEY i);
void map_destroy(MAP* map);
void map_resize(MAP* map, unsigned n);

#endif /* MAP_H_ */
