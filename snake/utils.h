#ifndef __UTILS_H_
#define __UTILS_H_
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
void sleep_awhile(float sec);
unsigned int getTimeSeed();
int randnum(int low, int high);
#endif