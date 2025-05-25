#include "../include/LevelOneConfigurator.h"
#include "../include/Spikes.h"
#include "../include/Map.h"

void LevelOneConfigurator::setup(Map& map){
    std::vector<std::pair<int, int>> positions = {{3,3}, {6,6}, {9,9} ,{12,12}, {1, 1}, {3,10}, {17, 8}};
    for(const auto& position : positions){
        auto spikes = std::make_shared<Spikes>();
        spikes->setPosition(position.first, position.second);
        spikes->setName("^");
        map.adaugaObstacol(spikes);
    }
}