//
// Created by User on 06.06.2020.
//

#include "BoardTileController.h"

BoardTileController::BoardTileController(BoardView &v, BoardTile &b): view(v), board(b)
{
    again = false;
    finished = false;
}

void BoardTileController::handleEvent(sf::Event &event)
{
    if( event.type == sf::Event::KeyPressed )
    {
        if(event.key.code==sf::Keyboard::Down)
        {
            board.move(DOWN);
            board.addTile();

        }
        if(event.key.code==sf::Keyboard::Up)
        {
            board.move(UP);
            board.addTile();


        }
        if(event.key.code==sf::Keyboard::Left)
        {
            board.move(LEFT);
            board.addTile();


        }
        if(event.key.code==sf::Keyboard::Right)
        {
            board.move(RIGHT);
            board.addTile();

        }
    }


    if (board.getIsDone()==true && board.getIsMoved()==false)
    {


        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
            {
                finished = true;
            }
        }
    }


}
