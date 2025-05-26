#include "../include/Spell.h"
#include "../include/Items.h"
#include <list>

Spell::Spell() : Items(), castTime(0), Sx(0), Sy(0), Sw(0), Sh(0), canHeal(false) {
}

Spell::Spell(const float castTime, const int Sx, const int Sy, const int Sw, const int Sh, const bool canHeal)
        :castTime(castTime), Sx(Sx), Sy(Sy), Sw(Sw), Sh(Sh), canHeal(canHeal){}

Spell::Spell(const Spell &other)=default;

Spell& Spell:: operator=(const Spell &other) {
    if (this == &other) {
        return *this;
    }

    castTime = other.castTime;
    Sx = other.Sx;
    Sy = other.Sy;
    Sw = other.Sw;
    Sh = other.Sh;
    canHeal = other.canHeal;
    return *this;
}

int Spell::levelFromItems() const {
    return Sw * Sh;
}

void Spell::giveDamage(const std::list<Ghost*>& ghosts){
    for (Ghost* ghost : ghosts) {
        if (!ghost || !ghost->isAlive()) continue;
        const int x = ghost->getX();
        const int y = ghost->getY();
        if (inArea(x, y)) {
            ghost->takeDamage(damage);
        }
    }
}

Spell::~Spell() =default;

bool Spell::inArea(const int x, const int y) const{
    return x >=Sx && x<=Sx+Sw && y>=Sy && y<=Sy+Sh;
}