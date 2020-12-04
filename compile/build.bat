@echo off
REM cl main.c glfw4.lib -I C:\Dev\Libraries\GLFW3.3\include\ /link /LIBPATH:C:\Dev\Libraries\GLFW3.3\libs /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

del bin/app.exe

set OUTPUT_DIR=bin
MKDIR %OUTPUT_DIR%

REM Compiler Flags
set COMPILE_FLAGS=/MD /Febin\app.exe /DMAX_MODELS=100

REM Link Libraries

set LOCAL_LIBS_DIR=C:\Dev\Libraries
set INCLUDES=-I include -I %LOCAL_LIBS_DIR%\GLFW\include -I %LOCAL_LIBS_DIR%\GLEW\Include -I %LOCAL_LIBS_DIR%\CGLM\Include\
set LIBS_DIR= /LIBPATH:%LOCAL_LIBS_DIR%\GLFW\Libs /LIBPATH:%LOCAL_LIBS_DIR%\GLEW\Libs /LIBPATH:%LOCAL_LIBS_DIR%\CGLM\Libs
set LIBS=glfw3.lib gdi32.lib user32.lib opengl32.lib kernel32.lib ucrt.lib shell32.lib msvcrt.lib glew32s.lib

REM Project Sources
set SRC_ROOT=src/*.c
set MATH_SRC=src/math/*.c
set GFX_SRC=src/graphics/*.c
set ALL_DRC=%SRC_ROOT% %MATH_SRC% %GFX_SRC%


cl main.c %SRC_ROOT% %COMPILE_FLAGS% %INCLUDES% /link %LIBS% %LIBS_DIR% /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

del *.obj

REM bin\app.exe

