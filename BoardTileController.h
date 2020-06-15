//
// Created by User on 06.06.2020.
//

#ifndef PUZZLE_BOARDTILECONTROLLER_H
#define PUZZLE_BOARDTILECONTROLLER_H

#include "BoardView.h"
#include "BoardTile.h"


class BoardTileController {
    BoardView & view;
    BoardTile & board;
    bool finished=false;
    bool again=false;
public:
    BoardTileController(BoardView &v, BoardTile &b);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow & win) { view.drawOnWindow(win); }
    bool isFinished() const { return finished; }
    void playAgain() { board.play_again(); }
    void setFinishedToFalse() { finished = false; }



};


#endif //PUZZLE_BOARDTILECONTROLLER_H
