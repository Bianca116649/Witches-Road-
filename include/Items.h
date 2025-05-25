#ifndef ITEMS_H
#define ITEMS_H
#include<string>

class Items{
protected:
    int id;
    static int count_id;
    int damage;
    std::string name;
public:
    Items();
    Items(int damage_, const std::string &name_);
    Items(const Items &other);
    Items & operator=(const Items &other);
    virtual ~Items();

    virtual void giveDamage()=0;
    virtual int levelFromItems() const=0;
    bool operator<(const Items &other) const;
    const std::string& getName() const;
    int getId() const;
    //int getDamage() const;
    friend std::ostream& operator<<(std::ostream& os, const Items& items);
};

#endif
