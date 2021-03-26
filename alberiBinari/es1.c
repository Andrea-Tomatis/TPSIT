/*
es1: Implementare un'albero binario in C.

Author: Andrea Tomatis
*/

#include <stdio.h>
#include <stdlib.h>


struct tree_node{
    struct tree_node *left;
    struct tree_node *right;
    int key, val;
};


void insert(struct tree_node **tree, struct tree_node *new){

    if (*tree == NULL){
        *tree = new;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }else{
        if (new->key < (*tree)->key)
            insert(&(*tree)->left, new);
        else if (new->key > (*tree)->key)
            insert(&(*tree)->right, new);
        else
            printf("Chiave duplicata\n");
    }

    return;
}


struct tree_node * find_by_key(struct tree_node *tree, int key){
    if (tree == NULL)
        return NULL;
    else{
        if (key == tree->key)
            return tree;
        else if (key > tree->key)
            return find_by_key(tree->right, key);
        else if (key < tree->key)
            return find_by_key(tree->left, key);
    }
}


void printTree(struct tree_node *tree){
    if (tree->left != NULL)
        printTree(tree->left);
    
    printf("val=%d key=%d\n", tree->val, tree->key);

    if (tree->right != NULL)
        printTree(tree->right);
}


int main(){

    struct tree_node *tree = NULL;
    struct tree_node *newLeaf = (struct tree_node*) malloc(sizeof(struct tree_node));

    newLeaf->key = 3;
    printf("inserisci un numero: ");
    scanf("%d", &newLeaf->val);
    insert(&tree, newLeaf);

    newLeaf = (struct tree_node*) malloc(sizeof(struct tree_node));
    newLeaf->key = 4;
    printf("inserisci un numero: ");
    scanf("%d", &newLeaf->val);
    insert(&tree, newLeaf);

    newLeaf = (struct tree_node*) malloc(sizeof(struct tree_node));
    newLeaf->key = 1;
    printf("inserisci un numero: ");
    scanf("%d", &newLeaf->val);
    insert(&tree, newLeaf);

    printTree(tree);

    struct tree_node *sup = find_by_key(tree, 4);
    printf("valore trovato: %d\n", sup->val);

    return 0;
}