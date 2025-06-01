#ifndef QUICKSAND_H
#define QUICKSAND_H

#include "Obstacle.h"
#include "Character.h"
#include <string>

template<typename T>
class Quicksand : public Obstacle {

private:
    T escape_time;
    T damage_in_time;
    T duration;
    T initialDuration;

public:
    Quicksand()
        : escape_time(0), damage_in_time(0), duration(0), initialDuration(0) {}

    Quicksand(T escape, T total_damage, const std::string& name, int pos_x, int pos_y,
        T damage_per_second, bool active)
        : Obstacle(name, static_cast<int>(total_damage), pos_x, pos_y, active),
          escape_time(escape),
          damage_in_time(damage_per_second),
          duration(escape),
          initialDuration(escape) {}

    void activate(Character& target) override {
        (void) target;
        active=true;
    }

    int calculateDamage() const override {
        if (duration > escape_time / static_cast<T>(2))
            return static_cast<int>(damage_in_time);
        if (duration > static_cast<T>(1))
            return static_cast<int>(damage_in_time * static_cast<T>(2));
        return 0;
    }

    void applyDamage(Character& target) override {
        int damage = calculateDamage();
        if (damage > 0) {
            target.receiveDamage(damage);
        } else {
            deactivate();
            return;
        }
        duration -= static_cast<T>(1);
    }

    int getBaseDamage() const override {
        return static_cast<float>(damage_in_time * escape_time);
    }

    void deactivate() {
        active=false;
        reset();
    }

    void reset() {
        duration = initialDuration;
        active = false;
    }

    ~Quicksand() override = default;
};

#endif // QUICKSAND_H
