#ifndef ILEVELCONFIGURATOR_H
#define ILEVELCONFIGURATOR_H
#include "Map.h"
class ILevelConfigurator{
    public :
      virtual void setup(Map& map) = 0;
    virtual ~ILevelConfigurator()=default;
};
#endif //ILEVELCONFIGURATOR_H