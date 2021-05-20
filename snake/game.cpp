#include "game.h"

void game::init()
{
    Map = arenamap(20,30);
}

void game::start()
{
    Map.print_nc();
}