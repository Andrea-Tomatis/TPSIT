/*

Andrea Tomatis

4^AROB

Verifica TPSIT

19/11/2020

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ERROR -1  //codice di errore
#define STR_LEN 100  //lunghezza massima di una stringa


typedef struct volo{  //contiene i dati di un volo
    int tempo;
    float lat,lon;
}Volo;

typedef struct anomalia{  //contiene il descrittore di un'anomalia
    int tempo;
    char* typerror;
}Anomalia;


//legge il numero di righe da un file
int leggiNumRighe(char *nomeFile){ 
    FILE* fp = fopen(nomeFile,"r");
    int k = 0;
    char* string = (char*) malloc(STR_LEN * sizeof(char));

    if(fp == NULL) return ERROR;  //se il file non esiste restituisce errore 
    while(fgets(string,STR_LEN,fp) != NULL)
        k++;
    fclose(fp);
    return k-1;  //restituisce il numero di righe meno la prima riga (che e' la legenda)
}



//carica il vettore di voli da file
int readFly(Volo* drone, char *filename, int k){   
    FILE* fp = fopen(filename,"r"); 
    char *line = (char*) malloc(STR_LEN * sizeof(char));  //alloca un vettore di supporto per leggere le righe da file
    int i = 0;

    if(fp == NULL) return ERROR;  //se il file non esiste restituisce il codice di errore

    while(fgets(line,STR_LEN,fp) && i <= k){ 
        if(i != 0){
            //la funzione strtok spezza la riga ogni volta che incontra la virgola
            (drone+i-1)->tempo = atoi(strtok(line,",\n"));
            (drone+i-1)->lat = atof(strtok(NULL,",\n"));
            (drone+i-1)->lon = atof(strtok(NULL,",\n"));   
        }
        
        i++;
    }

    free(line);  //disalloca la stringa di supporto
    fclose(fp);
    return 0;
}


//legge le anomalie da file e carica un vettore di anomalie
int readAnomalie(Anomalia* err, char *filename, int k){   
    FILE* fp = fopen(filename,"r"); 
    char *line = (char*) malloc(STR_LEN * sizeof(char));  //alloca un vettore di supporto per leggere le righe da file
    int i = 0;

    if(fp == NULL) return ERROR;  //se il file non esiste restituisce il codice di errore

    while(fgets(line,STR_LEN,fp) && i <= k){ 
        if(i != 0){
            //la funzione strtok spezza la riga ogni volta che incontra la virgola
            (err+i-1)->tempo = atoi(strtok(line,",\n"));
            (err+i-1)->typerror = strdup(strtok(NULL,","));
        }
        i++;    
    }

    free(line);  //disalloca la stringa di supporto
    fclose(fp);
    return 0;
}


//restituisce l'indice dell'errore se ce ne stato uno in un determinato tempo t. Altrimenti restituisce errore
int isErrore(int t, Anomalia* errori, int k){
    for(int i = 0; i < k; i++) 
        if((errori+i)->tempo == t){
            return i;
        } 
    return ERROR;
}


//stampa a video le caratteristiche di una anomalia
void trovaCoordAnomalie(Volo* drone,Anomalia* errori,int righeVolo, int righeErrori){
    int errorindex;
    for(int i = 0; i < righeVolo; i++){
        errorindex = isErrore((drone+i)->tempo,errori,righeErrori); //la variabile error index contine l'indice dell'errore
        if( errorindex != ERROR)  //se e' diverso da -1 stampa l'errore;
            printf("Tipo di problema: %s tempo: %d, latitudine: %f, longitudine: %f\n\n",(errori+errorindex)->typerror,(drone+i)->tempo,(drone+i)->lat,(drone+i)->lon);
    }
    return;
}


int main(){
    
    int k = leggiNumRighe("Volo_drone.csv");  //legge il numero di righe del file
    if(k == ERROR) return -1;  //se il file non esiste terimina il programma
    
    Volo* drone = (Volo*) malloc(k * sizeof(Volo));  //alloca un vettore di voli

    if(readFly(drone,"Volo_drone.csv",k) == ERROR) //carica il vettore di voli da file, se il file non esiste termina il programma
        return ERROR;
    else{
        int lines = leggiNumRighe("Anomalie_drone.csv");  //legge il numero di righe del file
        if(lines ==  ERROR) return ERROR; //se il file non esiste terimina il programma

        Anomalia* errori = (Anomalia*) malloc(lines * sizeof(Anomalia));  //alloca un vettore di errori
        if(readAnomalie(errori,"Anomalie_drone.csv",lines) == -1) return ERROR; //carica il vettore da file o, se il file non esiste, termina il programma
        
        trovaCoordAnomalie(drone,errori,k,lines);  //stampa a video le coordinate delle anomalie

        free(errori);  //disalloca il vettore
    }
    
    free(drone);  //disalloca il vettore
    return 0; 
}
