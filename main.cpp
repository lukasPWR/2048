#include <iostream>
#include "BoardTile.h"
#include "BoardView.h"
#include "BoardTileController.h"
#include "time.h"
#include <SFML/Graphics.hpp>

int main() {
    srand( static_cast<int>( time( NULL ) ) );

    BoardTile bt(4,4);
    BoardView bv(bt);
    BoardTileController bc(bv,bt);
    bt.debug_display();





    sf::RenderWindow window(sf::VideoMode(1000, 1000), "2048");


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            bc.handleEvent(event);
        }


        window.clear(sf::Color::Black);
        bv.drawOnWindow(window);


        window.display();

    }

    return 0;
    }











