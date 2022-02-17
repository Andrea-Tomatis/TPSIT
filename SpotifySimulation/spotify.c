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
int readSongs(Song *playlist, char *filename, int k){   
    FILE* fp = fopen(filename,"r"); //open the file in reading mode
    char *line = (char*) malloc(STR_LEN * sizeof(char));  //line read from the file
    int i = 0;

    if(fp == NULL) return ERROR;  //if the file doesn't exist return error

    while(fgets(line,STR_LEN,fp) && i < k){ //read each line of the file
        /*
        strtok(): divide a string by character or substring
        */
        //stores the index of the song in the songs array
        (playlist+i)->ind = atoi(strtok(line,",\n"));
        //stores the title of the song in the songs array
        strncpy((playlist+i)->title, strtok(NULL, ",\n"), STR_LEN); 

        //stores the author of the song in the songs array
        strncpy((playlist+i)->author, strtok(NULL, ",\n"), STR_LEN);
        i++;
    }

    free(line);
    return 0;
}





//this function print songs in a random order
void playrandom(Song *playlist,int k){
    Song* played_songs = playlist; //array of extracted song index
    int index;  //extract index

    srand(time(NULL));  //set the random seed using the time() function, from time.h
    for(int i = 0; i < k; i++){  //it sorts number while all songs are played
        //this do while loop controls that the sorted song hasn't already been sorted
        do{
            index = rand() % (k);
        }while((played_songs+index)->ind == -1);

        //print the song
        printf("%-2d: %s | %s\n",i+1,(playlist + index)->title,(playlist + index)->author);

        //increase the number of played songs by 1 and append the sorted index to the played song index array
        (played_songs + index)->ind = -1; 
    }  //end the for loop
    free(played_songs);
    return;
}



//reads the number of songs in the file
int leggiNumRighe(char *nomeFile){ 
    FILE* fp = fopen(nomeFile,"r");
    int k = 0;
    char* string = (char*) malloc(STR_LEN * sizeof(char));

    if(fp == NULL) return -1;
    while(fgets(string,STR_LEN,fp) != NULL)
        k++;
    return k;
}


int main(){
    //Song playlist[SONG_NUM];  //songs array
    
    int k = leggiNumRighe("spotify.csv");
    Song *playlist = (Song*) malloc(k * sizeof(Song));
    int readingFile = readSongs(playlist,"spotify.csv",k);  //number of songs in the file
    if(readingFile == ERROR) printf("error: no such file found\n"); //if the file doesn't exist, print error
    else playrandom(playlist,k);  //else it plays all songs in random order
    
    free(playlist);
    return 0; 
}
