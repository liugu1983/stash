#include "utils.h"

void sleep_awhile(float sec){
    struct timespec ts;
    ts.tv_sec = (time_t)sec;
    ts.tv_nsec = (sec-(time_t)sec)*1000000000;
    nanosleep(&ts,0);
}
unsigned int getTimeSeed()
{
    struct timeval tv;
    gettimeofday(&tv,0);
    return (unsigned int)(tv.tv_sec);
}
int randnum(int low, int high)
{
    return rand()%(high-low) + low;
}