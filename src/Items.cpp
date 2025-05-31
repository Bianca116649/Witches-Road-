#include<iostream>
#include "../include/Items.h"

Items::Items(): id(count_id++), damage(0), name("_"){}

Items::Items(const int damage_, const std::string &name_):id(count_id++), damage(damage_), name(name_) {}

Items::~Items() = default;

int Items::count_id = 1;

Items::Items(const Items &other)
  : id(other.id),
    damage(other.damage),
    name(other.name) {
}

Items& Items:: operator=(const Items &other) {
    if (this == &other)
        return *this;
    damage = other.damage;
    name = other.name;
    id = other.id;
    return *this;
}

const std::string& Items::getName() const {
    return name;
}

int Items::getId() const {
    return id;
}

bool Items::operator<(const Items &other) const {
    return this->levelFromItems() < other.levelFromItems();

}

std::ostream& operator<<(std::ostream& os, const Items& items) {
    os<<items.getId()<<": "<<items.getName() << " " <<items.levelFromItems();
    return os;
}