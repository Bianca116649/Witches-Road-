#include "../include/MagicItems.h"
#include "../include/Spell.h"
#include "../include/Weapon.h"

MagicItems::MagicItems(float castTime, int Sx, int Sy, int Sw, int Sh, bool canHeal, const std::string &name,
                       int damage, int durability, int attackRange, const std::string &specialeffect, bool isBroken, int max_targets, bool secundary_effect, int duration, int charges, const std::string &rarity)
    : Items(damage, name),
Spell(castTime, Sx, Sy, Sw, Sh, canHeal),
      Weapon(durability, attackRange, specialeffect, isBroken),
maxTargets(max_targets), secundaryEffect(secundary_effect), duration(duration),
      charges(charges), rarity(rarity) {}


MagicItems::~MagicItems() = default;

MagicItems::MagicItems(const MagicItems &other)
        : Items(other),
          Spell(other),
          Weapon(other),
          maxTargets(other.maxTargets),
          secundaryEffect(other.secundaryEffect),
          duration(other.duration),
          charges(other.charges),
          rarity(other.rarity) {

}

MagicItems& MagicItems:: operator=(const MagicItems &other) {
    if (this == &other)
        return *this;
    Items::operator=(other);
    Spell::operator =(other);
    Weapon::operator =(other);
    maxTargets = other.maxTargets;
    secundaryEffect = other.secundaryEffect;
    duration = other.duration;
    charges = other.charges;
    rarity = other.rarity;
    this->damage = other.damage;
    this->name = other.name;
    return *this;
}

int MagicItems:: levelFromItems() const {
    return static_cast<int>(rarity.length());
}

void MagicItems::giveDamage() {
    if (isBroken || charges <=0)
        return;

    const int rarityBonus = static_cast<int>(rarity.length())*3;
    const int originalDamage = damage;
    damage += rarityBonus;

    Spell::giveDamage();

    if (canHeal) {
        for (Ghost* ghost : keptGhosts) {
            if (ghost && ghost->isAlive() && ghost->getPower()<50) {
                ghost->takeDamage(damage);
            }
        }
    }
    damage = originalDamage;

    Weapon::giveDamage();

    charges--;
    Weapon::durability-=2;
    if (Weapon::durability<=0)
        {Weapon::isBroken=true;}
}
