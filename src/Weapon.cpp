#include "../include/Weapon.h"
#include "../include/Spikes.h"

Weapon::Weapon(const int durability, const int attackRange, const std::string& specialeffect, const bool isBroken, Spikes*  spikes)
: durability(durability), attackRange(attackRange), specialeffect(specialeffect), isBroken(isBroken), spikes(spikes) {
    if (!spikes) {
        this -> spikes = new Spikes();
    }
}

Weapon::Weapon(const int durability, const int attackRange, const std::string& specialeffect, bool isBroken)
: durability(durability), attackRange(attackRange), specialeffect(specialeffect), isBroken(isBroken) {}

Weapon::Weapon(const Weapon &other)
  : Items(other),
    durability(other.durability),
    attackRange(other.attackRange),
    specialeffect(other.specialeffect),
    isBroken(other.isBroken),
    spikes(other.spikes) {
}

Weapon& Weapon:: operator=(const Weapon &other) {
    if (this == &other)
        return *this;
    durability = other.durability;
    attackRange = other.attackRange;
    specialeffect = other.specialeffect;
    isBroken = other.isBroken;
    spikes = other.spikes;
    return *this;
}

Weapon::~Weapon() {
    delete spikes;
}

int Weapon::levelFromItems() const {
    return 10;
}

void Weapon::giveDamage(){
    if (!spikes) {return; }

    if (spikes->getHeight()<attackRange) {
        spikes->deactivate();
    }
    else {
        while (spikes->isActive()==false && durability>0){
            spikes->takeDamage(5);
            durability -=5;
        }
    }
}
