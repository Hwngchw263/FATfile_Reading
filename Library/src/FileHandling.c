
#include "FileHandling.h"

FILE* fileptr = NULL;
ProcessStatus_t Open_FAT_File(const char* path) {
	ProcessStatus_t status = PROCESS_SUCCESS;
	fileptr = fopen(path, "r + b");
	if (fileptr != NULL) {
        printf("\nSuccess to open file.");
	}
    else {
		status = PROCESS_FAILURE;
        printf("\nFail to open file.");
    }
	return status;
}
ProcessStatus_t Close_FAT_File() {
	ProcessStatus_t status = PROCESS_SUCCESS;
	if (fclose(fileptr) == 0) {
        printf("\nSuccess to close file.");
	}
    else {
        status = PROCESS_FAILURE;
        printf("\nFail to close file.");
    }
	return status;
}

ProcessStatus_t Read_Boot_blockArea(BootSector_Type *bootsector) {
    ProcessStatus_t status = PROCESS_SUCCESS;
    if (fileptr == NULL) {
		status = PROCESS_FAILURE;
	}
	else {
		fread(bootsector, sizeof(BootSector_Type), 1, fileptr);
	}
}

ProcessStatus_t Read_Root_DirectoryArea(BootSector_Type *bootsector, DirectoryEntry_Type *rootdirectory) {
    ProcessStatus_t status = PROCESS_SUCCESS;
    if (fileptr == NULL) {
		status = PROCESS_FAILURE;
	}
	else {
		uint32_t rootdir = (bootsector->sectorsPerFAT * bootsector->numFATs + bootsector->reservedSectors) * bootsector->bytesPerSector;
        printf("\nRoot directory position: 0x%x", rootdir);
	}	
}
ProcessStatus_t Read_Entry() {

}