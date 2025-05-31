#include "../include/Spell.h"
#include "../include/Items.h"
#include <list>


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

void Spell::setGhost(const std::list<Ghost*> &ghosts) {
    keptGhosts.clear();
    for (Ghost* ghost : ghosts) {
        if (!ghost || !ghost->isAlive()) continue;
        const int x = ghost->getX();
        const int y = ghost->getY();
        if (inArea(x, y)) {
            keptGhosts.push_back(ghost);
        }

    }
}
void Spell::giveDamage(){
   for (Ghost* ghost : keptGhosts) {
       ghost->takeDamage(100);
   }
}

Spell::~Spell() =default;

bool Spell::inArea(const int x, const int y) const{
    return x >=Sx && x<=Sx+Sw && y>=Sy && y<=Sy+Sh;
}