#include <iostream>
#include "BoardTile.h"
#include "BoardView.h"
#include "BoardTileController.h"
#include "time.h"
#include <SFML/Graphics.hpp>
#include "MenuVIew.h"
#include "MenuController.h"
#include "GameManager.h"

int main() {
    srand( static_cast<int>( time( NULL ) ) );

    BoardTile bt(4,4);

    BoardView bv(bt);
    BoardTileController bc(bv,bt);
    MenuVIew mv;
    MenuController mc(mv,bt);
    GameManager gm(bt,bc,mc);


    bt.debug_display();





    sf::RenderWindow window(sf::VideoMode(1000, 1000), "2048");


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            gm.handleEvent(event);

        }


        window.clear(sf::Color::Black);
        gm.drawOn(window);


        window.display();

    }

    return 0;
    }











