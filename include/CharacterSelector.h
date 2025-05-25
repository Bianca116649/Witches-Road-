#ifndef CHARACTERSELECTOR_H
#define CHARACTERSELECTOR_H
#include "ICharacterCreator.h"

class CharacterSelector : public ICharacterCreator{
    public :
        std::pair<std::shared_ptr<Character>, std::shared_ptr<Character>> createCharacters() override;

};

#endif //CHARACTERSELECTOR_H