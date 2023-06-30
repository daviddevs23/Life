#ifndef MAP_HPP
#define MAP_HPP

class Map {
   private:
    int width{};
    int height{};
    int** map;

   public:
    int getWidth();
    int getHeight();
    int** getMap();

    Map(int width, int height);

    bool genMap();
};

#endif
