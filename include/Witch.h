#ifndef WITCH_H
#define WITCH_H
#include "Character.h"

class Witch : public Character {
private:
    bool isAlive;
    int life;
    int speed;
    bool hasAnimal;
    std::string covenName;

public:

    Witch(bool isAlive, const std::string& name, int posX, int posY, int level, int strength,
          int life, int speed, bool hasAnimal, const std::string& covenName);

    Witch(const Witch& other);
    Witch& operator=(const Witch& other);
    ~Witch() override;

    int getLife() const;
    int getSpeed() const;
    const std::string& getCovenName() const;
    bool isAliveStatus() const;

    void receiveDamage(int damage) override;

    void displayInfo() const override;

    friend std::ostream& operator<<(std::ostream& out, const Witch& w);
};

#endif // WITCH_H
