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
ProcessStatus_t Read_FAT_file();
ProcessStatus_t Read_Boot_blockArea(BootSector_Type *bootsector);
ProcessStatus_t Read_File_allocation_tableArea();
ProcessStatus_t Read_Root_DirectoryArea(BootSector_Type *bootsector, DirectoryEntry_Type *rootdirectory);
ProcessStatus_t Read_Entry();
void Read_DataArea();

#endif