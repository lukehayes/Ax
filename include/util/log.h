/*
 * =====================================================================================
 *
 *    Description:  Functions for logging messages to the console, with colours.
 *
 * =====================================================================================
 */

#ifndef UTIL_LOG_H
#define UTIL_LOG_H

/* #####   HEADER FILE INCLUDES   ################################################### */
#include <stdio.h>


/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  L - Log
 *  Description:  Log a string(message)to the console.
 * =====================================================================================
 */
void L(const char* message)
{
    printf("\e[32mLog:\e[96m%s\e[0m\n", message);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  LI - Log Integer
 *  Description:  Log a integer(value)to the console.
 * =====================================================================================
 */
void LI(int value)
{
    printf("\e[32mLog:\e[96m%i\e[0m\n", value);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  LSI - Log String Integer
 *  Description:  Log a string(message) and an integer(value)to the console.
 * =====================================================================================
 */
void LSI(const char* message, int value)
{
    printf("\e[32mLog:\e[96m%s - %i \e[0m\n", message, value);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  LSS - Log String String
 *  Description:  Log a string(message) and another string(value)to the console.
 * =====================================================================================
 */
void LSS(const char* message, const char* value)
{
    printf("\e[32mLog:\e[96m%s. - %s. \e[0m\n", message, value);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  LE - Log Error
 *  Description:  Log a error string(message) and another string(value)to the console.
 * =====================================================================================
 */
void LE(const char* message, const char* value)
{
    printf("\e[31mLog:%s. : \e[33m%s.\e[0m\n", message, value);
}


#endif
