#ifndef WEAPON_H
#define WEAPON_H
#include "Items.h"
#include "Spikes.h"

class Weapon: public virtual Items {
protected:
    int durability;
    int attackRange{};
    std::string specialeffect;
    bool isBroken{};
    Spikes* spikes{};

public:
    Weapon(int durability, int attackRange, const std::string& specialeffect,
        bool isBroken, Spikes* spikes);
    Weapon(int durability, int attackRange, const std::string& specialeffect,bool isBroken);

    Weapon(const Weapon &other);

    Weapon& operator=(const Weapon &other);

    ~Weapon() override;

    void giveDamage() override;

    int levelFromItems() const override;
};

#endif