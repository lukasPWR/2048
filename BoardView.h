//
// Created by User on 05.06.2020.
//

#ifndef PUZZLE_BOARDVIEW_H
#define PUZZLE_BOARDVIEW_H

#include <SFML/Graphics.hpp>
#include "BoardTile.h"
#include <vector>


class BoardView {

    BoardTile & board;
    sf::RectangleShape tile_0,tile_2,tile_4,tile_8,tile_16,tile_32,tile_64,tile_128,tile_256,tile_512,tile_1024,tile_2048;
    sf::Texture tile2_txt,tile4_txt,tile8_txt,tile16_txt,tile32_txt,tile64_txt,tile128_txt,tile256_txt,tile512_txt,tile1024_txt,tile2048_txt;
    sf::Font font_sc;
    sf::Text score, space;







public:
    BoardView (BoardTile & b);
    void drawOnWindow(sf::RenderWindow & win);

};


#endif //PUZZLE_BOARDVIEW_H
