#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "graphics.hpp"
#include "map.hpp"

// TODO: Commenct code more
// TODO: Check for return values more effectively
// TODO: GDB to remove memory leaks

int main() {
    int width = 1024;
    int height = 1024;
    int desktopWdith = sf::VideoMode::getDesktopMode().width;
    int desktopHeight = sf::VideoMode::getDesktopMode().height;

    Map* gameBoard = new Map(width, height);
    gameBoard->genMap();
    int** tmp = gameBoard->getMap();

    Graphics* displayEngine = new Graphics(width, height, "Life");
    displayEngine->setBackground(tmp, width, height);


    while (displayEngine->getWindow()->isOpen()) {
        sf::Event event;
        while (displayEngine->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                displayEngine->getWindow()->close();
        }
        displayEngine->updateDisplay();
    }

    return 0;
}
