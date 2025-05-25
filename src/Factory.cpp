#include "../include/Factory.h"
#include "../include/Witch.h"
#include "../include/Deity.h"
#include "../include/Character.h"

std::shared_ptr<Character> CharacterFactory::createCharacter(const std::string& type) {
    if (type == "Witch") {
        return std::make_shared<Witch>(true, "Witch Original" ,0, 0, 1, 10, 100, 20, true, "Harkness");
    }
    if (type == "Deity") {
        return std::make_shared<Deity>("Deity Original" ,29, 14, 1, 100, 30, 50, true, "Death", "Nature");
    }
    return nullptr;
}
std::vector<std::shared_ptr<Character>> CharacterFactory::createAllCharacters() {
    std::vector<std::shared_ptr<Character>> characters;
    characters.push_back(std::make_shared<Witch>(true, "Agatha", 0,0,3,30,100,21,true,"Harkness"));
    characters.push_back(std::make_shared<Witch>(true, "Billy", 0,0,0,45,100,20,false,"Maximoff"));
    characters.push_back(std::make_shared<Deity>("Rio" ,29, 14, 60, 100, 200, 100, true, "Death", "Nature"));
    characters.push_back(std::make_shared<Deity>("Mrs. Heart" ,29, 14, 10, 5, 50, 10, false, "Death", "Nature"));

    return characters;
}


