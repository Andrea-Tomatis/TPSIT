#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_ERR 0
#define ERR -1

struct inverso{
    int cifra;
    struct inverso* next;
};

int isempty(struct inverso* head){
    return (head == NULL) ? 1 : 0;
}

void push(struct inverso** head, struct inverso* element){
    if (isempty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }

    return;
}


struct inverso* pop(struct inverso** head){
    struct inverso* ret = *head;

    if(isempty(*head)){
        return NULL;
    }else 
        *head = ret->next;

    return ret;
}


int main(){
    int num;
    int new_num = 0;
    struct inverso* n_invertito = (struct inverso*) malloc(sizeof(struct inverso));
    struct inverso* support;
    printf("inserisci un numero intero: ");
    scanf("%d",&num);

    while (num > 0){
        support = (struct inverso*) malloc(sizeof(struct inverso));
        support->cifra = num%10;
        push(&n_invertito,support);

        new_num = new_num * 10 + pop(&n_invertito)->cifra;
        num = num / 10;
    }

    
    printf("inverso: %d\n",new_num);

    return NO_ERR; 
}