#include <stdio.h>
#include <stdlib.h>
#include "TAD_generico.h"

int comp(void *a, void *b){
    int *n1 = (int *) a;
    int *n2 = (int *) b;

    if(*n1 == *n2)
        return 0;
    else{
        if(*n1 < *n2)
            return -1;
        else
            return 1;
    }
}

void imprime(Sequencia *seq){
    for(int i = 0; i < seq->qtd; i++)
        if(seq->dados[i] != NULL)
            printf("%d\n", *((int *) seq->dados[i]));
}

int main()
{
    int *dado,*chave;

    Sequencia *seq = criar(5, comp);
    if(seq == NULL)
        return 0;

    dado = (int *) malloc(sizeof(int));
    *dado = 1;

    if(!inserirOrdenado(seq, (void *)dado))
        return 0;

    dado = (int *) malloc(sizeof(int));
    *dado = 3;

    if(!inserirOrdenado(seq, (void *)dado))
        return 0;

    dado = (int *) malloc(sizeof(int));
    *dado = 2;

    if(!inserirOrdenado(seq, (void *)dado))
        return 0;

    dado = (int *) malloc(sizeof(int));
    *dado = 10;

    if(!inserirOrdenado(seq, (void *)dado))
        return 0;

    dado = (int *) malloc(sizeof(int));
    *dado = 7;

    if(!inserirOrdenado(seq, (void *)dado))
        return 0;

    imprime(seq);

    /*
    dado = (int *) malloc(sizeof(int));
    *dado = 3;

    if(!setNull(seq, (void *)dado))
        return 0;

    dado = (int *) malloc(sizeof(int));
    *dado = 40;

    if(!inserirNull(seq, (void *)dado))
        return 0; */

}
