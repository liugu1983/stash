#ifndef __SNAKE_H_
#define __SNAKE_H_

#include <deque>
#include <ncurses.h>
#include "arenamap.h"
using namespace std;



class snake{
    public:
        snode head;
        unsigned int len;
        deque<snode > body;
        arenamap &smap;
        bool dead;
        unsigned int color_id;
    public:
        snake(arenamap &_smap):len(0),smap(_smap),dead(false),color_id(0){}
        ~snake(){}
        void init();
        void print_nc();
        void move();
        mapnode findway();
        void setColor(unsigned int color){color_id = color;}
};

#endif
