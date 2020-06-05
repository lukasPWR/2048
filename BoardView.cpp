//
// Created by User on 05.06.2020.
//

#include "BoardView.h"

BoardView::BoardView(BoardTile &b): board(b)
{

}

void BoardView::drawOnWindow(sf::RenderWindow &win)
{
//grid
    int height = board.getBoardHeight();
    int width = board.getBoardWidth();
    int x = 170;
    int y = 170;

    sf::RectangleShape tile_0(sf::Vector2f(x, y));
    for( int i = 0; i <height; ++i){
        for(int j = 0; j <width; ++j)
        {
            tile_0.setFillColor(sf::Color::Red);
            tile_0.setOutlineThickness(3);
            tile_0.setOutlineColor(sf::Color::White);

            tile_0.setPosition(x*i+x,y*j+y);
            win.draw(tile_0);
        }
    }





}
