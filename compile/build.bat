@echo off
REM cl main.c glfw4.lib -I C:\Dev\Libraries\GLFW3.3\include\ /link /LIBPATH:C:\Dev\Libraries\GLFW3.3\libs /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

del "bin/app.exe"

REM --- Output Settings
set OUTPUT_DIR=bin
MKDIR %OUTPUT_DIR%

REM --- Compiler Flags
set COMPILE_FLAGS=/MD /EHsc /Febin\app.exe /std:c++17 /DMAX=100

REM --- Link Libraries Directory
set LOCAL_LIBS_DIR=C:\Dev\Libraries

REM --- Includes Directories
set INCLUDES=-I include -I %LOCAL_LIBS_DIR%\GLFW\include -I %LOCAL_LIBS_DIR%

REM --- Library Directories
set LIBS_DIR= /LIBPATH:%LOCAL_LIBS_DIR%\GLFW\Libs /LIBPATH:%LOCAL_LIBS_DIR%\GLEW\Libs /LIBPATH:%LOCAL_LIBS_DIR%\CGLM\Libs

REM --- Libraries
set LIBS=glfw3.lib gdi32.lib user32.lib opengl32.lib kernel32.lib ucrt.lib shell32.lib msvcrt.lib

REM --- Project Sources
set AX_SYSTEM_SRC=src/Ax/System/*.cpp
set AX_GL_SRC=src/Ax/System/GL/*.cpp
set AX_GRAPHICS_SRC=src/Ax/System/Graphics/*.cpp
set ALL_SRC=src/glad.c %AX_SYSTEM_SRC% %AX_GL_SRC% %AX_GRAPHICS_SRC%

REM --- Run Compiler
cl main.cpp %ALL_SRC% %COMPILE_FLAGS% %INCLUDES% /link %LIBS% %LIBS_DIR% /SUBSYSTEM:CONSOLE /NODEFAULTLIB:msvcrt.lib

REM --- Delete All Object Files
del *.obj

REM --- Run Binary
REM bin\app.exe

