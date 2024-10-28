#include <stdint.h>
#include "FileHandling.h"

char keyinput[20];

int main() {	
	Open_FAT_File("floppy.img");
	Read_Boot_blockArea();
	Get_Description();
	Close_FAT_File();
}
