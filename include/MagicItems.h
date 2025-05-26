#ifndef MAGICITEMS_H
#define MAGICITEMS_H
#include "Weapon.h"
#include "Spell.h"

class MagicItems : public Spell, public Weapon{
private:
    int maxTargets;
    bool secundaryEffect;
    int duration;
    int charges;
    std::string rarity;
public:
    MagicItems(float castTime, int Sx, int Sy, int Sw, int Sh, bool canHeal, const std::string &name,
        int damage, int durability, int attackRange, const std::string &specialeffect, bool isBroken,
        const std::string &basic_string, int damage1, int max_targets, bool secundary_effect,
        int duration, int charges, const std::string &rarity);
    ~MagicItems() override;
    MagicItems(const MagicItems &other);
    MagicItems& operator=(const MagicItems &other);
    int levelFromItems() const override;

    //using Weapon::giveDamage;
    void giveDamage(const std::list<Ghost*>& ghosts) override;
};


#endif