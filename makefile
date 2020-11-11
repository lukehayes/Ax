CC = gcc
CFLAGS = -Wall
IDFLAGS = -I include -I deps/GLEW
SRCDIR = src
SRCFLAGS = src/math/vec2.c
LDFLAGS = -L/usr/local/lib/GLFW -L deps/GLEW/lib -L .
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl -lGLEW -lCG-Math
TARGET = -o bin/app
ENTRY = main.c

all: libCG-Math.so
	$(CC) $(ENTRY) $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

CG-Math.o: $(wildcard src/math/*.c)
	$(CC) -c $^  $(IDFLAGS)

libCG-Math.so: $(wildcard src/math/*.c)
	$(CC) -fPIC -shared -o $@  -c $^ -lc $ $(IDFLAGS)


#Debug specific. -g3 flag enables ALL debugging symbols.
DEBUG_FLAGS = -Wall -ggdb
debug:
	$(CC) $(ENTRY) $(TARGET) $(DEBUG_FLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm *.o *.so *.a
	rm -r bin
