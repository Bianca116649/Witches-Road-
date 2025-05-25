#ifndef ICHARACTERCREATOR_H
#define ICHARACTERCREATOR_H
#include "Character.h"
#include<memory>

class ICharacterCreator {
public:
    virtual ~ICharacterCreator() = default;
    virtual std::pair<std::shared_ptr<Character>, std::shared_ptr<Character>> createCharacters() =0;
};
#endif //ICHARACTERCREATOR_H