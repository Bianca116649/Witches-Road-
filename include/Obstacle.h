#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <string>

class Character;
class Obstacle {
protected:
    std::string name;
    int totalDamage;
    int positionX;
    int positionY;
    bool active;
public:
    Obstacle(const std::string& name, int damage, int x, int y, bool active);

    Obstacle();

    Obstacle(const std::string &name, int damage, int x, int y);

    virtual ~Obstacle();

    virtual int getBaseDamage() const = 0; //damage-ul original pe care il are fiecare obstacol

    virtual int calculateDamage() const=0; //calculeaza damage-ul actual cu modificari

    const std::string& getName() const;

    int getX() const;

    int getY() const;

    void setName(const std::string& Newname);

    void setPosition(int x, int y);

    virtual void applyDamage(Character& target) = 0;

    virtual void activate(Character& target) = 0;
    int isActive() const;


};

#endif // OBSTACLE_H