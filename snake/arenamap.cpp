#include "arenamap.h"
#include "utils.h"

void arenamap::print_nc()
{
    for(unsigned int i=0;i<map_x;i++)
        for(unsigned int j=0;j<map_y;j++){
            unsigned int nodeId = i*map_y+j;
            if(vmap[nodeId].isWall){
                mvprintw(vmap[nodeId].x,vmap[nodeId].y,"#");
            }
        }
    refresh();
    sleep_awhile(1.5);
}