#include "map.hpp"

#include <math.h>

#include <cstdlib>
#include <iostream>

int Map::getWidth() { return this->width; }
int Map::getHeight() { return this->height; }
int** Map::getMap() { return this->map; }

float interpolate(float a0, float a1, float w) {
    if (0.0 > w) return a0;
    if (1.0 < w) return a1;
    return (a1 - a0) * (3.0 - w * 2.0) * w * w + a0;
}

typedef struct {
    float x, y;
} vector2;

vector2 randomGradient(int ix, int iy) {
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2;
    unsigned a = ix, b = iy;
    a *= 3284157443;
    b ^= a << s | a >> (w - s);
    b *= 1911520717;
    a ^= b << s | b >> (w - s);
    a *= 2048419325;
    float random = a * (3.14159265 / ~(~0u >> 1));
    vector2 v;
    v.x = cos(random);
    v.y = sin(random);
    return v;
}

float dotGridGradient(int ix, int iy, float x, float y) {
    vector2 gradient = randomGradient(ix, iy);

    float dx = x - (float)ix;
    float dy = y - (float)iy;

    return (dx * gradient.x + dy * gradient.y);
}

float perlin(float x, float y) {
    int x0 = (int)floor(x);
    int x1 = x0 + 1;
    int y0 = (int)floor(y);
    int y1 = y0 + 1;

    float sx = x - (float)x0;
    float sy = y - (float)y0;

    float n0, n1, ix0, ix1, value;

    n0 = dotGridGradient(x0, y0, x, y);
    n1 = dotGridGradient(x1, y0, x, y);
    ix0 = interpolate(n0, n1, sx);

    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);
    ix1 = interpolate(n0, n1, sx);

    value = interpolate(ix0, ix1, sy);
    return value;
}

// TODO: Implement Perlin Noise for map generation
bool Map::genMap() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            this->map[x][y] = (perlin(x / 255.0, y / 255.0) * 255) + 122;
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
