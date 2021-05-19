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

    public:
        snake(arenamap &_smap):len(0),smap(_smap){}
        ~snake(){}
        void print_nc();
};

#endif