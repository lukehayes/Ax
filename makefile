CC = gcc
CFLAGS = -Wall
IDFLAGS = -I include -I deps/GLEW
LDFLAGS = -L/usr/local/lib/GLFW -L deps/GLEW/lib
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl -lGLEW
TARGET = -o bin/$@
ENTRY = main.c

app:
	$(CC) $(ENTRY) $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

#Debug specific. -g3 flag enables ALL debugging symbols.
DEBUG_FLAGS = -Wall -g3
debug:
	$(CC) $(ENTRY) $(TARGET) $(DEBUG_FLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -r bin
