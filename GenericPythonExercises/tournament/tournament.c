/*
Tournament: Tally the results of a small football competition.
            Based on an input file containing which team played against which and 
            what the outcome was, create a file with a table like this:

            Team                           | MP |  W |  D |  L |  P
            Devastating Donkeys            |  3 |  2 |  1 |  0 |  7
            Allegoric Alaskans             |  3 |  2 |  0 |  1 |  6
            Blithering Badgers             |  3 |  1 |  0 |  2 |  3
            Courageous Californians        |  3 |  0 |  1 |  2 |  1

            legend: MP -> Matches played, W -> wins, D -> draws, L -> losses, P -> points

@Andrea-Tomatis
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define WIN 3
#define LOSS 0
#define DRAW 1
#define ERROR -1
#define NO_ERROR 0
#define STR_LEN 1000
#define MAX_TEAMS 100



typedef char* String;
typedef struct team* Team;



struct team{
    String name;
    int n_match, win, loss, draw;
    int points;
};



int readFile(String, Team);
String getField(String, int);
Team search_team(Team, String, int*);
void print_tournament(Team, int);
void selectionSort(Team, int);
void invert(Team, Team);



int main(){
    struct team *tournament = (Team) malloc(sizeof(struct team) * MAX_TEAMS); 
    int k;

    if((k = readFile("./matches.csv", tournament)) == ERROR)
        printf("error: falied file reading\n");
    else
    {
        selectionSort(tournament, k);
        print_tournament(tournament, k);
    }

    return 0;
}



int readFile(String file_name, Team teams){

    FILE *fp = fopen(file_name, "r");
    
    String line = (String) malloc(sizeof(char) * STR_LEN),
           result = (String) malloc(sizeof(char) * STR_LEN);
    
    Team t1 = (Team) malloc(sizeof(struct team)),
         t2 = (Team) malloc(sizeof(struct team));
    
    int k = 0;
    
    if (fp == NULL) return ERROR;
    
    while(fgets(line, STR_LEN, fp) != NULL)
    {
        t1 = search_team(teams, strdup(strtok(line,";\n")), &k);
        t2 = search_team(teams, strdup(strtok(NULL,";")), &k);
        result = strdup(strtok(NULL, ";"));

        t1->n_match += 1;
        t2->n_match += 1;

        if (strcmp(result, "win") == 0 ||
            strcmp(result, "win\n") == 0){
            t1->win += 1;
            t2->loss += 1;
            t1->points += 3;
        }
        else if (strcmp(result, "draw") == 0 || 
                strcmp(result, "draw\n") == 0){
            t1->draw += 1;
            t2->draw += 1;
            t1->points += 1;
            t2->points += 1;
        }
        else if (strcmp(result, "loss") == 0 ||
                strcmp(result, "loss\n") == 0){
            t2->win += 1;
            t1->loss += 1;
            t2->points += 3;
        }else{
            printf("an error occurred: invalid match result\n");
        }

    } 
    
    fclose(fp);
    free(line);
    free(result);
    
    return k;
}



Team search_team(Team teams, String name, int *n){
    for(int i = 0; i < *n; i++){
        if (strcmp((teams+i)->name, name) == 0)
            return teams+i;
    }

    *n += 1;
    (teams + *n - 1)->name = strdup(name);
    (teams + *n - 1)->n_match = 0;
    (teams + *n - 1)->win = 0;
    (teams + *n - 1)->draw = 0;
    (teams + *n - 1)->loss = 0;
    (teams + *n - 1)->points = 0;

    return (teams + *n - 1);
}



void selectionSort(Team t, int n){
    int k,kmin,j;
    for(k = 0; k < n-1; k++) {
        kmin = k;
        for(j = k+1; j < n; j++)
            if((t + kmin)->points <= (t + j)->points)
                kmin = j;
            
        if(kmin != k) invert(t + k, t + kmin);    
    }
    return;
}



void invert(Team t1, Team t2){
    struct team tmp = *t1;
    *t1 = *t2;
    *t2 = tmp;
    return;
}



void print_tournament(Team t, int k){
    printf("-------TOURNAMENT-------\n");
    for (int i = 0; i < k; i++){
        printf("Position %d >>> %s:\n", i+1, (t+i)->name);
        printf("   total points: %d\n", (t+i)->points);
        printf("   played matches: %d\n", (t+i)->n_match);
        printf("   wins: %d\n", (t+i)->win);
        printf("   losses: %d\n", (t+i)->loss);
        printf("   draws: %d\n", (t+i)->draw);
    }
        
    return;
}