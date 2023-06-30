#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.hpp"

void draw(sf::RenderWindow window,int** board) {
    ;
}

int main() {
    // sf::RectangleShape shape(sf::Vector2f(100, 100));
    // shape.setFillColor(sf::Color(255, 255, 255));

    // sf::RectangleShape board[8][8];

    // while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed) window.close();
    //     }

    //     window.clear();

    //     for (int x = 0; x < 8; x++) {
    //         for (int y = 0; y < 8; y++) {
    //             board[x][y] = sf::RectangleShape(sf::Vector2f(100, 100));
    //             if ((x + y) % 2 == 0) {
    //                 board[x][y].setFillColor(black);
    //             } else {
    //                 board[x][y].setFillColor(white);
    //             }
    //             board[x][y].setPosition(x * 100, y * 100);
    //             window.draw(board[x][y]);
    //         }
    //     }

    //     window.display();
    // }

    int width = 200;
    int height = 100;
    int desktopWdith = sf::VideoMode::getDesktopMode().width;
    int desktopHeight = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(width, height), "Life");

    Map* gameBoard = new Map(width, height);
    gameBoard->genMap();

    int** tmp = gameBoard->getMap();

    return 0;
}
