#ifndef SPELL_H
#define SPELL_H
#include "Ghost.h"
#include "Items.h"

#include<list>
class Spell : public virtual Items{
protected:
    float castTime;
    int requiredLvl;
    int Sx, Sy, Sw, Sh;  // raza vrajii
    bool canHeal;

public:

    Spell(float castTime, int requiredLvl, int Sx, int Sy, int Sw, int Sh, bool canHeal, const std::string &name, int damage);

    ~Spell() override;

    Spell(const Spell &other);
    Spell& operator=(const Spell &other);

    virtual void giveDamage(const std::list<Ghost*>& ghosts);
    bool inArea(int x, int y) const;
    int levelFromItems() const override;
};

#endif //SPELL_H