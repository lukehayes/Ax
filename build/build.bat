@echo off
REM cl main.c glfw4.lib -I C:\Dev\Libraries\GLFW3.3\include\ /link /LIBPATH:C:\Dev\Libraries\GLFW3.3\libs /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

del bin/app.exe

set outputDir=bin
MKDIR %outputDir%

REM Compiler Flags
set compileFlags=/MD /Feapp.exe

REM Link Libraries
set libs=glfw3.lib gdi32.lib user32.lib opengl32.lib kernel32.lib ucrt.lib shell32.lib msvcrt.lib glew32s.lib


cl /MD /Feapp.exe main.c -I include -I deps\GLEW /link %libs% /LIBPATH:libs /LIBPATH:C:\Dev\Libraries\GLEW\Libraries /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

app.exe

