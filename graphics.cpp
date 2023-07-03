#include "graphics.hpp"

#include <iostream>

Graphics::Graphics(int width, int height, std::string name) {
    this->windowWidth = width;
    this->windowHeight = height;
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), name);
}

// TODO: Change colors depending on terrain type
bool Graphics::setBackground(int** board, int width, int height) {
    this->backgroundImage.create(width, height, sf::Color(235, 52, 219));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int colorTmp = board[x][y];
            this->backgroundImage.setPixel(x, y, sf::Color(colorTmp, colorTmp, colorTmp));
        }
    }

    this->backgroundTexture.create(width, height);
    this->backgroundTexture.update(this->backgroundImage);

    this->background.setTexture(this->backgroundTexture);
    this->background.setPosition(sf::Vector2f(0, 0));

    return true;
}
bool Graphics::drawBackground() {
    this->window->draw(this->background);
    return true;
};

bool Graphics::updateDisplay() {
    this->window->clear();
    this->drawBackground();
    this->window->display();
    return true;
}

sf::RenderWindow* Graphics::getWindow() { return this->window; }
