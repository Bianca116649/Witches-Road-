#ifndef WEAPON_H
#define WEAPON_H
#include "Items.h"
#include "Spikes.h"

class Weapon: virtual public Items {
protected:
    int durability;
    int attackRange;
    std::string specialeffect;
    bool isBroken;
    Spikes* spikes;

public:
    Weapon(int durability, [[maybe_unused]] int attackRange, [[maybe_unused]] const std::string& specialeffect,
        [[maybe_unused]] bool isBroken, const std::string& name, int damage, Spikes* spikes);
    Weapon(int durability, int attackRange, const std::string& specialeffect,bool isBroken,
      const std::string& name, int damage);

    Weapon(const Weapon &other);

    Weapon& operator=(const Weapon &other);

    ~Weapon() override;

    void giveDamage() override;
    int levelFromItems() const override;
};

#endif