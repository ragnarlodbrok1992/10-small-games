TARGET=triangle
ADDITIONAL_SOURCE=src/entities/pad.cpp src/entities/ball.cpp

all: $(TARGET)

$(TARGET): clean
	g++ src/main.cpp ${ADDITIONAL_SOURCE} -o $(TARGET) -Wall `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -g

clean:
	rm -f *.o $(TARGET)

