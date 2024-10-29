#ifndef __FORMAT_H__
#define __FORMAT_H__

#include <stdint.h>

#define BLOCKSIZE 512
#pragma pack(1)
typedef struct{
    uint8_t     bootstrap[3];             // Offset 0x00: Part of the bootstrap program (3 bytes)
    uint8_t     oemName[8];               // Offset 0x03: Optional manufacturer description (8 bytes)
    uint16_t    bytesPerSector;           // Offset 0x0B: Number of bytes per sector (almost always 512)
    uint8_t     sectorsPerCluster;        // Offset 0x0D: Number of blocks per allocation unit
    uint16_t    reservedSectors;          // Offset 0x0E: Number of reserved sectors, typically 1
    uint8_t     numFATs;                  // Offset 0x10: Number of File Allocation Tables
    uint16_t    maxRootEntries;           // Offset 0x11: Number of root directory entries
    uint16_t    totalSectors16;           // Offset 0x13: Total number of sectors (if < 65536; else 0)
    uint8_t     mediaDescriptor;          // Offset 0x15: Media descriptor byte
    uint16_t    sectorsPerFAT;            // Offset 0x16: Number of sectors per FAT
    uint16_t    sectorsPerTrack;          // Offset 0x18: Number of sectors per track
    uint16_t    numHeads;                 // Offset 0x1A: Number of heads (disk surfaces)
    uint32_t    hiddenSectors;            // Offset 0x1C: Number of hidden sectors (if any)
    uint32_t    totalSectors32;           // Offset 0x20: Total number of sectors if totalSectors16 == 0
    uint16_t    driveNumber;              // Offset 0x24: Physical drive number (usually 0)
    uint8_t     bootSignature;            // Offset 0x26: Extended Boot Record Signature (0x29 if present)
    uint32_t    volumeID;                 // Offset 0x27: Volume Serial Number
    uint8_t     volumeLabel[11];          // Offset 0x2B: Volume Label (11 characters, padded with spaces if shorter)
    uint8_t     filesystemType[8];        // Offset 0x36: File system identifier (e.g., "FAT12   ", "FAT16   ")
    uint8_t     bootstrapCode[448];       // Offset 0x3E: Remainder of bootstrap code
    uint16_t    bootSectorSignature;      // Offset 0x1FE: Boot sector signature (0x55AA)

}BootSector_Type;


typedef enum {
    UNALLOCATED = 0x00000000,       // 0 - unallocated
    BAD_CLUSTER_12 = 0x00000FF7,    // 0xFF7 (for FAT12)
    BAD_CLUSTER_16 = 0x0000FFF7,    // 0xFFF7 (for FAT16)
    BAD_CLUSTER_32 = 0x0FFFFFF7,    // 0xFFFF FFF7 (for FAT32)
    EOF_CLUSTER_12 = 0x00000FF8,    // 0xFF8 (for FAT12, end of file)
    EOF_CLUSTER_16 = 0x0000FFF8,    // 0xFFF8 (for FAT16, end of file)
    EOF_CLUSTER_32 = 0x0FFFFFF8     // 0xFFFF FFF8 (for FAT32, end of file)
} FATClusterStatus;

//FATEntry type show the cluster is bad, end of file, allocated or unlocated
typedef struct{
    FATClusterStatus state;
    uint8_t next_cluster_num;
}FATEntry_Type;

typedef struct {
    char filename[8];         // 0x00 - Filename (8 bytes)
    char extension[3];        // 0x08 - Filename extension (3 bytes)
    uint8_t attributes;       // 0x0b - File attributes (1 byte)
    uint8_t reserved[10];     // 0x0c - Reserved (10 bytes)
    uint16_t time;            // 0x16 - Time created or last updated (2 bytes)
    uint16_t date;            // 0x18 - Date created or last updated (2 bytes)
    uint16_t startCluster;    // 0x1a - Starting cluster number for file (2 bytes)
    uint32_t fileSize;        // 0x1c - File size in bytes (4 bytes)
} DirectoryEntry_Type;

#endif