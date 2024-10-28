#ifndef __DISPLAYDATA_H__
#define __DISPLAYDATA_H__

#include <stdio.h>
#include <stdint.h>

typedef enum
{
	HANDLE_FAT_SUCCESS=0U,
	HANDLE_FAT_INVALID=1U
}DATA_State;

void Display_Data(uint32_t cluster);
#endif