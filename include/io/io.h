#ifndef CG_IO_H
#define CG_IO_H

#include <stdio.h>
#include "common/types.h"

u8
CG_Get_Filesize(FILE* handle)
{
    // Move the file pointer to the end of the file to
    // work out the file size.
    fseek(handle, 0, SEEK_END);
    int size = ftell(handle);
    fseek(handle, 0, SEEK_SET);
    return size;
}

/**
 * Read a file into a buffer and return it. 
 * Buffer needs to be freed after use!
 */
const char*
CG_Read_File(const char* filename)
{
    FILE* fh = fopen(filename, "r");
    int size = CG_Get_Filesize(fh);

    char* buffer = malloc(sizeof(char) * size);

    for(int i = 0; i<= size; i++) {
        buffer[i] = fgetc(fh);

        if(i == size)
        {
            buffer[i] = '\0';
        }
    }

    fclose(fh);

    return buffer;
}




#endif
