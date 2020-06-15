//
// Created by User on 16.06.2020.
//

#ifndef PUZZLE_GAMEMANAGER_H
#define PUZZLE_GAMEMANAGER_H

#include "BoardTile.h"
#include "BoardTileController.h"
#include "MenuController.h"


class GameManager {
    BoardTile &board;
    BoardTileController &boardC;
    MenuController &menuC;
    void update();
    enum GameState {MENU,GAME} state;
public:
    GameManager(BoardTile &b, BoardTileController &bc, MenuController &mc);
    void drawOn(sf::RenderWindow &win);
    void handleEvent(sf::Event &event);

};


#endif //PUZZLE_GAMEMANAGER_H
