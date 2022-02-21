/**
 * Simple logging output utilities for debugging.
 */
#ifndef AX_SYS_COMMON_LOG
#define AX_SYS_COMMON_LOG

#include <iostream>

template<typename A>
void LOG(const A& a)
{
    if(DEBUG)
    {
        std::cout << "LOG: " << a << std::endl;
    }
}

template<typename A, typename B>
void LOG(const A& a, const B& b)
{
    if(DEBUG)
    {
        std::cout << "LOG: " << a << " " << b << std::endl;
    }
}

template<typename A, typename B, typename C>
void LOG(const A& a, const B& b, const C& c)
{
    if(DEBUG)
    {
        std::cout << "LOG: " << a << " " << b << " " << c << std::endl;
    }
}

#endif  //AX_SYS_COMMON_LOG
