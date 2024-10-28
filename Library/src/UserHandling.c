#include "UserHandling.h"

BootSector_Type bootsector;

void Open(const char* file){
    Open_FAT_File(file);
    Read_Boot_blockArea(&bootsector);
    Display_Description(&bootsector);
}

void Close(){
    Close_FAT_File();
}