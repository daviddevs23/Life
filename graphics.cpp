#include "graphics.hpp"

Graphics::Graphics(int width, int height, std::string name) {
    this->windowWidth = width;
    this->windowHeight = height;
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), name);
}

bool Graphics::setBackground(int** board, int width, int height) {
    sf::Image* background = new sf::Image();
    background->create(width, height, sf::Color(235, 52, 219));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int colorTmp = board[x][y];
            background->setPixel(x, y, sf::Color(colorTmp, colorTmp, colorTmp));
        }
    }

    sf::Texture backgroundTexture;
    backgroundTexture.create(width, height);
    backgroundTexture.update(*background);
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(sf::Vector2f(0, 0));
    this->background = backgroundSprite;
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
