//
// Created by User on 05.06.2020.
//

#include "BoardView.h"

BoardView::BoardView(BoardTile &b): board(b)
{

}


void BoardView::drawOnWindow(sf::RenderWindow &win) {
//grid
        int height = board.getBoardHeight();
        int width = board.getBoardWidth();
        int x = 170;
        int y = 170;


        sf::RectangleShape tile_0(sf::Vector2f(x, y));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(board.getFieldInfo(j,i)=='0')
                {
                tile_0.setFillColor(sf::Color(138, 121, 121));
                tile_0.setOutlineThickness(3);
                tile_0.setOutlineColor(sf::Color::White);
                tile_0.setPosition(x * i + x, y * j + y);
                win.draw(tile_0);
                }
                if(board.getFieldInfo(j,i)=='2')
                {
                    if (!tile2_txt.loadFromFile("2.jpg"))
                    {
                        cout << "error" << endl;
                        system("pause");

                    }

                    tile_2.setTexture(& tile2_txt);
                    tile_2.setSize(sf::Vector2f(x,y));
                    tile_2.setOutlineThickness(3);
                    tile_2.setOutlineColor(sf::Color::White);
                    tile_2.setPosition(x * i + x, y * j + y);
                    win.draw(tile_2);
                }
                if(board.getFieldInfo(j,i)=='4')
                {
                    if (!tile4_txt.loadFromFile("4.jpg"))
                    {
                        cout << "error" << endl;
                        system("pause");

                    }
                    tile_4.setTexture(& tile4_txt);
                    tile_4.setSize(sf::Vector2f(x,y));
                    tile_4.setOutlineThickness(3);
                    tile_4.setOutlineColor(sf::Color::White);
                    tile_4.setPosition(x * i + x, y * j + y);
                    win.draw(tile_4);
                }
            }
        }

        if (!font_sc.loadFromFile("wynik.ttf"))
        {
            std::cout << "error " << std::endl;
            system("pause");
        }

        score.setFont(font_sc);
        score.setCharacterSize(y/2);
        score.setFillColor(sf::Color::White);
        score.setPosition(x *2.2, 0);
        score.setString("Wynik:" + std::to_string(board.getScore()));
        win.draw(score);





    }


