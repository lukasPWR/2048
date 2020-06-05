#include <iostream>
#include "BoardTile.h"
#include "BoardView.h"
#include "time.h"
#include <SFML/Graphics.hpp>

int main() {
    srand( static_cast<int>( time( NULL ) ) );

    BoardTile bt(4,4);
    BoardView bv(bt);
    bt.debug_display();


 /* bt.debug_display();
  cout <<"-----------" << endl;
  bt.debug_display();
  bt.addTile();
  cout <<"---------"<< endl;
  bt.debug_display();
  bt.move(LEFT);
  cout << "========="<< endl;
  bt.debug_display();*/
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);
        bv.drawOnWindow(window);


        window.display();

    }

    return 0;
    }











