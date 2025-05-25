#include "../include/Character.h"
#include <iostream>

Character::Character() : name(""), posX(0), posY(0), level(0), strength(0), health(100) {}

Character::Character(const std::string& name, int x, int y, int level, int strength)
    : name(name), posX(x), posY(y), level(level), strength(strength), health(100) {}

Character::Character(const Character& other)
    : name(other.name), posX(other.posX), posY(other.posY),
      level(other.level), strength(other.strength), health(other.health) {}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        posX = other.posX;
        posY = other.posY;
        level = other.level;
        strength = other.strength;
        health = other.health;
    }
    return *this;
}

const std::string& Character::getName() const { return name; }
int Character::getX() const { return posX; }
int Character::getY() const { return posY; }
void Character::move(int dx, int dy) {
    posX += dx;
    posY += dy;
}
int Character::getLevel() const { return level; }
int Character::getStrength() const { return strength; }
int Character::getHealth() const { return health; }

Character& Character::operator*=(int factor) {
    strength *= factor;
    return *this;
}

void Character::displayInfo() const {
    std::cout << *this << "\n";
}


std::ostream& operator<<(std::ostream& out, const Character& c) {
    out << "Name: " << c.getName()
        << ", Level: " << c.getLevel()
        << ", Power: " << c.getStrength()
        << ", Positions: (" << c.getX() << ", " << c.getY() << ")"
        << ", Health: " << c.getHealth();
    return out;
}