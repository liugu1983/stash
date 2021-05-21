#ifndef __ARENAMAP_H_
#define __ARENAMAP_H_
#include <utility>
#include <vector>
#include <ncurses.h>
using namespace std;

#define snode pair<unsigned int, unsigned int>

class mapnode{
    public:
        unsigned int id;
        unsigned int x;
        unsigned int y;
        bool         isWall;
        bool         isOpen;
        bool         isApple;
    public:
        mapnode(unsigned int _id=0, unsigned int _x=0, unsigned int _y=0, bool _isWall=false)
        :id(_id),x(_x),y(_y),isWall(_isWall){
            isOpen = !_isWall;
        }
        ~mapnode(){}
};

class applenode{
    public:
        unsigned int id;    //the same id of mapnode
        unsigned int x;
        unsigned int y;
        bool     eaten;
    public:
        applenode(unsigned int _id=0,unsigned int _x=0, unsigned int _y=0, bool _eaten=false)
        :id(_id),x(_x),y(_y),eaten(_eaten){}
        ~applenode(){}
};

class arenamap{
    public:
        unsigned int mapsize;
        unsigned int map_x;
        unsigned int map_y;
        vector<applenode> vapple;
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

        unsigned int getOpenMapnodeNum(){
            unsigned int ret = 0;
            for(unsigned int i=0;i<vmap.size();i++){
                if(vmap[i].isOpen)
                    ret++;
            }
            return ret;
        }
        mapnode getAnOpenNode();
        void setTaken(mapnode n){
            vmap[n.id].isOpen = false;
        }
        void setTaken(unsigned int x, unsigned int y){
            vmap[x*map_y+y].isOpen = false;
        }
        void setTaken(snode s){
            vmap[s.first*map_y+s.second].isOpen = false;
        }
        void setOpen(mapnode n){
            vmap[n.id].isOpen = true;
        }
        void setOpen(unsigned int x, unsigned int y){
            vmap[x*map_y+y].isOpen = true;
        }
        void setOpen(snode s){
            vmap[s.first*map_y+s.second].isOpen = true;
        }
        void setApple(mapnode n){
            vmap[n.id].isApple = true;
        }
        void setNotApple(mapnode n){
            vmap[n.id].isApple = false;
        }
        void generateAnApple();
        size_t getAppleNum(){return vapple.size();}
};
#endif