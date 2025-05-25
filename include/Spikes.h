#ifndef SPIKES_H
#define SPIKES_H
#include "Obstacle.h"

class Game;

class Spikes : public Obstacle {
private:
    int height;
    bool isPoisoned;
    Game* game;
public:
    Spikes();

    Spikes(int height, bool isPoisoned,const std::string& name, int total_damage, int position_x, int position_y, Game* game, bool active);

    int getBaseDamage() const override;

    int getHeight() const;

    void takeDamage(int damage);

    void applyDamage(Character& target) override;

    void activate(Character& target) override;

    void deactivate();

    void updateScore() const;

    int calculateDamage() const override;

    ~Spikes() override;
};

#endif // SPIKES_H