#include <stdio.h>
#include <stdlib.h>
#include "TAD_sequencia.h"

int main()
{
    Sequencia *seq;
    int res, i;

    seq = Create(5);

    if(seq == NULL){
        printf("Erro na criação da sequencia\n");
        return 0;
    }

    res = Insert(seq, 3);
    res = Insert(seq, 4);
    res = Insert(seq, 7);
    res = Insert(seq, 21);
    res = Insert(seq, 5);

    for(i = 0; i < seq->qtd; i++){
        printf("%d\n", seq->dados[i]);
    }

    printf("\n");
    res = Search(seq, 4);
    if(res > 0)
        printf("Achou\n");
    else
        printf("Não achou\n");

    res = Search(seq, 99);
    if(res > 0)
        printf("Achou\n");
    else
        printf("Não achou\n");

    res = Remove(seq, 21);

    printf("\n");
    if(res > 0)
        for(i = 0; i < seq->qtd; i++)
            printf("%d\n", seq->dados[i]);

    else
        printf("Não achou o elemento para remover\n");

    return 0;
}
