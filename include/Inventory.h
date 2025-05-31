#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include "MagicItems.h"

class Inventory {
private:
    std::vector<std::shared_ptr<Items>> items;

public:
    Inventory() = default;

    void addItems(const std::shared_ptr<Items>& item);

    int LvlfromItem();

    void sortItems();

    void printSort();
    std::vector<std::shared_ptr<Items>>& getItems();
    ~Inventory()=default;
    friend std::ostream& operator<<(std::ostream& os, const Inventory& inventory);
};

#endif

