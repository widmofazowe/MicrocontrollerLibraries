/*
 * map.c
 *
 *  Created on: Nov 28, 2012
 *      Author: widmo
 */
/* Includes ------------------------------------------------------------------*/
#include "map.h"
#include <malloc.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : _map_index
* Description    : Search for an index of element with key 'key'.
* Input          : map: a pointer to map,
* 				   key: search key.
* Output         : None.
* Return         : Index in table.
*******************************************************************************/
unsigned _map_index(MAP* map, MAPKEY key) {
	unsigned i;
	for(i = 0; i < map->size; ++i) {
		if(MAP_CMP(key, (map->elements+i)->key))
			break;
	}
	return i;
}

/*******************************************************************************
* Function Name  : _map_firstempty
* Description    : Search for an index of the first element which is empty.
* Input          : map: a pointer to map.
* Output         : None.
* Return         : Index in table.
*******************************************************************************/
unsigned _map_firstempty(MAP* map) {
	unsigned i;
	for(i = 0; i < map->size; ++i) {
		if((map->elements+i)->active == FALSE)
			break;
	}
	return i;
}

/*******************************************************************************
* Function Name  : map_create
* Description    : Create a map.
* Input          : n: size of map.
* Output         : None.
* Return         : A pointer to a created map.
*******************************************************************************/
MAP* map_create(unsigned n) {
	MAP* map;
	map = (MAP*) malloc(sizeof(MAP));
	map->size = n;
	map->elements = (MAP_ELEMENT*) calloc(n, sizeof(MAP_ELEMENT));
	return map;
}

/*******************************************************************************
* Function Name  : map_set
* Description    : Add an element to map.
* Input          : map: a pointer to the map,
* 				   x: an element which is added.
* Output         : None.
* Return         : None.
*******************************************************************************/
void map_set(MAP* map, MAPKEY key, MAPTYPE x) {
	unsigned i;

	if((i=_map_index(map, key)) != map->size) {
		(map->elements+i)->value = x;
	} else if((i=_map_firstempty(map)) != map->size) {
		(map->elements+i)->value = x;
		(map->elements+i)->key = key;
		(map->elements+i)->active = TRUE;
	} else {
#if MAP_USEAUTORESIZING == 1
		i = map->size;
		map->size += MAP_STEP;
		map->elements = (MAP_ELEMENT*) realloc(map->elements, (map->size)*sizeof(MAPTYPE));
		(map->elements+i)->value = x;
		(map->elements+i)->key = key;
		(map->elements+i)->active = TRUE;
#endif
	}
}

/*******************************************************************************
* Function Name  : map_erase
* Description    : Erase an element from map.
* Input          : map: a pointer to the map,
* 				   key: key where element is being erased.
* Output         : None.
* Return         : None.
*******************************************************************************/
void map_erase(MAP* map, MAPKEY key) {
	unsigned i;
	if((i=_map_index(map, key)) != map->size) {
			(map->elements+i)->active = FALSE;
	}
}

/*******************************************************************************
* Function Name  : map_get
* Description    : Read an element from map.
* Input          : map: a pointer to the map,
* 				   key: key where element is being read.
* Output         : None.
* Return         : Element which is read.
*******************************************************************************/
MAPTYPE map_get(MAP* map, MAPKEY key) {
	return (map->elements+_map_index(map, key))->value;
}

/*******************************************************************************
* Function Name  : map_isset
* Description    : Read an element from map.
* Input          : map: a pointer to the map.
* Output         : None.
* Return         : Element which is read.
*******************************************************************************/
BOOL map_isset(MAP* map, MAPKEY i) {
	return (_map_index(map, i) == map->size) ? FALSE : TRUE;
}

/*******************************************************************************
* Function Name  : map_destroy
* Description    : Destroy map and free memory.
* Input          : map: pointer to the map.
* Output         : None.
* Return         : None.
*******************************************************************************/
void map_destroy(MAP* map) {
	free(map->elements);
	free(map);
}

/*******************************************************************************
* Function Name  : map_resize
* Description    : Resize map.
* Input          : map: a pointer to map,
* 				   n: a new size of map.
* Output         : None.
* Return         : None.
*******************************************************************************/
void map_resize(MAP* map, unsigned n) {
	map->size = n;
	map->elements = (MAP_ELEMENT*) realloc(map->elements, n*sizeof(MAPTYPE));
}


