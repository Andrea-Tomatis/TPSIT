/*
Clock: Implement a clock that handles times without dates.
    Two clocks that represent the same time should be equal to each other.

@Andrea-Tomatis
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void clear_screen(int, FILE*);


int main(){

    time_t now;
    struct tm *tm_struct;
    int hour, min, sec;

    now = time(NULL);
    tm_struct = localtime(&now);
    int prec_sec = tm_struct->tm_sec;


    while (1){
        now = time(NULL);
        tm_struct = localtime(&now);
        hour = tm_struct->tm_hour;
        min = tm_struct->tm_min;
        sec = tm_struct->tm_sec;
        if (sec != prec_sec)
        {
            fflush(stdout);
            printf("%d : %d : %d",hour,min,sec);
            clear_screen(12,stdout);
            prec_sec = sec;
        }
    }


    return 0;
}



void clear_screen(int length, FILE* stream){
    for(int i = 0; i < length; i++) printf("\b");
    
    fflush(stream);

    for(int i = 0; i < length; i++) printf(" ");
    for(int i = 0; i < length; i++) printf("\b");
}