#include <iostream>
#include "game.h"
using namespace std;
int main(int argc, char *argv[])
{
    game Game;
    Game.init();

    /*ncurses gui start*/
    initscr();
    
    Game.start();
    endwin();
    return 0;
}
