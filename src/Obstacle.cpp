#include "../include/Obstacle.h"

Obstacle::Obstacle(){}

Obstacle::Obstacle(const std::string& name, const int damage, const int x, const int y, const bool active)
    : name(name), totalDamage(damage), positionX(x), positionY(y), active(active) {}

Obstacle::~Obstacle() = default;

int Obstacle::getX() const {
    return positionX;
}

int Obstacle::getY() const {
    return positionY;
}

void Obstacle::setName(const std::string& name) {
    this->name = name;
}
void Obstacle::setPosition(const int x, const int y) {
    positionX = x;
    positionY = y;
}

const std::string& Obstacle::getName() const {
    return name;
}
int Obstacle::isActive() const {
    return active;
}