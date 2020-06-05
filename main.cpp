#include <iostream>
#include "BoardTile.h"
#include "time.h"

int main() {
    srand( static_cast<int>( time( NULL ) ) );

    BoardTile bt(4,4);

  bt.consoleGame();
    return system( "pause" );







}
