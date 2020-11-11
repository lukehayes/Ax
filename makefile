CC = gcc
CFLAGS = -Wall
IDFLAGS = -I include -I deps/GLEW
SRCDIR = src
SRCFLAGS = src/math/vec2.c
LDFLAGS = -L/usr/local/lib/GLFW -L deps/GLEW/lib -L .
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl -lGLEW
STATIC_LIBS = -lCG-Math-Static
TARGET = -o bin/app
ENTRY = main.c

#Bundle all source code into a single binary
all:
	$(CC) $(ENTRY) src/*/*.c $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

build-static: 
	$(CC) $(ENTRY) $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS) $(STATIC_LIBS)

libCG-Math-Static.a:
	$(CC) -c src/math/*.c $(IDFLAGS)
	ar -rcs $@ *.o


#Debug specific. -g3 flag enables ALL debugging symbols.
DEBUG_FLAGS = -Wall -ggdb
debug:
	$(CC) $(ENTRY) $(TARGET) $(DEBUG_FLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm *.o *.so *.a
	rm -r bin
