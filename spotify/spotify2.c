/*
Author: Andrea Tomatis
CSV READING
problem: read a list of songs from a given csv file and play them in a random order. This version use lists
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
    char *title;  //title of the song
    char *author;  //author of the song
    struct song* next;
}Song;



/*
not-recorsive version of push function
void push(Song* p, int i, char* t, char* a){
    struct song* p_appoggio = p;
    
    if(i == 1){
        p->author = strdup(a);
        p->title = strdup(t);
        p->ind = i;
        p->next = NULL;
        return;
    }
    while(p_appoggio->next != NULL)
        p_appoggio = p_appoggio->next;
    
        
    p_appoggio->next = (Song*)malloc(sizeof(Song));
    p_appoggio->next->ind = i;
    p_appoggio->next->title = strdup(t);
    p_appoggio->next->author = strdup(a);
    p_appoggio->next->next = NULL;
    return;
}
*/
void push(Song* p, int id, char* t, char* a){
    if(id == 1){
        p->author = strdup(a);
        p->title = strdup(t);
        p->ind = id;
        p->next = NULL;
        return;
    }
    if(p->next == NULL){
        p->next = (Song*)malloc(sizeof(Song));
        p->next->ind = id;
        p->next->title = strdup(t);
        p->next->author = strdup(a);
        p->next->next = NULL;
        return;
    }else{
        push(p->next,id,t,a);
        return;
    }
}

int leggiFile(char* nomeFile, Song* playlist){
    FILE* fp = fopen(nomeFile,"r");
    char* line = (char*) malloc(STR_LEN * sizeof(char));
    int id;
    char* title;
    char* author;

    if(fp == NULL) return ERROR;

    while(fgets(line,STR_LEN,fp) != NULL){
        id = atoi(strtok(line,",\n"));
        title = strdup(strtok(NULL,",\n"));
        author = strdup(strtok(NULL,",\n"));
        Song* p_appoggio = playlist;
        push(p_appoggio,id,title,author);
    }

    fclose(fp);
    return 0;
}

Song* trova(int n, Song* p){
    if(n == 0)
        return p;
    else
        return trova(n-1,p->next);
}

void riproduciRandom(Song* playlist){
    struct song* p_appoggio = playlist;
    int n = 1;
    int numrand;
    while(p_appoggio->next != NULL){
        p_appoggio = p_appoggio->next;
        n++;
    }
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        do{
            numrand = rand()%n;
            p_appoggio = playlist;
            p_appoggio = trova(numrand,p_appoggio);
        }while(p_appoggio->ind == -1);
        printf("%d- %s %s\n",p_appoggio->ind,p_appoggio->title,p_appoggio->author);
        p_appoggio->ind = -1;
    }    
    
    return;
}

int main(){
    struct song* playlist = (struct song*) malloc(sizeof(struct song));
    //lettura file
    if (leggiFile("spotify.csv",playlist) == ERROR){
        printf("error: no such file found\n");
        return ERROR;
    }else
        riproduciRandom(playlist);
    
    return 0;
}

