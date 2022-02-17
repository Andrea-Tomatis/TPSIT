/*
Date: 14/11/2020

Author: Andrea Tomatis

Read the italians covid data from a csv file and find:
-the top 3 areas by focused therapy
-the total number of focused therapy
-the top 3 regions by total positive cases

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STR_LEN 1000
#define ERROR -1
#define NO_ERROR 0
#define NUM_DATI 14
#define INDEX_TERAPIA_INTENSIVA 8
#define INDEX_TOTALI_POSITIVI 4

typedef struct regione{
    char *data;  //date of the data
    char *stato;  //state of the data (Italy)
    char *nome;  //name of the region
    int id_regione;  //id of the region
    float lat,lon;  //latitude and longitude of the region
    int dati[NUM_DATI]; //vector of data
}Regione;



int leggifile(Regione *italy, char* nomefile, int nrighe);
int leggiRigheFile(char *nomefile);
void scambia(Regione* x, Regione* y);
void topterapiaIntensiva(Regione *r, int nregioni);
void topTotaliPositivi(Regione *r, int nregioni);



//read the number of lines in the file
int leggiRigheFile(char *nomefile){
    char *line = (char*) malloc(STR_LEN * sizeof(char));
    int k = 0;
    
    FILE* fp = fopen(nomefile,"r");
    if(fp == NULL) return ERROR;

    while(fgets(line,STR_LEN,fp) != NULL)
        k++;
    
    fclose(fp);
    free(line);
    return k;
}



//read all of the data from the file and store them into a vector
int leggifile(Regione *italy, char* nomefile, int nrighe){
    FILE *fp = fopen(nomefile,"r");
    char *line = (char*) malloc(STR_LEN * sizeof(char));

    if(fp == NULL) return ERROR;
    int i = 0;
    while(fgets(line,STR_LEN,fp) != NULL && i < nrighe){
        (italy+i)->data = strdup(strtok(line,",\n"));
        (italy+i)->stato = strdup(strtok(NULL, ",\n"));
        (italy+i)->id_regione =  atoi(strtok(NULL, ",\n"));
        (italy+i)->nome = strdup(strtok(NULL, ",\n"));
        (italy+i)->lat = atof(strtok(NULL, ",\n"));
        (italy+i)->lon = atof(strtok(NULL, ",\n"));
        for(int j = 0; j < NUM_DATI; j++)
            (italy+i)->dati[j] = atoi(strtok(NULL, ",\n"));
        i++;
    }
    
    free(line);
    fclose(fp);
    return NO_ERROR;
}

//switch two Region variable value
void scambia(Regione* x, Regione* y){
    Regione temp = *x;
    *x = *y;
    *y = temp;
    return;
}


//find the top 3 regions by focus terapy
void topterapiaIntensiva(Regione *r, int nregioni){
    Regione *top = r;
    
    int kmin,j;
    for(int k = 0; k < nregioni-1; k++){
        kmin = k;
        for(j = k+1; j < nregioni; j++)
            if((top+kmin)->dati[INDEX_TERAPIA_INTENSIVA] > (top+j)->dati[INDEX_TERAPIA_INTENSIVA]) kmin = j;
        if(kmin != k) scambia((top+kmin), (top+k));
    }
    
    printf("Top 3 regioni per ricoverati in terapia intensiva:\n");
    for(int i = 0; i < 3; i++)
        printf("-%d %s: %d\n",i+1, (top+nregioni-i-1)->nome, (top+nregioni-i-1)->dati[INDEX_TERAPIA_INTENSIVA]);
    

    free(top);
    return;
}


//top 3 regions by total positive cases
void topTotaliPositivi(Regione *r, int nregioni){
    Regione *top = r;
    
    int kmin,j;
    for(int k = 0; k < nregioni-1; k++){
        kmin = k;
        for(j = k+1; j < nregioni; j++)
            if((top+kmin)->dati[INDEX_TOTALI_POSITIVI] > (top+j)->dati[INDEX_TOTALI_POSITIVI]) kmin = j;
        if(kmin != k) scambia((top+kmin), (top+k));
    }
    
    printf("Top 3 regioni per totali positivi:\n");
    for(int i = 0; i < 3; i++)
        printf("-%d %s: %d\n",i+1, (top+nregioni-i-1)->nome, (top+nregioni-i-1)->dati[INDEX_TOTALI_POSITIVI]);
    
    free(top);
    return;
}


//calculate the total number of focus terapy
int totaleIntensiva(Regione *regioni, int nregioni){
    int somma = 0;

    for(int i = 0; i < nregioni; i++)
        somma += (regioni+i)->dati[INDEX_TERAPIA_INTENSIVA];
    return somma;
}


//main
int main(){
    char *nomefile = "contagi.csv";
    
    //lettura da file
    int nLine = leggiRigheFile(nomefile);
    if(nLine == ERROR) printf("error: no such file found\n");
    else{
        Regione *italy = (Regione*) malloc(nLine * sizeof(Regione));
        if(leggifile(italy,nomefile, nLine) == NO_ERROR){
            //stilare le classifiche
            topterapiaIntensiva(italy,nLine);
            printf("\n");
            printf("Totale ricoverati terapia intensiva: %d\n\n",totaleIntensiva(italy,nLine));
            topTotaliPositivi(italy,nLine);

        }
        free(italy);
    }

    return 0;
}
