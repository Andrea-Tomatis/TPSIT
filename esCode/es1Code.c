/*
Es01:
  Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
  all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
  testare la funzione dequeue per svuotare la coda.

Author: Andrea Tomatis
*/


#include <stdio.h>
#include <stdlib.h>


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


void printQueue(struct node** head,
                struct node** tail){
    struct node* support;
    
    while(support != NULL){
        //assign to support the last element of the queue
        support = dequeue(head, tail);
        //print the value of support
        printf("%d", support->val);
        //free the memory containing the last element of the queue
        free(support);
    }
    
    return;
}


int main(){
    
    struct node* head;
    struct node* tail;
    struct node* input_node;
    int end;
    
    do{
        input_node = (struct node*) malloc(sizeof(struct node));

        printf("\n>Digit a number: ");
        scanf("%d", &input_node->val);
        
        enqueue(&head, &tail, input_node);

        printf(">Do you want to continue? (1/0): ");
        fflush(stdin);
        scanf("%d", &end);

    }while(end != 0);

    printQueue(&head, &tail);

    return 0;
}