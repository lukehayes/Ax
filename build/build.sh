rm -rf bin
mkdir -p bin

SRC="main.c"
INC_DIRS="-I include"
LINK_DIRS="-L/usr/local/lib/GLFW"
LIBS="-lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl"
OUTPUT="-o app"

gcc $SRC $OUTPUT $INC_DIRS $LINK_DIRS $LIBS

mv app bin

./bin/app
