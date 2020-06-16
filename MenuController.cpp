//
// Created by User on 16.06.2020.
//

#include "MenuController.h"
MenuController::MenuController(MenuVIew &mv, BoardTile &b):  board(b),view(mv)
{

}
void MenuController::handleEvent(sf::Event &event)
{
   int x=1000;
   int y=1000;
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if ((event.mouseButton.x > x / 3) && (event.mouseButton.x < x / 3 + x / 3) && (event.mouseButton.y > y- y / 4) && (event.mouseButton.y < y - y / 4 + y / 12))
            {
                finished = true;
            }
        }
    }
}

