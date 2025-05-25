
#ifndef LEVELONECONFIGURATOR_H
#define LEVELONECONFIGURATOR_H
#include "ILevelConfigurator.h"
#include "Map.h"

class LevelOneConfigurator: public ILevelConfigurator{
public:
    void setup(Map& map) override;
};
#endif //LEVELONECONFIGURATOR_H