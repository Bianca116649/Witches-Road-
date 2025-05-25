#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using namespace std;

class Character {

protected:
    std::string name;
    int posX, posY;
    int level;
    int strength;
    int health;

public:
    Character();
    explicit Character(const std::string& name, int pos1, int pos2, int level, int strength);
    virtual ~Character() = default;

    Character& operator=(const Character& copy);
    Character(const Character& copy);

    int getX() const;
    int getY() const;
    void move(int dx, int dy);
    const std::string& getName() const;
    int getLevel() const;
    int getStrength() const;
    int getHealth() const;

    virtual void receiveDamage(int damage)=0;

    Character& operator*=(int factor);

    virtual void displayInfo() const;
    friend ostream& operator<<(ostream& out, const Character& c);
};

#endif // CHARACTER_H