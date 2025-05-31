#ifndef GHOST_H
#define GHOST_H
#include "Obstacle.h"

class Game;

class Ghost : public Obstacle {
private:
    bool fly;
    int power;
public:
    Ghost();

    Ghost(int power, bool fly, int position_x, const std::string &name, int position_y,
          int total_damage, bool active);

    int getBaseDamage() const override;

    int calculateDamage() const override;

    void takeDamage(int damage);

    void applyDamage(Character& target) override;

    void activate(Character& target) override;

    bool isAlive() const;

    int getPower() const;

};

#endif // GHOST_H