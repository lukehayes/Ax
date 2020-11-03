@echo off
REM cl main.c glfw4.lib -I C:\Dev\Libraries\GLFW3.3\include\ /link /LIBPATH:C:\Dev\Libraries\GLFW3.3\libs /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib
cl ../main.c User32.lib opengl32.lib glfw3.lib -I ../include /EHsc /link /LIBPATH:../libs /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib


