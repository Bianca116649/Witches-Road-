#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include "Weapon.h"
#include "Spell.h"
#include "MagicItems.h"

class Inventory {
private:
    int totalPointsfromLvl = 0;
    std::vector<std::shared_ptr<Items>> items;

public:
    Inventory() = default;

    void addItems(const std::shared_ptr<Items>& item);

    int LvlfromItem();

    void sortItems();

    void printSort();

    ~Inventory()=default;
    friend std::ostream& operator<<(std::ostream& os, const Inventory& inventory);
};

#endif

