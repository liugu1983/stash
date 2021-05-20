#include <iostream>
#include "game.h"
using namespace std;
int main(int argc, char *argv[])
{
    game Game;
    

    /*ncurses gui start*/
    initscr();
    curs_set(0);    //set cursor invisible
    Game.init();
    Game.start();
    endwin();
    return 0;
}
