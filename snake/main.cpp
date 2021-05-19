#include <iostream>
#include "arenamap.h"
#include "snake.h"
using namespace std;
int main(int argc, char *argv[])
{
    arenamap Map(20,30);
    snake S1(Map);

    /*ncurses gui start*/
    initscr();
    Map.print_nc();
    endwin();
    return 0;
}
