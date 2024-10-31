#include "UserHandling.h"

BootSector_Type bootsector;
DirectoryType rootdirectory;
void Open(const char* file){

    Open_FAT_File(file);
    Read_Boot_blockArea(&bootsector);
    Display_BootBlock(&bootsector);
    Read_Root_DirectoryArea(&bootsector, &rootdirectory);
}

void Close(){
    Close_FAT_File();
}