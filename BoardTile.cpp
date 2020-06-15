//
// Created by User on 20.05.2020.
//

#include "BoardTile.h"

BoardTile::BoardTile(int cols, int rows): cols(cols), rows(rows)
{

    isDone = false;
    isMoved = true;

    score = 0;



    setBoard(cols,rows);

}


void BoardTile::setBoard(int cols, int rows)
{

    cols =4;
    rows = 4;
    state = RUNNING;

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
    addTile();

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
        return '1';
    }
    if(board.at(y).at(x).value == 4)
    {
        return '2';
    }
    if(board.at(y).at(x).value == 8)
    {
        return '3';
    }
    if(board.at(y).at(x).value == 16)
    {
        return '4';
    }
    if(board.at(y).at(x).value == 32)
    {
        return '5';
    }
    if(board.at(y).at(x).value == 64)
    {
        return '6';
    }
    if(board.at(y).at(x).value == 128)
    {
        return '7';
    }
    if(board.at(y).at(x).value == 256)
    {
        return '8';
    }
    if(board.at(y).at(x).value == 512)
    {
        return '9';
    }
    if(board.at(y).at(x).value == 1024)
    {
        return 'x';
    }
    if(board.at(y).at(x).value == 2048)
    {
        return 'z';
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
bool BoardTile::checkAdd(int x, int y )
{
    if( x < 0 || x >4 || y < 0 || y> 4)
        return false;
    return board.at(y).at(x).value ;


}
bool BoardTile::canMove()
{
    for( int y = 0; y < cols; y++ )
        for( int x = 0; x < rows; x++ )
            if( !board.at(x).at(y).value ) return true;

    for( int i = 0; i < cols;i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if(checkAdd(i+1,j))
                return true;
            if(checkAdd(i-1,j))
                return true;
            if(checkAdd(i,j+1))
                return true;
            if(checkAdd(i,j-1))
                return true;

        }
    }
    return false;
}
GameState BoardTile::whatState()
{

        for(int i = 0; i < board.size(); i++)
        {
            if(board.at(i).at(i).isBlocked && board.at(i).at(i).value)
            {
                return FINISHED_LOSS;
            }
            if(board.at(i).at(i).value==2048)
            {
                return FINISHED_WIN;
            }
        }

}
void BoardTile::addTile()
{
    uint a= 0;
    uint b= 0;
            if(!board.at(a).at(b).value)
            {

            do{
                a = rand() %4;
                b = rand() %4;
            }
            while(board.at(a).at(b).value);
            board.at(a).at(b).value = 2;
                if( canMove() ) return;
            }
            isDone = true;
}



void BoardTile::moveVertical(int x, int y, int d)
{
    if(board.at(x).at(y+d).value &&board.at(x).at(y+d).value == board.at(x).at(y).value  && !board.at(x).at(y).isBlocked && !board.at(x).at(y+d).isBlocked  )
    {
        board.at(x).at(y).value = 0;
        board.at(x).at(y+d).value *= 2;
        score += board.at(x).at(y+d).value;
        isMoved = true;

    }
    else if( !board.at(x).at(y+d).value && board.at(x).at(y).value )
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
    else
        {
        if( y + d > 0 )
            moveVertical( x, y + d, -1 );
        }


}
void  BoardTile::moveHorizontal(int x, int y, int d)
{
    if( board.at(x+d).at(y).value && board.at(x+d).at(y).value == board.at(x).at(y).value  && !board.at(x).at(y).isBlocked && !board.at(x+d).at(y).isBlocked )
    {
        board.at(x).at(y).value = 0;
        board.at(x+d).at(y).value *= 2;
        score += board.at(x+d).at(y).value;
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
                    if( board.at(x).at(y).value)
                        moveVertical( x, y, -1 );
                    y++;
                }
            }
            break;
        case DOWN:
            for( int x = 0; x < 4; x++ )
            {
                int y = 2;
                while( y >= 0 )
                { if( board.at(x).at(y).value ) moveVertical( x, y, 1 ); y--;}
            }
            break;
        case LEFT:
            for( int y = 0; y < 4; y++ )
            {
                int x = 1;
                while( x < 4 )
                { if( board.at(x).at(y).value ) moveHorizontal( x, y, -1 ); x++;}
            }
            break;
        case RIGHT:
            for( int y = 0; y < 4; y++ )
            {
                int x = 2;
                while( x >= 0 )
                { if( board.at(x).at(y).value ) moveHorizontal( x, y, 1 ); x--;}
            }
    }
}