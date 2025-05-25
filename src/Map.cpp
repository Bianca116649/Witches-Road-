#include "../include/Map.h"
#include <iostream>
#include <random>
#include <memory>
#include "../include/Exceptii.h"

Map::Map() : mapWidth(30), mapHeight(15),
             map_matrix(mapHeight, std::vector<string>(mapWidth, "_")),
             witch_cleared(mapHeight, std::vector<bool>(mapWidth, false)) {}

void Map::adauga(std::shared_ptr<Character> const& character) {
    characters.push_back(character);
}

void Map::adaugaObstacol(std::shared_ptr<Obstacle> const& obstacle) {
    obstacles.push_back(obstacle);
}

const std::vector<std::shared_ptr<Obstacle>>& Map::getObstacles() const {
    return obstacles;
}

bool Map::isInside(const int x, const int y) const {
    return x >= 0 && x < mapWidth && y >= 0 && y < mapHeight;
}

bool Map::canMove(const Character& character, const int dx, const int dy) const {
    const int newX = character.getX() + dx;
    const int newY = character.getY() + dy;
    return isInside(newX, newY);
}

void Map::updateMap() {
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            map_matrix[i][j] = "_";
        }
    }

    for (const auto& character : characters) {
        const int x = character->getX();
        const int y = character->getY();

        if (!isInside(x, y)) {
            std::cout<<"Character "<<character->getName()<<" is out of bounds.";
            continue;
        }
        map_matrix[y][x]=character->getName()[0];
    }

    for (const auto& obstacle : obstacles) {
        const int x = obstacle->getX();
        const int y = obstacle->getY();
        map_matrix[y][x] = obstacle->getName();
    }

    for (const auto& row : map_matrix) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}