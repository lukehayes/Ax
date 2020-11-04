#ifndef _CG_ENGINE_H
#define _CG_ENGINE_H

typedef struct Engine
{
    int width;
    int height;
    const char* title;
} Engine;

Engine CG_CreateEngine()
{
    Engine e = { 800,600, "Game" };
    return e;
}

#endif
