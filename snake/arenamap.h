#ifndef __ARENAMAP_H_
#define __ARENAMAP_H_
#include <vector>
#include <ncurses.h>
using namespace std;
class mapnode{
    public:
        unsigned int id;
        unsigned int x;
        unsigned int y;
        bool         isWall;
        bool         isOpen;
    public:
        mapnode(unsigned int _id=0, unsigned int _x=0, unsigned int _y=0, bool _isWall=false)
        :id(_id),x(_x),y(_y),isWall(_isWall){
            isOpen = ~isWall;
        }
        ~mapnode(){}
};

class arenamap{
    public:
        unsigned int mapsize;
        unsigned int map_x;
        unsigned int map_y;
        vector<mapnode> vmap;

    public:
        arenamap(unsigned int x=0,unsigned int y=0)
        :mapsize(x*y),map_x(x),map_y(y){
            vmap.clear();
            for(unsigned int i=0;i<x;i++){
                for(unsigned int j=0;j<y;j++){
                    mapnode *n = new mapnode(i*y+j,i,j,i==0||j==0||i==(x-1)||j==(y-1));
                    vmap.push_back(*n);
                }
            }
        }
        ~arenamap(){}
        void print_nc();
};
#endif