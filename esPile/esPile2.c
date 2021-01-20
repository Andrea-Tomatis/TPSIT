/*
Author: Andrea Tomatis

esPile2: Scivere un programma che data un'espressione matematica controlli se le parentesi sono
posizionate correttamente.s

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_ERR 0
#define ERR -1
#define STR_LEN 100

typedef struct operatore{
    char car;
    struct operatore* next;
}Operatore;

int isempty(struct operatore* head){
    return (head == NULL) ? 1 : 0;
}

void push(struct operatore** head, struct operatore* element){
    if (isempty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }

    return;
}


struct operatore* pop(struct operatore** head){
    struct operatore* ret = *head;

    if(isempty(*head)){
        return NULL;
    }else 
        *head = ret->next;

    return ret;
}


int isOpenParenthesis(char c){
    return (c == '(' || c == '[' || c == '{') ? 1 : 0;
}

int isCloseParenthesis(char c){
    return (c == ')' || c == ']' || c == '}') ? 1 : 0;
}



int main(){
    char* espression = (char*) malloc(sizeof(char) * STR_LEN);
    Operatore* parentesi = (Operatore*) malloc(sizeof(Operatore));
    Operatore* support = (Operatore*) malloc(sizeof(Operatore));

    int ok = NO_ERR;

    printf("inserisci un'espressione matematica: ");
    scanf("%s",espression);
    
    for(int i = 0; i < strlen(espression); i++){
        if (isOpenParenthesis(*(espression + i)) == 1){
            support->car = *(espression + i);
            push(&parentesi, support);
        }

        if(isCloseParenthesis(*(espression + i)) == 1){
            if(*(espression + i) != (char)((int)pop(&parentesi)->car + 1))
                ok = ERR;
                break;
        }
    }

    printf("your expression is %s\n",(ok == NO_ERR) ? "right" : "wrong");
    
    return NO_ERR;
}