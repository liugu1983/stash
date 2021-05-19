#ifndef __UTILS_H_
#define __UTILS_H_
#include <time.h>
#include <stdlib.h>
void sleep_awhile(float sec){
    struct timespec ts;
    ts.tv_sec = (time_t)sec;
    ts.tv_nsec = (sec-(time_t)sec)*1000000000;
    nanosleep(&ts,0);
}

int randnum(int low, int high)
{
    return rand()%(high-low) + low;
}
#endif