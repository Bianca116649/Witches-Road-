#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <vector>
#include "Character.h"

class CharacterFactory {
public:
    static std::shared_ptr<Character> createCharacter(const std::string& type) ;
    static std::vector<std::shared_ptr<Character>> createAllCharacters();
};

#endif //FACTORY_H