/*
Verifica 18/02/2021

Andrea Tomatis
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NO_ERR 0
#define ERR -1
//dichiarazione semi
#define CUORI 'C'
#define PICCHE 'P'
#define DENARI 'D'
#define FIORI 'F'
#define N_SEMI 4  //numero semi in un mazzo
#define N_CARTE 13  //numero carte di un seme

struct carta{
    char seme;  //seme della carta
    int nCarta;  //numero della carta (da 1 a 13)
    struct carta* next; 
};


//funzione per verificare se la pila e' vuota
int isempty(struct carta* head){
    return (head == NULL) ? 1 : 0;
}


//funzione per inserire un elemento nella pila
void push(struct carta** head, struct carta* element){
    if (isempty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }

    return;
}


//funzione per estrarre un elemento dalla pila
struct carta* pop(struct carta** head){
    struct carta* ret = *head;

    if(isempty(*head)){
        return NULL;
    }else 
        *head = ret->next;

    return ret;
}


//questa funzione restituisce il carattere rappresentante
//il seme associato all'indice passato in input alla funzione
char trovaSeme(int i){
    switch (i){
        case 0:
            return CUORI;
            break;
        case 1:
            return PICCHE;
            break;
        case 2:
            return DENARI;
            break;
        case 3:
            return FIORI;
            break;
    }

    return ERR;
}


//questa funzione controlla se la carta estratta e' stata gia' pescata
//in precedenza
int isEstratta(int num, int* vett, int lenVet){
    
    for(int i = 0; i < lenVet; i++){
        if(num == *(vett+i))
            return 1;
    }
    return 0;
}


int main(){
    //pila contenente le carte
    struct carta* stack = NULL;

    //struttura di supporto per la push
    struct carta* element;

    //pile contenenti le carte dei 2 giocatori
    struct carta* alice = NULL;
    struct carta* bob = NULL;

    //carta estratta randomicamente per caricare il mazzo
    int cartaEstratta;
    //vettore contenente le carte estratte finora
    int* carteEstratte;
    //numero di carte estratte finora
    int nCarteEstratte;

    //randomizza il seme della funzione random
    srand(time(NULL));

    //ciclo per caricare il mazzo (il piu' esterno cicla sui semi)
    for(int i = 0; i < N_SEMI; i++){
        //inizializzazione delle carte estratte e del vettore di carte estratte
        nCarteEstratte = 0;
        carteEstratte = (int*) malloc(sizeof(int) * N_CARTE);

        //ciclo per inserire nella pila le carte dalla 1 alla 13
        for(int j = 0; j < N_CARTE; j++){

            //ciclo do while che estrae una carta random e controlla se
            //non e' stata gia' estratta in precedenza
            do{
                cartaEstratta = rand()%N_CARTE;
            }while(isEstratta(cartaEstratta, carteEstratte, nCarteEstratte) == 1);

            //la carta estratta viene aggiunta al vettore e il contatore viene incrementato
            *(carteEstratte + nCarteEstratte) = cartaEstratta;
            nCarteEstratte++;

            //la carta (nome e seme) viene inserita nella pila
            element = (struct carta*) malloc(sizeof(struct carta));
            element->nCarta = j+1;
            element->seme = trovaSeme(i); //in base all'indice restituisce il seme
            
            push(&stack, element);

        }
    }
    

    //finche la pila non si svuota distribuisce le carte ai 2 giocatori
    while(!isempty(stack)){

        //l'ordine di consegna della carta e' randomico
        if(rand()%2 == 0){
            push(&alice, pop(&stack));
            push(&bob, pop(&stack));
        }else{
            push(&bob, pop(&stack));
            push(&alice, pop(&stack));
        }
    }
    
    //stampa tutte le carte di alice svuotandone la pila
    printf("carte di Alice:\n");
    while(!isempty(alice)){
        element = pop(&alice);
        printf("%d %c\n", element->nCarta, element->seme);
        free(element);
    }
    
    return NO_ERR;  //esecuzione terminata con successo
}