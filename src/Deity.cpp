#include "../include/Deity.h"
#include <iostream>
#include <algorithm>

Deity::Deity(const std::string& name, const int posX, const int posY, const int level, const int strength,
             const int flySpeed, const int flyHeight, const bool immortal, const std::string& powers, const std::string& symbol)
    : Character(name, posX, posY, level, strength), flySpeed(flySpeed), flyHeight(flyHeight),
      immortal(immortal), powers(powers), symbol(symbol) {
}

Deity::Deity(const Deity& other)
    : Character(other), flySpeed(other.flySpeed), flyHeight(other.flyHeight), immortal(other.immortal),
      reincarnation(other.reincarnation), powers(other.powers), symbol(other.symbol) {}

Deity& Deity::operator=(const Deity& other) {
    if (this != &other) {
        Character::operator=(other);
        flySpeed = other.flySpeed;
        flyHeight = other.flyHeight;
        immortal = other.immortal;
        powers = other.powers;
        symbol = other.symbol;
        reincarnation = other.reincarnation;
    }
    return *this;
}

Deity::~Deity() = default;

int Deity::getFlySpeed() const { return flySpeed; }
int Deity::getFlyHeight() const { return flyHeight; }
bool Deity::isImmortal() const { return immortal; }
const std::string& Deity::getPowers() const { return powers; }
const std::string& Deity::getSymbol() const { return symbol; }

void Deity::receiveDamage(const int damage) {
    if (!immortal) {
     flySpeed = std::max(0, flySpeed -damage);
        flyHeight = max(0.0f, flyHeight -  static_cast<float>(0.5)*damage);
        if (flySpeed==0 && flyHeight==0) {
            reincarnation = 100;
            back_in_game();
        }
    }
}
void Deity::back_in_game() {
    flyHeight=10;
    flySpeed=10;
}


void Deity::displayInfo() const {
    std::cout << *this << "\n";
}

std::ostream& operator<<(std::ostream& out, const Deity& d) {
    out << "Deity: " << d.getName() << ", Level: " << d.getLevel() << ", Strength: " << d.getStrength()
        << ", Fly Speed: " << d.getFlySpeed() << ", Fly Height: " << d.getFlyHeight() << ", Immortal: "
        << (d.isImmortal() ? "Yes" : "No") << ", Powers: " << d.getPowers() << ", Symbol: " << d.getSymbol()
        << ", Position: (" << d.getX() << ", " << d.getY() << ")";
    return out;
}
