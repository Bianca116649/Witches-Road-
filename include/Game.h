#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <memory>
#include "Character.h"
#include "Map.h"

class Game {

private:
    std::shared_ptr<Map> map;
    std::shared_ptr<Character> caracter1;
    std::shared_ptr<Character> caracter2;
    bool gameOn;
    std::string lvl_name;
    static Game* instancePtr;
    int score;
    std::string player1;
    std::string player2;
    Game() : map(std::make_shared<Map>()),gameOn(true), lvl_name("_"), score(0) {}

public:

    Game(const Game& obj) = delete;
    ~Game();
    static Game& getInstance();
    void run();
    void chooseCharacter();
    void start();
    void selectLevel();
    void verifyPosition(Character& c) const;
    void stop();
    void moveCharacter();
    void updateScore(int points);
    friend std::istream& operator>>(std::istream& is, Game& game);
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif //GAME_H
