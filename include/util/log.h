#ifndef UTIL_LOG_H
#define UTIL_LOG_H
#include <stdio.h>

/** ========================================================================
    Wrapper functions around printf() for logging messages with colors.
======================================================================== **/

void L(const char* message)
{
    printf("\e[32mLog:\e[96m%s\e[0m\n", message);
}

void LI(int value)
{
    printf("\e[32mLog:\e[96m%i\e[0m\n", value);
}

void LSI(const char* message, int value)
{
    printf("\e[32mLog:\e[96m%s - %i \e[0m\n", message, value);
}

void LSS(const char* message, const char* value)
{
    printf("\e[32mLog:\e[96m%s. - %s. \e[0m\n", message, value);
}

void LE(const char* message, const char* value)
{
    printf("\e[31mLog:%s. : \e[33m%s.\e[0m\n", message, value);
}


#endif
