#ifndef LEVELTWOCONFIGURATOR_H
#define LEVELTWOCONFIGURATOR_H
#include "ILevelConfigurator.h"
#include "LevelTwoConfigurator.h"
#include "Map.h"

class LevelTwoConfigurator: public ILevelConfigurator{
public:
    void setup(Map& map) override;
};
#endif //LEVELTWOCONFIGURATOR_H
