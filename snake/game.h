#ifndef __GAME_H_
#define __GAME_H_
#include "arenamap.h"
#include "snake.h"
class game{
    public:
        arenamap Map;
        unsigned int round;
        bool     isGameOn;
    public:
        game(){}
        ~game(){}
        void init();
        void start();
};
#endif