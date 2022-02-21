#ifndef AX_CONFIG_H
#define AX_CONFIG_H

#include <string>

/**
 * Location for all global settings for simplicity.
 */
struct Config
{
    int width =  800;
    int height = 600;
    std::string title = "No Game Title";
};

#endif
