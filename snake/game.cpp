#include "game.h"
#include "utils.h"

void game::init()
{
    unsigned int seed = getTimeSeed();
    srand(seed);
    Map = arenamap(20,30);
    S1 = new snake(Map);
    isGameOn = false;
    round = 0;
    mvprintw(0,31,"Seed = %d\n",seed);
    refresh();
}

void game::start()
{
    S1->init();
    isGameOn = true;
    while(isGameOn){
        isGameOn = gameround();
        Map.print_nc();
        S1->print_nc();
        refresh();
        sleep_awhile(1.5);
    }  
}

bool game::gameround()
{
    round++;

    //Check if a new apple is needed. If so create one.
    if(Map.getAppleNum() == 0){
        Map.generateAnApple();
    }

    //Snake S1 move a step
    S1->move();

    //Check if snake is dead. If so stop the game.
    if(S1->dead)
        return false;
    else{
        //If no open space on the map stop the game.
        if(Map.getOpenMapnodeNum()==0)
            return false;
        else   
            return true;
    }
}