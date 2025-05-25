#include "../include/DefaultCharacterCreator.h"
#include "../include/Witch.h"
#include "../include/Factory.h"
#include<memory>

std::pair<std::shared_ptr<Character>, std::shared_ptr<Character>> DefaultCharacterCreator::createCharacters() {
    auto witch = CharacterFactory::createCharacter("Witch");
    auto deity = CharacterFactory::createCharacter("Deity");
    witch->displayInfo();
    deity->displayInfo();
    return {witch, deity};
}