#include "game.h"
#include "utils.h"

void game::init()
{
    unsigned int seed = getTimeSeed();
    srand(seed);
    Map = arenamap(20,30);
    S1 = new snake(Map);
    S2 = new snake(Map);
    S1->setColor(2);
    S2->setColor(4);
    isGameOn = false;
    round = 0;
    mvprintw(0,31,"Seed = %d\n",seed);
    refresh();
}

void game::start()
{
    S1->init();
    S2->init();
    isGameOn = true;
    while(isGameOn){
        isGameOn = gameround();
        Map.print_nc();
        refresh();
        S1->print_nc();
        S2->print_nc();
        refresh();
        mvprintw(1,31,"Round  = %3d\n",round);
        mvprintw(2,31,"Snake1 = %3d\n",S1->len);
        mvprintw(3,31,"Snake2 = %3d\n",S2->len);
        
        sleep_awhile(0.1);
    }  
    getchar();
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
    S2->move();

    //Check if snake is dead. If so stop the game.
    if(S1->dead&&S2->dead)
        return false;
    else{
        //If no open space on the map stop the game.
        if(Map.getOpenMapnodeNum()==0)
            return false;
        else   
            return true;
    }
}
