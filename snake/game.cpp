#include "game.h"

void game::init()
{
    Map = arenamap(30,20);
    S1 = snake(Map);
}

void game::start()
{
    Map.print_nc();
}