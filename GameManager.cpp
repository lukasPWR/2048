//
// Created by User on 16.06.2020.
//

#include "GameManager.h"
GameManager::GameManager(BoardTile &b, BoardTileController &bc, MenuController &mc): board(b), boardC(bc), menuC(mc)
{
    state = MENU;
}
void GameManager::update()
{
    switch(state)
    {
        case MENU:
            if(menuC.isFinished())
            {
                state = GAME;
            }
            break;
        case GAME:
            if(boardC.isFinished())
            {
                menuC.setFinishedToFalse();
                state = MENU;
                boardC.setFinishedToFalse();
                boardC.playAgain();

            }
            break;
    }
}
void GameManager::handleEvent(sf::Event &event)
{
    switch (state)
    {
        case MENU:
            menuC.handleEvent(event);
            break;
        case GAME:
            boardC.handleEvent(event);
            break;
    }
    update();
}
void GameManager::drawOnWindow(sf::RenderWindow &win)
{
    switch (state)
    {
        case MENU:
            menuC.drawOnWindow(win);
            break;
        case GAME:
            boardC.draw(win);
            break;

    }
}
