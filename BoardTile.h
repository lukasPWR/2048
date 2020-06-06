//
// Created by User on 20.05.2020.
//

#ifndef PUZZLE_BOARDTILE_H
#define PUZZLE_BOARDTILE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include<cstdio>
#include<unistd.h>
using namespace std;
typedef unsigned int uint;
enum Direction {UP, DOWN, LEFT, RIGHT};



struct Tile
        {
    uint value ;
    bool isBlocked;
        };


class BoardTile {
    vector<vector<Tile>> board;
    bool isWin;
    bool isDone;
    bool isMoved;

    uint score;
    int cols;
    int rows;



    Direction direction;



public:
    BoardTile(int cols, int rows);

    void setBoard( int cols, int rows);
    void debug_display() const;
    bool getIsMoved() {return isMoved;}
    bool getIsDone() {return isDone;}
    bool getIsWin() {return isWin;}
    int getScore() {return score;};
    int getBoardHeight() const { return rows; }
    int getBoardWidth() const { return cols; }
    char getFieldInfo(int x, int y) const;
    int getValue(int x, int y);
    void play_again();
    bool checkAdd(int x, int y, uint v) ;
    bool canMove() ;
    void addTile();
    void moveHorizontal(int x, int y, int d);
    void moveVertical(int x, int y, int d);
    void move(Direction d);












};


#endif //PUZZLE_BOARDTILE_H
