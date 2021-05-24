#include <iostream>
#include "game.h"
using namespace std;
int main(int argc, char *argv[])
{
    game Game;
    

    /*ncurses gui start*/
    initscr();
    curs_set(0);    //set cursor invisible
    if(start_color()==OK){
        use_default_colors();
        init_pair(1, COLOR_RED,-1);
        init_pair(2, COLOR_GREEN,-1);
        init_pair(3, COLOR_BLUE, -1);
        init_pair(4, COLOR_CYAN, -1);
    }
    Game.init();
    Game.start();
    endwin();
    return 0;
}
