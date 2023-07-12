#include "map.hpp"

#include <cstdlib>
#include <iostream>

int Map::getWidth() { return this->width; }
int Map::getHeight() { return this->height; }
int** Map::getMap() { return this->map; }

// TODO: Implement Perlin Noise for map generation
bool Map::genMap() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            this->map[x][y] = std::rand() % 255;
        }
    }
    return true;
}

Map::Map(int width, int height) {
    this->width = width;
    this->height = height;
    this->map = new int*[width];

    if (this->height < 1 || this->width < 1) {
        std::cout << "Please reinitialize map with a valid width and height "
                     "(greater than 0)"
                  << std::endl;
    }

    for (int i = 0; i < width; i++) {
        this->map[i] = new int[height];
    }
}
