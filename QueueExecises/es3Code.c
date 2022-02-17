/*
Es03:
  Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
  enqueue() and dequeue().

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


void push(struct node** head,
          struct node** tail, struct node* element){
    struct node* support_head = NULL;
    struct node* support_tail = NULL;
    struct node* element3;
    while(!isempty(*head)){
        element3 =  dequeue(head, tail);
        enqueue(&support_head, &support_tail,element3);
    }

    enqueue(head, tail, element);

    while(!isempty(support_head)){
        enqueue(head, tail, dequeue(&support_head, &support_tail));
    }

    return;
}


struct node* pop(struct node** head, 
                 struct node** tail){
    return dequeue(head, tail);
}


int main(){
    
    struct node* stack_head = NULL;
    struct node* stack_tail = NULL;
    struct node* element;

    for(int i = 0; i < 10; i++){
        element = (struct node*) malloc(sizeof(struct node));
        
        element->val = i;
        push(&stack_head, &stack_tail, element);
    }

    printf("ultimo elemento: %d\n", pop(&stack_head, &stack_tail)->val);
    
    return 0;
}

