#ifndef __CG_IO_H__
#define __CG_IO_H__

#include <stdio.h>
#include "common/types.h"

u8
CG_Get_Filesize(FILE* handle)
{
    fseek(handle, 0, SEEK_END);
    int size = ftell(handle);
    fseek(handle, 0, SEEK_SET);
    return size;
}

str
CG_Read_File(const char* filename, char* buffer)
{
    FILE* fh = fopen(filename, "r");
    int size = CG_Get_Filesize(fh);
    int counter = 0;

    for(int i = 0; i<= size + 1; i++) {
        buffer[i] = fgetc(fh);
    }

    fclose(fh);

    return buffer;
}




#endif
