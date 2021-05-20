#ifndef __SNAKE_H_
#define __SNAKE_H_
#include <utility>
#include <vector>
#include <ncurses.h>
#include "arenamap.h"
using namespace std;

#define snode pair<unsigned int, unsigned int>

class snake{
    public:
        snode head;
        unsigned int len;
        vector<snode > body;
        arenamap &smap;
        bool dead;

    public:
        snake(arenamap &_smap):len(0),smap(_smap),dead(false){}
        ~snake(){}
        void init();
        void print_nc();
        void move();
};

#endif