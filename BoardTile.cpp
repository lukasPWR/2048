//
// Created by User on 20.05.2020.
//

#include "BoardTile.h"

BoardTile::BoardTile(int cols, int rows): cols(cols), rows(rows)
{

    isWin = false;
    isDone = false;
    isMoved = true;
    score = 0;



    setBoard(cols,rows);
    addTile();
}


void BoardTile::setBoard(int cols, int rows)
{

    cols =4;
    rows = 4;

    board.resize(4);
    for(int i=0; i<board.size();i++)
    {
        board.at(i).resize(4);
    }

    for(int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            board.at(i).at(j).value = 0;
            board.at(i).at(j).isBlocked = false;

        }
    }


}


void BoardTile::debug_display() const
{
    for(int i=0;i<cols;++i)
    {
        for(int j=0;j<rows;++j)
        {
            cout << getFieldInfo(i, j);
        }
        cout << endl;
    }


}
char BoardTile::getFieldInfo(int x, int y) const
{
    if(board.at(y).at(x).value == 0)
    {
        return '0';
    }
    if(board.at(y).at(x).value == 2)
    {
        return '2';
    }
    if(board.at(y).at(x).value == 4)
    {
        return '4';
    }
    if(board.at(y).at(x).value == 8)
    {
        return '8';
    }
    if(board.at(y).at(x).value == 16)
    {
        return '16';
    }
    if(board.at(y).at(x).value == 32)
    {
        return '32';
    }
    if(board.at(y).at(x).value == 64)
    {
        return '64';
    }
    if(board.at(y).at(x).value == 128)
    {
        return '128';
    }
    if(board.at(y).at(x).value == 256)
    {
        return '256';
    }
    if(board.at(y).at(x).value == 512)
    {
        return '512';
    }
    if(board.at(y).at(x).value == 1024)
    {
        return '1024';
    }
    if(board.at(y).at(x).value == 2048)
    {
        return '2048';
    }


}

int BoardTile::getValue(int x, int y)
{
    return board.at(y).at(x).value;
}

void BoardTile::play_again()
{
    board.clear();
    setBoard(cols,rows);
    addTile();
}
bool BoardTile::checkAdd(int x, int y, int v)
{
    if( x < 0 || x >3 || y < 0 || y> 3)
        return false;
    return board.at(y).at(x).value == v;


}
bool BoardTile::canMove()
{
    for( int i = 0; i < cols;i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if(checkAdd(i+1,j,board.at(i).at(j).value))
                return true;
            if(checkAdd(i-1,j,board.at(i).at(j).value))
                return true;
            if(checkAdd(i,j+1,board.at(i).at(j).value))
                return true;
            if(checkAdd(i,j-1,board.at(i).at(j).value))
                return true;
        }
    }
    return false;
}
void BoardTile::addTile()
{
    int a= 0;
    int b= 0;
            if(!board.at(a).at(b).value)
            {

            do{
                a = rand() %4;
                b = rand() %4;
            }
            while(board.at(a).at(b).value);
                int s = rand() % 100;
                if( s > 89 ) board[a][b].value = 4;
                else board.at(a).at(b).value = 2;
                if( canMove() ) return;
            }
            isDone = true;
}

void BoardTile::entryKey()
{
    isMoved = false;
    char c;
    cout << "(W)Up (S)Down (A)Left (D)Right "; cin >> c; c &= 0x5F;
    switch(c)
    {
        case 'W': move( UP );break;
        case 'A': move( LEFT ); break;
        case 'S': move( DOWN ); break;
        case 'D': move( RIGHT );
    }
    for( int y = 0; y < cols; y++ )
        for( int x = 0; x < rows; x++ )
            board.at(y).at(x).isBlocked = false;
}

void BoardTile::moveVertical(int x, int y, int d)
{
    if( board.at(x).at(y+d).value && board.at(x).at(y+d).value == board.at(x).at(y).value && !board.at(x).at(y).isBlocked && !board.at(x).at(y).isBlocked  )
    {
        board.at(x).at(y).value = 0;
        board.at(x).at(y+d).value *= 2;
        score += board.at(x).at(y+d).value;
        board.at(x).at(y+d).isBlocked = true;
        isMoved = true;

    }
    else if( board.at(x).at(y+d).value && board.at(x).at(y).value )
    {
        board.at(x).at(y+d).value = board.at(x).at(y).value;
        board.at(x).at(y).value = 0;
        isMoved = true;
    }
    if( d > 0 )
    {
        if( y + d < 3 )
            moveVertical( x, y + d,  1 );
    }
    else {
        if( y + d > 0 )
            moveVertical( x, y + d, -1 );
    }

}
void  BoardTile::moveHorizontal(int x, int y, int d)
{
    if( board.at(x+d).at(y).value && board.at(x+d).at(y).value == board.at(x).at(y).value&& !board.at(x).at(y).isBlocked && !board.at(x+d).at(y).isBlocked  )
    {
        board.at(x).at(y).value = 0;
        board.at(x+d).at(y).value*= 2;
        score += board.at(x+d).at(y).value;
        board.at(x+d).at(y).isBlocked = true;
        isMoved = true;
    }
    else if( !board.at(x+d).at(y).value && board.at(x).at(y).value )
    {
        board.at(x+d).at(y).value = board.at(x).at(y).value;
        board.at(x).at(y).value = 0;
        isMoved = true;
    }
    if( d > 0 )
    {
        if( x + d < 3 )
            moveHorizontal( x + d, y,  1 );
    }
    else
    {
        if( x + d > 0 )
            moveHorizontal( x + d, y, -1 );
    }
}
void BoardTile::move(Direction d)
{
    switch( d )
    {
        case UP:
            for( int x = 0; x < 4; x++ )
            {
                int y = 1;
                while( y < 4 )
                {
                    if( board.at(x).at(y).value )
                        moveVertical( x, y, -1 ); y++;
                }
            }
            break;
        case DOWN:
            for( int x = 0; x < 4; x++ )
            {
                int y = 2;
                while( y >= 0 )
                {
                    if( board.at(x).at(y).value )
                        moveVertical( x, y, 1 ); y--;}
            }
            break;
        case LEFT:
            for( int y = 0; y < 4; y++ )
            {
                int x = 1;
                while( x < 4 )
                {
                    if( board.at(x).at(y).value )
                        moveHorizontal( x, y, -1 ); x++;}
            }
            break;
        case RIGHT:
            for( int y = 0; y < 4; y++ )
            {
                int x = 2;
                while( x >= 0 )
                {
                    if( board.at(x).at(y).value )
                        moveHorizontal( x, y, 1 ); x--;
                }
            }
    }
}