/*
Author: Andrea Tomatis

CSV READING
problem: read a list of songs from a given csv file and play them in a random order
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


//constant definition
#define STR_LEN 100  //maximum lengh of a string
#define SONG_NUM 99  //maximum number of song into the playlist
#define ERROR -1  //return -1 if there's an error

typedef struct song{
    int ind; //index of the song
    char title[100];  //title of the song
    char author[100];  //author of the song
}Song;


//this function read the index, the title and the author of each song from the csv file and saves songs into an array
int readSongs(Song playlist[], char filename[]){   
    FILE* fp = fopen(filename,"r"); //open the file in reading mode
    int k = 0;  //number of songs
    char line[STR_LEN];  //line read from the file

    if(fp == NULL) return ERROR;  //if the file doesn't exist return error

    while(fgets(line,STR_LEN,fp) != NULL){ //read each line of the file
        /*
        sscanf(): read from a value from a string
        strtok(): divide a string by character or substring
        */
        //stores the index of the song in the songs array
        sscanf(strtok(line, ",\n"), "%d", &playlist[k].ind);  

        //stores the title of the song in the songs array
        strncpy(playlist[k].title, strtok(NULL, ",\n"), STR_LEN); 

        //stores the author of the song in the songs array
        strncpy(playlist[k++].author, strtok(NULL, ",\n"), STR_LEN);
    }

    return k;  //returns the number of songs in the csv file
}


//this function control if an index has already been sorted
//it returns true if it has or false if it hasn't
bool isPlayed(int ind, int played_songs[], int k){
    int i = 0;
    bool ok = false;
    while(i < k && !ok)
        if(played_songs[i++] == ind) ok = true;
    return ok;
}


//this function print songs in a random order
void playrandom(Song playlist[],int k){
    int played_songs[k]; //array of extracted song index
    int index;  //extract index
    int nplayed = 0;  //number of played songs

    srand(time(NULL));  //set the random seed using the time() function, from time.h
    for(int i = 0; i < k; i++){  //it sorts number while all songs are played
        //this do while loop controls that the sorted song hasn't already been sorted
        do{
            index = rand() % (k);
        }while(isPlayed(index,played_songs,nplayed));

        //print the song
        printf("%-2d: %s | %s\n",i+1,playlist[index].title,playlist[index].author);

        //increase the number of played songs by 1 and append the sorted index to the played song index array
        played_songs[nplayed++] = index; 
    }  //end the for loop

    return;
}


int main(){
    Song playlist[SONG_NUM];  //songs array

    int nsongs = readSongs(playlist,"spotify.csv");  //number of songs in the file
    if(nsongs == ERROR) printf("error: no such file found\n"); //if the file doesn't exist, print error
    else playrandom(playlist,nsongs);  //else it plays all songs in random order
    
    return 0; 
}
