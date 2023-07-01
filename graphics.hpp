#include <SFML/Graphics.hpp>

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

//TODO: Create a loop object to run the game

class Graphics {
   private:
    int windowWidth;
    int windowHeight;
    sf::RenderWindow* window;
    sf::Sprite background;

   public:
    Graphics(int width, int height, std::string name);
    sf::RenderWindow* getWindow();
    bool setBackground(int** board, int width, int height);
    bool drawBackground();
    bool updateDisplay();
};

#endif
