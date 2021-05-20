#include "snake.h"
#include "utils.h"

void snake::init()
{
    mapnode h=smap.getAnOpenNode();
    head = make_pair(h.x,h.y);
    len =1;
    body.push_back(head);
    dead =false;

    smap.setTaken(h);
}
void snake::print_nc()
{
    //TODO:Add print function here
    mvprintw(head.first,head.second,"O");
    for(unsigned int i=1;i<body.size();i++){
        mvprintw(body[i].first,body[i].second,"o");
    }

}

void snake::move()
{}