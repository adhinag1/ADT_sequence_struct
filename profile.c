#include "data.h"
#include<stdio.h>

void profileInsert(Vector * v, List * l) {
    gettimeofday(&start, NULL);
    for (int i = 0; i<1000; i++) {
        v->insert(v, i, (Data) {i});
    }
    gettimeofday(&stop, NULL);
    time_t start_time_v = (start.tv_sec* 1000000) + start.tv_usec;
    time_t stop_time_v = (stop.tv_sec* 1000000) + stop.tv_usec;
    float profile_time_v = stop_time_v - start_time_v;
    printf("start_time: %ld\n", (long)start_time_v);
    printf("stop_time: %ld\n", (long)stop_time_v);
    printf("Profile_time for Insert(Vector): %f microseconds\n\n", profile_time_v);
    
    gettimeofday(&start, NULL);
    for (int i = 0; i<1000; i++) {
        l->insert(l, i, (Data){i+1});
    }
    gettimeofday(&stop, NULL);
    time_t start_time_l = (start.tv_sec* 1000000) + start.tv_usec;
    time_t stop_time_l = (stop.tv_sec* 1000000) + stop.tv_usec;
    float profile_time_l = stop_time_l - start_time_l;
    printf("start_time: %ld\n", (long)start_time_l);
    printf("stop_time: %ld\n", (long)stop_time_l);
    printf("Profile_time for Insert(List): %f microseconds\n\n", profile_time_l);
}

void profileRead(Vector * v, List * l) {
    gettimeofday(&start, NULL);
    for (int i = 0; i<100; i++) {
        int index = (rand() % 1000);
        v->read(v, index);
    } 
    gettimeofday(&stop, NULL);
    time_t start_time_v = (start.tv_sec* 1000000) + start.tv_usec;
    time_t stop_time_v = (stop.tv_sec* 1000000) + stop.tv_usec;
    float profile_time_v = stop_time_v - start_time_v;
    printf("start_time: %ld\n", (long)start_time_v);
    printf("stop_time: %ld\n", (long)stop_time_v);
    printf("Profile_time for Read (Vector): %f microseconds\n\n", profile_time_v);   
    
    gettimeofday(&start, NULL);
    for (int i = 0; i<100; i++) {
        int index = (rand() % 1000);
        l->read(l, index);
    } 
    gettimeofday(&stop, NULL);
    time_t start_time_l = (start.tv_sec* 1000000) + start.tv_usec;
    time_t stop_time_l = (stop.tv_sec* 1000000) + stop.tv_usec;
    float profile_time_l = stop_time_l - start_time_l;
    printf("start_time: %ld\n", (long)start_time_l);
    printf("stop_time: %ld\n", (long)stop_time_l);
    printf("Profile_time for Read (List): %f microseconds\n\n", profile_time_l);    
}

void profileRemove(Vector * v, List * l) {
    gettimeofday(&start, NULL);
    for (int i = 0; i<100; i++) {
        int index = (rand() % 1000);
        v->remove(v, index);
    } 
    gettimeofday(&stop, NULL);
    time_t start_time_v = (start.tv_sec* 1000000) + start.tv_usec;
    time_t stop_time_v = (stop.tv_sec* 1000000) + stop.tv_usec;
    float profile_time_v = stop_time_v - start_time_v;
    printf("start_time: %ld\n", (long)start_time_v);
    printf("stop_time: %ld\n", (long)stop_time_v);
    printf("Profile_time for Remove (Vector): %f microseconds\n\n", profile_time_v);
    
    gettimeofday(&start, NULL);
    for (int i = 0; i<100; i++) {
        int index = (rand() % 1000);
        l->remove(l, index);
    } 
    gettimeofday(&stop, NULL);
    time_t start_time_l = (start.tv_sec* 1000000) + start.tv_usec;
    time_t stop_time_l = (stop.tv_sec* 1000000) + stop.tv_usec;
    float profile_time_l = stop_time_l - start_time_l;
    printf("start_time: %ld\n", (long)start_time_l);
    printf("stop_time: %ld\n", (long)stop_time_l);
    printf("Profile_time for Remove (List): %f microseconds\n\n", profile_time_l);
}