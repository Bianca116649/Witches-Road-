#include "../include/Witch.h"
#include <iostream>
#include<algorithm>

Witch::Witch(bool isAlive, const std::string& name, int posX, int posY, int level, int strength,
             int life, int speed, bool hasAnimal, const std::string& covenName)
    : Character(name, posX, posY, level, strength), isAlive(isAlive), life(life), speed(speed),
      hasAnimal(hasAnimal), covenName(covenName) {}

Witch::Witch(const Witch& other)
    : Character(other), isAlive(other.isAlive), life(other.life), speed(other.speed),
      hasAnimal(other.hasAnimal), covenName(other.covenName) {}

Witch& Witch::operator=(const Witch& other) {
    if (this != &other) {
        Character::operator=(other);
        isAlive = other.isAlive;
        life = other.life;
        speed = other.speed;
        hasAnimal = other.hasAnimal;
        covenName = other.covenName;
    }
    return *this;
}

Witch::~Witch() {}

int Witch::getLife() const { return life; }
int Witch::getSpeed() const { return speed; }
const std::string& Witch::getCovenName() const { return covenName; }
bool Witch::isAliveStatus() const { return isAlive; }

void Witch::receiveDamage(const int damage) {
    if (!isAlive) return;
    life = std::max(0, life - damage);
    if (life == 0) {
        isAlive = false;
        std::cout << "Witch has died.\n";
    }
}


void Witch::displayInfo() const {
    std::cout << *this << "\n";
}

std::ostream& operator<<(std::ostream& out, const Witch& w) {
    out << "Witch: " << w.getName() << ", Level: " << w.getLevel() << ", Strength: " << w.getStrength()
        << ", Life: " << w.getLife() << ", Speed: " << w.getSpeed() << ", Alive: " << (w.isAliveStatus() ? "Yes" : "No")
        << ", Coven: " << w.getCovenName() << ", Position: (" << w.getX() << ", " << w.getY() << ")";
    return out;
}