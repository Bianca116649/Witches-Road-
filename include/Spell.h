#ifndef SPELL_H
#define SPELL_H
#include "Ghost.h"
#include "Items.h"

#include<list>
class Spell : public virtual Items{
protected:
    float castTime;
    int Sx, Sy, Sw, Sh;  // raza vrajii
    bool canHeal;

public:

    Spell(float castTime, int Sx, int Sy, int Sw, int Sh, bool canHeal);

    ~Spell() override;

    Spell(const Spell &other);
    Spell& operator=(const Spell &other);
    using Items::giveDamage;
    virtual void giveDamage(const std::list<Ghost*>& ghosts);
    bool inArea(int x, int y) const;
    int levelFromItems() const override;
};

#endif //SPELL_H