#ifndef QUICKSAND_H
#define QUICKSAND_H

#include "Obstacle.h"
#include "Character.h"

class Quicksand : public Obstacle {
private:
    int escape_time;
    int damage_in_time;
    int duration;
    int initialDuration;

public:
    Quicksand();

    Quicksand(int escape, int total_damage, const std::string& name, int pos_x, int pos_y, int damage_per_second, bool active);
    void activate(Character& target) override;

    int calculateDamage() const override;

    void applyDamage(Character& target) override;

    int getBaseDamage() const override;

    void deactivate();

    void tick(Character& target);

    void reset();

    ~Quicksand() override;
};

#endif // QUICKSAND_H

