#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.hpp"

void draw(sf::RenderWindow* window, int** board, int width, int height) {
    sf::Image* background = new sf::Image();
    background->create(width, height, sf::Color(0, 0, 255));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int colorTMP = board[x][y];
            background->setPixel(x, y, sf::Color(colorTMP, colorTMP, colorTMP));
        }
    }

    sf::Texture backgroundTexture;
    backgroundTexture.update(*background);
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(sf::Vector2f(100,100));
    window->draw(backgroundSprite);
}

int main() {
    int width = 2000;
    int height = 1000;
    int desktopWdith = sf::VideoMode::getDesktopMode().width;
    int desktopHeight = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(width, height), "Life");

    Map* gameBoard = new Map(width, height);
    gameBoard->genMap();

    int** tmp = gameBoard->getMap();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        draw(&window, tmp, width, height);

        window.display();
    }

    return 0;
}
