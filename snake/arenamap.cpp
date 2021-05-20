#include "arenamap.h"
#include "utils.h"

void arenamap::print_nc()
{
    //print map
    for(unsigned int i=0;i<map_x;i++)
        for(unsigned int j=0;j<map_y;j++){
            unsigned int nodeId = i*map_y+j;
            if(vmap[nodeId].isWall){
                mvprintw(vmap[nodeId].x,vmap[nodeId].y,"#");
            }
        }
    //print apples
    for(unsigned int i=0;i<vapple.size();i++){
        mvprintw(vapple[i].x,vapple[i].y,"@");
    }
}

mapnode arenamap::getAnOpenNode()
{
    unsigned int idx = randnum(0,getOpenMapnodeNum());
    unsigned int pick = 0;
    for(unsigned int i=0;i<vmap.size();i++){
        if(vmap[i].isOpen){
            if(pick==idx){
                return vmap[i];
            }
            pick++;
        }
    }
}

void arenamap::generateAnApple()
{
    //Find an open mapnode randomly on this map
    mapnode pick = getAnOpenNode();

    //Generate an apple here
    applenode Apple(pick.id,pick.x,pick.y,false);
    vapple.push_back(Apple);

    //Apple node is no longer open
    setTaken(pick);
}