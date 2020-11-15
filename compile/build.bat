@echo off
REM cl main.c glfw4.lib -I C:\Dev\Libraries\GLFW3.3\include\ /link /LIBPATH:C:\Dev\Libraries\GLFW3.3\libs /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

del bin/app.exe

set outputDir=bin
MKDIR %outputDir%

REM Compiler Flags
set compileFlags=/MD /Febin\app.exe

REM Link Libraries

set LOCAL_LIBS=C:\Dev\Libraries
set includes=-I include -I %LOCAL_LIBS%\GLFW\include -I %LOCAL_LIBS%\GLEW\Include -I %LOCAL_LIBS%\CGLM\Include\
set LIBS_DIR= /LIBPATH:%LOCAL_LIBS%\GLFW\Libs /LIBPATH:%LOCAL_LIBS%\GLEW\Libs /LIBPATH:%LOCAL_LIBS%\CGLM\Libs
set LIBS=glfw3.lib gdi32.lib user32.lib opengl32.lib kernel32.lib ucrt.lib shell32.lib msvcrt.lib glew32s.lib
set math_src=src/math/*.c
set util_src=src/util/*.c


cl main.c %compileFlags% %math_src% %includes% /link %LIBS% %LIBS_DIR% /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

del *.obj

REM bin\app.exe

