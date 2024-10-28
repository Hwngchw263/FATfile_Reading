
#include "FileHandling.h"

FILE* fileptr = NULL;
ProcessStatus_t Open_FAT_File(const char* path) {
	ProcessStatus_t status = PROCESS_SUCCESS;
	fileptr = fopen(path, "r + b");
	if (fileptr != NULL) {
        printf("Success to open file.\n");
	}
    else {
		status = PROCESS_FAILURE;
        printf("Fail to open file.\n");
    }
	return status;
}
ProcessStatus_t Close_FAT_File() {
	ProcessStatus_t status = PROCESS_SUCCESS;
	if (fclose(fileptr) == 0) {
        printf("Success to close file.\n");
	}
    else {
        status = PROCESS_FAILURE;
        printf("Fail to close file.\n");
    }
	return status;
}

ProcessStatus_t Read_Boot_blockArea(BootSector_Type *bootsector) {
    ProcessStatus_t status = PROCESS_SUCCESS;
    if (fileptr == NULL) {
		status = PROCESS_FAILURE;
	}
	else {
        printf("Boot size: %d\n", sizeof(BootSector_Type));
		fread(bootsector, BLOCKSIZE, 1, fileptr);
        printf("Sign: %x\n", (*bootsector).bootSectorSignature);
	}
}
