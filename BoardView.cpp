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
            if (board.getFieldInfo(j, i) == '0') {
                tile_0.setFillColor(sf::Color(138, 121, 121));
                tile_0.setOutlineThickness(3);
                tile_0.setOutlineColor(sf::Color::White);
                tile_0.setPosition(x * i + x, y * j + y);
                win.draw(tile_0);
            }
            if (board.getFieldInfo(j, i) == '1') {
                if (!tile2_txt.loadFromFile("2.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_2.setTexture(&tile2_txt);
                tile_2.setSize(sf::Vector2f(x, y));
                tile_2.setOutlineThickness(3);
                tile_2.setOutlineColor(sf::Color::White);
                tile_2.setPosition(x * i + x, y * j + y);
                win.draw(tile_2);
            }
            if (board.getFieldInfo(j, i) == '2') {
                if (!tile4_txt.loadFromFile("4.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }
                tile_4.setTexture(&tile4_txt);
                tile_4.setSize(sf::Vector2f(x, y));
                tile_4.setOutlineThickness(3);
                tile_4.setOutlineColor(sf::Color::White);
                tile_4.setPosition(x * i + x, y * j + y);
                win.draw(tile_4);
            }
            if(board.getFieldInfo(j,i)=='3')
            {
                if (!tile8_txt.loadFromFile("8.jpg"))
                {
                    cout << "error" << endl;
                    system("pause");

                }
                tile_8.setTexture(& tile8_txt);
                tile_8.setSize(sf::Vector2f(x,y));
                tile_8.setOutlineThickness(3);
                tile_8.setOutlineColor(sf::Color::White);
                tile_8.setPosition(x * i + x, y * j + y);
                win.draw(tile_8);
            }
            if (board.getFieldInfo(j, i) == '4') {
                if (!tile16_txt.loadFromFile("16.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_16.setTexture(&tile16_txt);
                tile_16.setSize(sf::Vector2f(x, y));
                tile_16.setOutlineThickness(3);
                tile_16.setOutlineColor(sf::Color::White);
                tile_16.setPosition(x * i + x, y * j + y);
                win.draw(tile_16);
            }
            if (board.getFieldInfo(j, i) == '5') {
                if (!tile32_txt.loadFromFile("32.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_32.setTexture(&tile32_txt);
                tile_32.setSize(sf::Vector2f(x, y));
                tile_32.setOutlineThickness(3);
                tile_32.setOutlineColor(sf::Color::White);
                tile_32.setPosition(x * i + x, y * j + y);
                win.draw(tile_32);
            }
            if (board.getFieldInfo(j, i) == '6') {
                if (!tile64_txt.loadFromFile("64.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_64.setTexture(&tile64_txt);
                tile_64.setSize(sf::Vector2f(x, y));
                tile_64.setOutlineThickness(3);
                tile_64.setOutlineColor(sf::Color::White);
                tile_64.setPosition(x * i + x, y * j + y);
                win.draw(tile_64);
            }
            if (board.getFieldInfo(j, i) == '7') {
                if (!tile128_txt.loadFromFile("128.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_128.setTexture(&tile128_txt);
                tile_128.setSize(sf::Vector2f(x, y));
                tile_128.setOutlineThickness(3);
                tile_128.setOutlineColor(sf::Color::White);
                tile_128.setPosition(x * i + x, y * j + y);
                win.draw(tile_128);
            }
            if (board.getFieldInfo(j, i) == '8') {
                if (!tile256_txt.loadFromFile("256.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_256.setTexture(&tile256_txt);
                tile_256.setSize(sf::Vector2f(x, y));
                tile_256.setOutlineThickness(3);
                tile_256.setOutlineColor(sf::Color::White);
                tile_256.setPosition(x * i + x, y * j + y);
                win.draw(tile_256);
            }
            if (board.getFieldInfo(j, i) == '9') {
                if (!tile512_txt.loadFromFile("512.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_512.setTexture(&tile512_txt);
                tile_512.setSize(sf::Vector2f(x, y));
                tile_512.setOutlineThickness(3);
                tile_512.setOutlineColor(sf::Color::White);
                tile_512.setPosition(x * i + x, y * j + y);
                win.draw(tile_512);
            }
            if (board.getFieldInfo(j, i) == 'x') {
                if (!tile1024_txt.loadFromFile("1024.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_1024.setTexture(&tile1024_txt);
                tile_1024.setSize(sf::Vector2f(x, y));
                tile_1024.setOutlineThickness(3);
                tile_1024.setOutlineColor(sf::Color::White);
                tile_1024.setPosition(x * i + x, y * j + y);
                win.draw(tile_1024);
            }
            if (board.getFieldInfo(j, i) == 'z') {
                if (!tile2_txt.loadFromFile("2048.jpg")) {
                    cout << "error" << endl;
                    system("pause");

                }

                tile_2048.setTexture(&tile2048_txt);
                tile_2048.setSize(sf::Vector2f(x, y));
                tile_2048.setOutlineThickness(3);
                tile_2048.setOutlineColor(sf::Color::White);
                tile_2048.setPosition(x * i + x, y * j + y);
                win.draw(tile_2048);
            }


        }

    }

    if (!font_sc.loadFromFile("wynik.ttf")) {
        std::cout << "error " << std::endl;
        system("pause");
    }

    score.setFont(font_sc);
    score.setCharacterSize(y / 2);
    score.setFillColor(sf::Color::White);
    score.setPosition(x * 2.2, 0);
    score.setString("Wynik:" + std::to_string(board.getScore()));
    win.draw(score);



}
