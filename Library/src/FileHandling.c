
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

ProcessStatus_t Read_Root_DirectoryArea(const BootSector_Type *bootsector, DirectoryType *rootdirectory) {
    ProcessStatus_t status = PROCESS_SUCCESS;
    if (fileptr == NULL) {
		status = PROCESS_FAILURE;
	}
	else {
		uint32_t rootdir = (bootsector->sectorsPerFAT * bootsector->numFATs + bootsector->reservedSectors) * bootsector->bytesPerSector;
		rootdirectory->Entry_list = malloc(sizeof(SFNEntry)* bootsector->numRootEntries);
		rootdirectory->number_current_entries = 0;
        printf("\nRoot directory position: 0x%x", rootdir);
		printf("\nSize of an SFN entry: %d", sizeof(SFNEntry));
		printf("\nSize of an LFN entry: %d", sizeof(LFNEntry));
		/*move current position to root area offset*/
		fseek(fileptr,rootdir,SEEK_SET);
		// printf("\nLog: 0x%x",fgetc(fileptr));
		uint8_t i, j;
		SFNEntry Temp_SFN_entry;
		LFNEntry Temp_LFN_entry;
		uint8_t File_Attribute;
		if (rootdirectory->Entry_list != NULL ) {
			for (i = 0; i < bootsector->numRootEntries; i++) {
				/*move to attribute field position*/
				fseek(fileptr,0x0B,SEEK_CUR);
				//Read attribute field
				File_Attribute = fgetc(fileptr);
				printf("\nLog attribute: 0x%x", File_Attribute);
				/*Return to start position of entry*/
				fseek(fileptr,-0x0C,SEEK_CUR);
				if (File_Attribute != 0x0F) {
					fread(&Temp_SFN_entry,sizeof(SFNEntry), 1, fileptr);
					if(Temp_SFN_entry.filename[0] != 0x0) {
						*(rootdirectory->Entry_list + rootdirectory->number_current_entries) = Temp_SFN_entry;
						// *(rootdirectory+i) = Temp_SFN_entry;
						rootdirectory->number_current_entries++;
					}
					else {
						break;
					}
				}
				else {
					fread(&Temp_LFN_entry,sizeof(LFNEntry), 1, fileptr);
				}

			}
		}
		printf("\nNumber entry: %d",rootdirectory->number_current_entries);
		printf("\nAll entry: ");
		for (i = 0; i< rootdirectory->number_current_entries; i++){
			printf("\nEntry %d : ", i+1);
			for (j=0; j < sizeof(rootdirectory->Entry_list[i].filename) ; j++) {
				printf("%c",rootdirectory->Entry_list[i].filename[j]);
			}
		}
	}	
}
