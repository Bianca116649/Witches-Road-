#include "../include/LevelTwoConfigurator.h"
#include "../include/Quicksand.h"
#include "../include/Ghost.h"

void LevelTwoConfigurator::setup(Map& map){
    std::vector<std::pair<int, int>> positions = {{3,3}, {6,6}, {9,9} ,{12,12}, {1, 1}, {3,10}, {17, 8}};

    int i = 0;
    for (const auto& position : positions) {
        std::shared_ptr<Obstacle> sand;

        if (i % 2 == 0) {
            sand = std::make_shared<Quicksand<int>>(5, 25, "~~~", position.first, position.second, 5, true);
        }
        else {
            sand = std::make_shared<Quicksand<float>>(4.5f, 20.0f, "~~~", position.first, position.second, 3.0f, true);
        }

        map.adaugaObstacol(sand);
        ++i;
    }
    std::vector<std::pair<int, int>> positions_= {{4,3}, {6,10}, {7,12} ,{10,9}, {20, 10}, {20,1}, {23,4}};
    for(const auto& pos : positions_){
        auto ghost=std::make_shared<Ghost>();
        ghost-> setPosition(pos.first, pos.second);
        ghost-> setName("0--");
        map.adaugaObstacol(ghost);
    }
}