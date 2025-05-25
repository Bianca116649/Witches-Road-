#include "../include/Spikes.h"
#include "../include/Character.h"
#include "../include/Game.h"
#include <iostream>

Spikes::Spikes(): Obstacle(), height(0), isPoisoned(false), game(nullptr) {
}

Spikes::Spikes(const int height, const bool isPoisoned,const std::string& name, const int total_damage, const int position_x, const int position_y, Game* game, const bool active)
    : Obstacle(name, total_damage, position_x, position_y,active), height(height), isPoisoned(isPoisoned), game(game){}

void Spikes::applyDamage(Character& target) {
    const int damage = calculateDamage();
    target.receiveDamage(damage);
    updateScore();
}

int Spikes::calculateDamage() const {
    int damage = (height < 40) ? totalDamage : 2*totalDamage;
    if (isPoisoned) {
        damage += 10 * totalDamage;
    }
    return damage;
}

int Spikes::getBaseDamage() const {
    return calculateDamage();
}

void Spikes::updateScore() const {
    int damage = calculateDamage();
    game->updateScore(-damage);
}
int Spikes::getHeight() const {
    return height;
}

void Spikes::deactivate(){
    active = true;
    height = 0;
}

void Spikes::activate(Character& target) {
    if (!active) {
        applyDamage(target);
    }
}

Spikes::~Spikes() = default;

void Spikes::takeDamage(const int damage) {
    height -= damage;
    if (height <= 0) {
        deactivate();
    }
}
