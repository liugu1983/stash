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
    attron(COLOR_PAIR(color_id)); 
    for(unsigned int i=1;i<body.size();i++){
        mvprintw(body[i].first,body[i].second,"o");
    }

    //Head may eat a body node. print lastly
    if(dead)
        mvprintw(head.first,head.second,"X");
    else
        mvprintw(head.first,head.second,"O");
    attroff(COLOR_PAIR(color_id));
}

void snake::move()
{
    //Move the snake a step
    if(dead)
        return;

    mapnode dest=findway();

    if(!dest.isOpen){
        if(dest.isApple){
            //Eat apple
            head = make_pair(dest.x,dest.y);
            len++;
            body.push_front(head);//Add a new head
            smap.setNotApple(dest);
            smap.vapple.pop_back();
            

        }else{
            //Hit a wall or snake body
            head = make_pair(dest.x,dest.y);
            body.push_front(head);
            smap.setTaken(body.front());
            smap.setOpen(body.back());
            body.pop_back();
            dead=true;
        }
    }
    else{
        head = make_pair(dest.x,dest.y);
        body.push_front(head);
        smap.setTaken(body.front());
        smap.setOpen(body.back());
        body.pop_back();
    }
}

mapnode snake::findway()
{
    unsigned int Hx = head.first;
    unsigned int Hy = head.second;
    unsigned int Ax = smap.vapple[0].x;
    unsigned int Ay = smap.vapple[0].y;

    unsigned int HeadId = Hx*smap.map_y+Hy;
    unsigned int UpId = (Hx-1)*smap.map_y+Hy;
    unsigned int DownId = (Hx+1)*smap.map_y+Hy;
    unsigned int LeftId = Hx*smap.map_y+Hy-1;
    unsigned int RightId = Hx*smap.map_y+Hy+1;
    mapnode Head = smap.vmap[HeadId];
    mapnode UP = smap.vmap[UpId];
    mapnode DOWN = smap.vmap[DownId];
    mapnode LEFT = smap.vmap[LeftId];
    mapnode RIGHT = smap.vmap[RightId];

    if(LEFT.isApple)
        return LEFT;
    if(RIGHT.isApple)
        return RIGHT;
    if(UP.isApple)
        return UP;
    if(DOWN.isApple)
        return DOWN;

    if(Hx == Ax){
        if(Hy<Ay){
            if(RIGHT.isOpen)
                return RIGHT;
            else if(UP.isOpen)
                return UP;
            else if(DOWN.isOpen)
                return DOWN;
            else
                return LEFT;
        }
        else if(Hy>Ay){
            if(LEFT.isOpen)
                return LEFT;
            else if(UP.isOpen)
                return UP;
            else if(DOWN.isOpen)
                return DOWN;
            else
                return RIGHT;
        }
    }
    else if(Hy==Ay){
        if(Hx<Ax){
            if(DOWN.isOpen)
                return DOWN;
            else if(LEFT.isOpen)
                return LEFT;
            else if(RIGHT.isOpen)
                return RIGHT;
            else
                return UP;            
        }
        else if(Hx>Ax){
            if(UP.isOpen)
                return UP;
            else if(LEFT.isOpen)
                return LEFT;
            else if(RIGHT.isOpen)
                return RIGHT;
            else    
                return DOWN;
        }
    }
    else if(Hx<Ax&&Hy<Ay){
        if(DOWN.isOpen)
            return DOWN;
        else if(RIGHT.isOpen)
            return RIGHT;
        else if(UP.isOpen)
            return UP;
        else   
            return LEFT;
    }
    else if(Hx<Ax&&Hy>Ay){
        if(DOWN.isOpen)
            return DOWN;
        else if(LEFT.isOpen)
            return LEFT;
        else if(UP.isOpen)
            return UP;
        else 
            return RIGHT;
    }
    else if(Hx>Ax&&Hy<Ay){
        if(UP.isOpen)
            return UP;
        else if(RIGHT.isOpen)
            return RIGHT;
        else if(DOWN.isOpen)
            return DOWN;
        else 
            return LEFT;
    }
    else if(Hx>Ax&&Hy>Ay){
        if(UP.isOpen)
            return UP;
        else if(LEFT.isOpen)
            return LEFT;
        else if(DOWN.isOpen)
            return DOWN;
        else   
            return RIGHT;
    }
}
