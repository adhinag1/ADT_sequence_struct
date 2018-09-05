#ifndef PROFILE_H
#define PROFILE_H

#include <time.h>
#include <sys/time.h>

struct timeval start;
struct timeval stop;

#include "profile.c"

void profileInsert(Vector * v, List * l);
void profileRead(Vector * v, List * l);
void profileRemove(Vector * v, List * l);

#endif