#include "../include/Inventory.h"
#include<iostream>

#include <algorithm>
// void Inventory::addItems(const std::shared_ptr<Items>& item) {
//     items.push_back(item);
// }
//
// int Inventory::LvlfromItem() {
//     totalPointsfromLvl = 0;
//     for (const auto& item : items) {
//         totalPointsfromLvl += item->levelFromItems();
//     }
//     return totalPointsfromLvl;
// }
//
// void Inventory::sortItems(){
//     sort(this->items.begin(), this->items.end(), [](const std::shared_ptr<Items>& a, const std::shared_ptr<Items>&b)
//          {
//       return *a<*b;});
// }

std::ostream& operator<<(std::ostream& os, const Inventory& inventory) {
    for (const auto& item : inventory.items) {
        os << *item<<"\n";
    }
    return os;
}

// void Inventory::printSort(){
//     this->sortItems();
//     for(int i=0; i<items.size(); i++){
//         std::cout << *this;
//     }}