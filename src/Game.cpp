#include <iostream>
#include <memory>
#include <limits>
#include "Game.h"

#include <fstream>

#include "Exceptii.h"
#include "Map.h"
#include "../include/Factory.h"
#include "../include/Quicksand.h"
#include "../include/ICharacterCreator.h"
#include "../include/ILevelConfigurator.h"
#include "../include/LevelOneConfigurator.h"
#include "../include/LevelTwoConfigurator.h"
#include "../include/DefaultCharacterCreator.h"
#include "../include/CharacterSelector.h"

Game::~Game()=default;

Game* Game::instancePtr=nullptr;

Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::start() {
    f.open("tastatura.txt");
    std::cout << "GAME START\n";
    f>>*this;
    std::cout<<"Use A,S,D,W for WITCH and I,J,K,L,P for DEITY.\n";
    try {
        chooseCharacter();
        selectLevel();
    } catch (const eroareJoc& e) {
        std::cout << "Game Error: " << e.what() << std::endl;
        stop();
    }
}

void Game::addItem() {
    std::shared_ptr<Items> item = std::make_shared<Weapon>(100, 5, "Fire Damage", false, "FLaming Sward", 25);
    inventory.addItems(item);


}
void Game::chooseCharacter() {
    char input;
    std::unique_ptr<ICharacterCreator> creator;
    while (true) {
        std::cout<<"Do you want a default character? (Y/N)"<<std::endl;
        f>>input;
        input=tolower(input);
        if (input == 'y') {
            creator = std::make_unique<DefaultCharacterCreator>();
            break;
        } else if (input == 'n') {
            creator=std::make_unique<CharacterSelector>();
            break;
        } else {
            std::cout<<"Invalid input. Please enter Y or N.\n";
        }
    }
    auto [c1, c2] = creator->createCharacters();
    caracter1 = std::move(c1);
    caracter2 = std::move(c2);
    map->adauga(caracter1);
    map->adauga(caracter2);
    map->updateMap();
}

void Game::selectLevel() {
   bool select = false;
    int level;
    std::unique_ptr<ILevelConfigurator> configurator;

    while (!select) {
        try {
            std::cout<<"Please choose a level (1 or 2)."<<std::endl;
            if (!(f>>level)) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw inputInvalid("Input must be a number.");
            } else
                if (level == 1) {
                    configurator = std::make_unique<LevelOneConfigurator>();
                    select = true;
                }
            else
                if (level == 2) {
                    configurator= std::make_unique<LevelTwoConfigurator>();
                    select = true;
                }else throw inputInvalid("Please enter 1 or 2.");

        }catch (const eroareJoc& e) {
            std::cout<<"ERROR: "<<e.what()<<std::endl;
        }
    }
    configurator->setup(*map);
    map->updateMap();
    run();
}

void Game::run() {
    gameOn=true;
    std::cout<<"Game running...\nPress movement keys to control characters.\n";
    addItem();
    moveCharacter();
}

void Game::stop() {
    gameOn = false;
    std::cout<<"Final inventory:\n";
    inventory.printSort();
    std::cout<<"Total power received from items: "<<inventory.LvlfromItem()<<"\n";
    std::cout<<*this;
    std::cout << "Thanks for playing.\n";
}

void Game::moveCharacter() {
    std::cout<<"Game started. Press Q to quit.\n"<<std::endl;
    while (gameOn) {
        char input;
        std::cout<<"To move character enter: \n";
        std::cout<<"WITCH : W for up, A for left, D for right, S for down.\n";
        std::cout<<" DEITY : I for up, J for left, L for right, K for down.\n";
        f>>input;
        input=tolower(input);
        int dx=0, dy=0;
        Character* target = nullptr;

            switch (input) {
                case 'w': dy= -1; target = caracter1.get(); break;
                case 'a': dx= -1; target = caracter1.get(); break;
                case 's': dy= 1; target = caracter1.get(); break;
                case 'd': dx= 1; target = caracter1.get(); break;
                case 'i': dy = -1; target = caracter2.get(); break;
                case 'j': dx= -1; target = caracter2.get(); break;
                case 'k': dy= 1; target = caracter2.get(); break;
                case 'l': dx= 1; target = caracter2.get(); break;
                case 'q': stop(); break;
                default: std::cout<<"Invalid input.\n"; continue;
            }
        try {
            if (target == nullptr) {
                std::cout<<"No character selected.\n";
                continue;
            }
            if (map->canMove(*target, dx,dy)) {
                target ->move(dx,dy);
                verifyPosition(*target);
            }else {
                std::cout<<"Can't move outside the map\n";
            }
            map->updateMap();
        }catch (const eroareJoc& e) {
            std::cout<<"Movement error: "<<e.what()<<std::endl;
            stop();
        }
    }
}

void Game::verifyPosition(Character& c) const {
    auto obstacles = map->getObstacles();
    for (const auto& obs: obstacles) {
        if (obs->getX()==c.getX() && obs->getY()==c.getY()) {
            if (obs->isActive()) {
                obs->activate(c);
            }
            else std::cout<<"Inactive obstacle. You are safe.\n";
        }
    }
}

void Game::updateScore(const int points) {
    score += points;
}

std::istream& operator>>(std::istream& is, Game& game) {
    std::cout<<"Enter player's one name: \n";
    is>>game.player1;
    std::cout<<"Enter player's two name: \n";
    is>>game.player2;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    os<<"Game over!\n";
    os<<"Player one "<<game.player1<< " and"<< " player two "<<game.player2<< " finish with score "<<game.score<<endl;
    return os;
}