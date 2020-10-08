/*
Autore: Andrea Tomatis
es: algoritmo di compressione RLE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 100

//tecnica di compressione nella quale gli elementi che si ripetono vengono sostituiti 
//dal numero di ricorrenze seguito dal carattere
void encoding(char s[]){  
    int cnt = 0;  //conta il numero di ricorrenze consecutive di un carattere
    int k = 0;
    char str2[DIM]; //stringa di supporto
    for(int i = 0; s[i] != '\0'; i++){  //scorre la stringa in cerca di caratteri che si ripetono
        cnt = 0; //ad ogni giro il contatore si resetta
        
        if(s[i] == s[i+1]){  //se una carattere si ripete lo comprime
            while(s[i] == s[i+cnt])
                cnt++;
            str2[k++] = cnt + '0';  //nella stringa di supporto viene inserito il numero di ricorrenze
        }
        str2[k++] = s[i];
        i += (cnt-1 >= 0) ? (cnt-1) : cnt;
    }
    str2[k] = '\0'; //inserimento del carattere terminatore
    strcpy(s,str2);  //copia della stringa di supporto nella principale
}

//controlla se un carattere e' un numero nel codice ascii
bool isNumero(char c){
    return c >= 48 && c <= 57;
}

//decomprime una stringa compressa nel RLE (run lenght coding)
void decoding(char s[]){
    int k = 0; 
    char str2[DIM];  //stringa di supporto

    //il programma scorre il vettore e sostituisce i numeri con la ripetizione di caratteri
    for(int i = 0; s[i] != '\0'; i++){
        
        if(isNumero(s[i])){  //se trova un numero decomprime i caratteri che seguono
            for(int j = 0; j < s[i] - '0' - 1; j++)
                str2[k++] = s[i+1];
        }else  //in alternativa copia semplicemente il carattere
            str2[k++] = s[i];
    }
    str2[k] = '\0'; //inserisce il carattere terminatore
    strcpy(s,str2); //copia la stringa di supporto nella stringa principale
}



int main(){

    char str[DIM];
    int opz;

    printf("scegli un'opzione:\n0-encoding\n1-decoding\n");
    scanf("%d",&opz);

    printf("inserisci una stringa: ");
    fflush(stdin);
    scanf("%s",str);

    if(opz == 0)  //se l'opzione scelta e' la 0 si procede con la compressione
        encoding(str);
    else if(opz == 1)  //se l'opzione scelta e' la 0 si procede con la decompressione
        decoding(str);

    printf("%s\n",str);  //stampa la stringa risultante
    return 0;
}