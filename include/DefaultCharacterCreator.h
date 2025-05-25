#ifndef DEFAULTCHARACTERCREATOR_H
#define DEFAULTCHARACTERCREATOR_H
#include "ICharacterCreator.h"

class DefaultCharacterCreator: public ICharacterCreator{
public:
    std::pair<std::shared_ptr<Character>, std::shared_ptr<Character>> createCharacters() override;
};

#endif //DEFAULTCHARACTERCREATOR_H