//
// Created by User on 16.06.2020.
//

#ifndef PUZZLE_MENUCONTROLLER_H
#define PUZZLE_MENUCONTROLLER_H

#include "SFML/Graphics.hpp"
#include "MenuVIew.h"
#include "BoardTile.h"



class MenuController {
    BoardTile &board;
    MenuVIew &view;

    bool finished= false;
public:
    explicit MenuController(MenuVIew &mv, BoardTile &b);
    void handleEvent(sf::Event &event);
    void drawOnWindow(sf::RenderWindow & win) { view.drawOnWindow(win); }
    void setFinishedToFalse() { finished = false; }
    bool isFinished() const {return finished;}


};


#endif //PUZZLE_MENUCONTROLLER_H
