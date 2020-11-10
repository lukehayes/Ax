CC = gcc
CFLAGS = -Wall
IDFLAGS = -I include -I deps/GLEW
SRCDIR = src
SRCFLAGS = src/math/vec2.c
LDFLAGS = -L/usr/local/lib/GLFW -L deps/GLEW/lib
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl -lGLEW
TARGET = -o bin/app
ENTRY = main.c

all: cg-math
	$(CC) $(ENTRY) $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)


MATH_DIR = $(SRCDIR)/math
MATH_LIB_SRC = $(MATH_DIR)/*.c
cg-math: 
	$(CC) -c $(MATH_LIB_SRC) $(IDFLAGS)


#Debug specific. -g3 flag enables ALL debugging symbols.
DEBUG_FLAGS = -Wall -ggdb
debug:
	$(CC) $(ENTRY) $(TARGET) $(DEBUG_FLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm *.o
	rm -r bin
