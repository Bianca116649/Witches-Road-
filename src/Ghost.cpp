#include "../include/Ghost.h"
#include "../include/Character.h"
#include <iostream>

Ghost::Ghost( const int power, const bool fly, const int position_x, const std::string& name, const int position_y, const int total_damage, bool active)
    : Obstacle(name, total_damage, position_x, position_y, active),
fly(fly), power(power){
}

Ghost::Ghost(): fly(false), power(0){
    active = true;
    totalDamage = 20;
}

int Ghost::getBaseDamage() const {
    return totalDamage;
}

int Ghost::calculateDamage() const {
    if (active==false) {
        return 0;
    }
    int damage = getBaseDamage();
    if (fly) {
        damage = static_cast<int>(damage * 1.2);
    }
    return damage;

}

void Ghost::takeDamage(const int damage) {
    power -= damage;
    if (power<= 0 && active) {
        active = false;
    }
}

void Ghost::applyDamage(Character& target) {
    int damage = calculateDamage();
    if (damage>0) {
        target.receiveDamage(damage);
    }
}

void Ghost::activate(Character& target) {
    applyDamage(target);
}

bool Ghost::isAlive() const {
    return active;
}

int Ghost::getPower() const {
    return power;
}
