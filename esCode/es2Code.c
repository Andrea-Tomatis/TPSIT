/*
Es02:
  Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
  degli elementi della coda di partenza. Suggerimento: utilizzare una pila.

Author: Andrea Tomatis
*/


#include <stdio.h>
#include <stdlib.h>


#define NO_ERR 0


struct node{
    int val;
    struct node* next;
};


int isempty(struct node* head){
    return (head == NULL) ? 1 : 0;
}


void enqueue(struct node** head, struct node** tail, 
             struct node* element){
    
    if(isempty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;

    return;
}


struct node* dequeue(struct node** head,
                     struct node** tail){
    
    struct node* ret = *head;

    if(isempty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;

    return ret;
}


void push(struct node** head, struct node* element){
    if (isempty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }

    return;
}


struct node* pop(struct node** head){
    struct node* ret = *head;

    if(isempty(*head)){
        return NULL;
    }else 
        *head = ret->next;

    return ret;
}


void caricaCoda(struct node* head, struct node* tail){
    int end;
    struct node* input_node;

    do{
        input_node = (struct node*) malloc(sizeof(struct node));

        printf("\n>Digit a number: ");
        scanf("%d", &input_node->val);
        
        enqueue(&head, &tail, input_node);

        printf(">Do you want to continue? (1/0): ");
        fflush(stdin);
        scanf("%d", &end);

    }while(end != 0);

    return;
}


void caricaPila(struct node* stack, struct node** head,
                struct node** tail){
    struct node* element;

    while(!isempty(*head)){
        element = dequeue(head, tail);
        push(&stack, element);
        free(element);
    }

    return;
}


void invertiCoda(struct node* stack, struct node** head,
                 struct node** tail){
    struct node* element;

    while(!isempty(stack)){
        element = pop(&stack);
        enqueue(head, tail, element);
        free(element);
    }
}


void stampaCoda(struct node* head, struct node* tail){
    struct node* sup;

    while(!isempty(head)){
        sup = dequeue(&head, &tail);
        printf("%d\n", sup->val);
        free(sup);
    }

    return;
}

int main(){
    struct node* head;
    struct node* tail;
    struct node* stack;

    caricaCoda(head, tail);

    caricaPila(stack, &head, &tail);

    invertiCoda(stack, &head, &tail);  

    stampaCoda(head, tail);

    return NO_ERR;
}