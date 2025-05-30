#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <Inventory.h>
#include <memory>
#include<list>
#include "Character.h"
#include "Map.h"

class Game {

private:
    std::ifstream f;
    std::shared_ptr<Map> map;
    std::shared_ptr<Character> caracter1;
    std::shared_ptr<Character> caracter2;
    bool gameOn;
    std::string lvl_name;
    static Game* instancePtr;
    int score;
    Inventory inventory;
    std::string player1;
    std::string player2;
    Game() : map(std::make_shared<Map>()),gameOn(true), lvl_name("_"), score(0) {}
    std::list<Ghost*> ghosts;

public:

    Game(const Game& obj) = delete;
    ~Game();
    static Game& getInstance();
    void run();
    void addItem();
    void chooseCharacter();
    void start();
    void selectLevel();
    void verifyPosition(Character& c);
    void stop();
    void moveCharacter();
    void updateScore(int points);
    void battle(Character& c, Obstacle& obs);
    friend std::istream& operator>>(std::istream& is, Game& game);
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif //GAME_H
