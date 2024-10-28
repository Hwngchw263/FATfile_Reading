#include <stdint.h>

//Define offset of file metadata
#define FILENAME_OFFSET             8
#define FILENAME_EXTENSION_OFFSET   3
#define FILE_ATTRIBUTES_OFFSET      1
#define RESERIVED_OFFSET            10
#define TIME_OFFSET                 2   
#define DATE_OFFSET                 2
#define START_CLUSTER_OFFSET        2
#define FILE_SIZE_OFFSET            4

typedef struct {
    uint64_t Filename ;
    uint64_t Filename_Extension;
    uint8_t   File_Attributes;
    uint8_t Reserved[10];
    uint16_t Time;
    uint16_t Date;
    uint16_t Starting_Cluster;
    uint32_t File_Size;
} Directory_summary_type;

typedef struct {
    uint8_t Hours : 5;
    uint8_t Minutes : 6;
    uint8_t Two_second_periods :5;
}Time_type;

typedef struct {
    uint8_t Year : 7;
    uint8_t Month : 4;
    uint8_t Day :5;
}Date_type;