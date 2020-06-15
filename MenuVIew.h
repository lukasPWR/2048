//
// Created by User on 15.06.2020.
//

#ifndef PUZZLE_MENUVIEW_H
#define PUZZLE_MENUVIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;




class MenuVIew {

    sf::Font font_1,font_2;
    sf::Text text_1, text_2;
    sf::RectangleShape playButton,background;
    sf::Texture background_txt;
public:
    MenuVIew ();
    void drawOnWindow(sf::RenderWindow &win);

};


#endif //PUZZLE_MENUVIEW_H
