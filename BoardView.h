//
// Created by User on 05.06.2020.
//

#ifndef PUZZLE_BOARDVIEW_H
#define PUZZLE_BOARDVIEW_H

#include <SFML/Graphics.hpp>
#include "BoardTile.h"


class BoardView {

    BoardTile & board;




public:
    BoardView (BoardTile & b);
    void drawOnWindow(sf::RenderWindow & win);

};


#endif //PUZZLE_BOARDVIEW_H
