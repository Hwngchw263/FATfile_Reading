#include "DisplayData.h"

void Display_Description(BootSector_Type *bootsector) {
    int i;
    printf("Optional manufacturer description: ");
    for (i=0;i< sizeof(bootsector->oemName);i++){
        printf("%c",bootsector->oemName[i]);
    }
    printf("\nNumber of File Allocation Tables: %d",bootsector->numFATs);
    printf("\nMax directory entry: %d", bootsector->maxRootEntries);
    printf("\nVolume Serial Number: %x",bootsector->volumeID);
    printf("\nVolume Label: ");
    for (i=0;i< sizeof(bootsector->volumeLabel);i++){
        printf("%c",bootsector->volumeLabel[i]);
    }
    printf("\nFile system identifier: ");
    for (i=0;i< sizeof(bootsector->filesystemType);i++){
        printf("%c",bootsector->filesystemType[i]);
    }
     printf("\nSign: %x", bootsector->bootSectorSignature);
    
}