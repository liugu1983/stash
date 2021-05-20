#include "game.h"

void game::init()
{
    Map = arenamap(20,30);
    S1 = new snake(Map);
}

void game::start()
{
    Map.print_nc();
}