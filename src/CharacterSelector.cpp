#include "../include/CharacterSelector.h"
#include "../include/Factory.h"
#include "../include/DefaultCharacterCreator.h"
#include <iostream>

std::pair<std::shared_ptr<Character>, std::shared_ptr<Character>> CharacterSelector::createCharacters(){
    const auto characters = CharacterFactory::createAllCharacters();
    std::cout<<"Available characters: \n";
    for(size_t i=0; i<characters.size(); i++){
        std::cout<<i<<": ";
        characters[i]->displayInfo();
    }
    int i1, i2;
    std::cout<<"Choose the first character (0 or 1): "; std::cin>>i1;
    std::cout<<"Choose the second character (2 or 3): "; std::cin>>i2;
    if (i1>=0 && i1<=1 && i2>=2 && i2<=3){
        return {characters[i1], characters[i2]};
    }else {
        std::cout<<"Invalid indices. Default characters are creating.\n";
        return DefaultCharacterCreator().createCharacters();
    }

}