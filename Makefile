TARGET=triangle

all: $(TARGET)

$(TARGET): clean
	g++ src/main.cpp -o $(TARGET) -Wall `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

clean:
	rm -f *.o $(TARGET)

