

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#define DIM 100

int sommavett(float vett[], int dim);
void contagiati(float v[],int *dimvett, float r, int n; 
void stampaVett(float vett[], int dim);


int sommavett(float vett[], int dim){
    float num = 0;
    for(int i = 0; i < dim; i++)
        num += vett[i];
    return num;
}

void contagiati(float v[],int *dimvett, float r, int n){
    *dimvett = 1;
    v[0] =  1;
    for(int i = 1; sommavett(v,*dimvett) < n; i++){
        v[i] = v[i-1] * (int)r;
        *dimvett += 1;
    }
    
    v[*dimvett-1] = n;
    return;
}

void stampaVett(float vett[], int dim){
    for(int i = 0; i < dim; i++)
        printf("%.0f ",vett[i]);
}

int main(){
    int n;
    float r;
    float cont[DIM];
    int dimVet;

    printf("inserisci il numero di persone contagiate da ognuno: ");
    scanf("%f",&r);
    printf("inserisci il numero di studenti nella classe: ");
    scanf("%d",&n);

    contagiati(cont,&dimVet,r,n);
    printf("numero di giorni di contagio: %d\ncontagiati per giorno:\n",dimVet);
    stampaVett(cont,dimVet);

    return 0;
}