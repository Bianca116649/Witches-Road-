#ifndef DEITY_H
#define DEITY_H

#include "Character.h"

class Deity : public Character {
private:
    int flySpeed;
    int flyHeight;
    bool immortal;
    int reincarnation{};
    std::string powers;
    std::string symbol;

public:

    Deity(const std::string& name, int posX, int posY, int level, int strength,
          int flySpeed, int flyHeight, bool immortal, const std::string& powers, const std::string& symbol);

    Deity(const Deity& other);
    Deity& operator=(const Deity& other);
    ~Deity() override;

    int getFlySpeed() const;
    int getFlyHeight() const;
    bool isImmortal() const;
    const std::string& getPowers() const;
    const std::string& getSymbol() const;
    void back_in_game();
    void receiveDamage(int damage) override;

    void displayInfo() const override;

    friend std::ostream& operator<<(std::ostream& out, const Deity& d);
};

#endif // DEITY_H