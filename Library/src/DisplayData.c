#include "DisplayData.h"

void Display_Description(BootSector_Type *bootsector) {
    int i;
    for (i=0;i< sizeof((*bootsector).filesystemType);i++){
        printf("%c",(*bootsector).filesystemType[i]);
    }
}