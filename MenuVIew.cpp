//
// Created by User on 15.06.2020.
//

#include "MenuVIew.h"
MenuVIew::MenuVIew()
{




}
void MenuVIew::drawOnWindow(sf::RenderWindow &win)
{
    int x =1000;
    int y = 1000;
    playButton.setSize(sf::Vector2f(x / 3, y / 12));
    playButton.setPosition(x / 3,y - y / 4);
    playButton.setFillColor(sf::Color(255,128,0));

    if (!font_1.loadFromFile("arial-black.ttf"))
    {
        std::cout << "error " << std::endl;
        system("pause");
    }
    text_1.setFont(font_1);
    text_1.setCharacterSize(y/30);
    text_1.setString("GRAJ");
    text_1.setFillColor(sf::Color::Red);
    text_1.setPosition(x/2.2, y - y/4.3);

    if (!font_2.loadFromFile("2048g.ttf"))
    {
        std::cout << "error " << std::endl;
        system("pause");
    }
    text_2.setFont(font_2);
    text_2.setCharacterSize(y/6);
    text_2.setPosition(x/12,y/5);
    text_2.setString("2048 GAME");
    text_2.setFillColor(sf::Color(255,128,0));

    if (!background_txt.loadFromFile("background.jfif")) {
        cout << "error" << endl;
        system("pause");

    }
    background.setTexture(&background_txt);
    background.setSize(sf::Vector2f(x, y));
    win.draw(background);
    win.draw(playButton);
    win.draw(text_1);
    win.draw(text_2);


}
