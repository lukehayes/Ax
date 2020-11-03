@echo off
REM cl main.c glfw4.lib -I C:\Dev\Libraries\GLFW3.3\include\ /link /LIBPATH:C:\Dev\Libraries\GLFW3.3\libs /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib
cl /MD ../main.c -I ../include /link glfw3.lib gdi32.lib user32.lib opengl32.lib kernel32.lib ucrt.lib shell32.lib msvcrt.lib /LIBPATH:../libs /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib


