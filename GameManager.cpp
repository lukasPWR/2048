//
// Created by User on 16.06.2020.
//

#include "GameManager.h"
GameManager::GameManager(BoardTile &b, BoardTileController &bc, MenuController &mc): board(b), boardC(bc), menuC(mc)
{
    state = GAME;
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
void GameManager::drawOn(sf::RenderWindow &win)
{
    switch (state)
    {
        case MENU:
            menuC.draw(win);
            break;
        case GAME:
            boardC.draw(win);
            break;

    }
}
