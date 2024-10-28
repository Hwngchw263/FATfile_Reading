#ifndef __FILEHANDLING_H__
#define __FILEHANDLING_H__
#include <stdio.h>
#include "Format.h"
typedef enum {
	PROCESS_SUCCESS,
	PROCESS_FAILURE
} ProcessStatus_t;

ProcessStatus_t Open_FAT_File(const char* path);
ProcessStatus_t Close_FAT_File();
void Read_FAT_file();
ProcessStatus_t Read_Boot_blockArea();
void Get_Description();
void Read_File_allocation_tableArea();
void Read_Root_DirectoryArea();
void Read_DataArea();

#endif