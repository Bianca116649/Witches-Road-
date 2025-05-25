#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include <string>
#include "Character.h"
#include "Obstacle.h"

class Map {
private:
    const int mapWidth;
    const int mapHeight;
    std::vector<std::vector<string>> map_matrix;
    std::vector<std::vector<bool>> witch_cleared;
    std::vector<std::shared_ptr<Character>> characters;
    std::vector<std::shared_ptr<Obstacle>> obstacles;

public:
    Map();
    void updateMap();

    void drawMap();
    bool isInside(const int x, const int y)const;
    bool canMove(const Character& character, int dx, int dy)const;
    void drawMap() const;
    void printMap() const;
    void adauga(std::shared_ptr<Character> const& character);

    void adaugaObstacol(std::shared_ptr<Obstacle> const &obstacle);
    const std::vector<std::shared_ptr<Obstacle>>& getObstacles() const;
};

#endif // MAP_H