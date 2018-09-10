#include <stdio.h>
#include <stdlib.h>
#include "TAD_generico.h"

int comp(void *a, void *b){
    int *e1 = (int *) a;
    int *e2 = (int *) b;
    if(*e1 == *e2)
        return 1;

    return 0;
}

int main()
{
    Sequencia *s = criar(10, comp);
    int *dado,*chave;

    dado = (int *) malloc(sizeof(int));
    *dado = 1;
    inserir(s, (void *)dado);

    dado = (int *) malloc(sizeof(int));
    *dado = 2;
    inserir(s, (void *)dado);

    chave = (int *) malloc(sizeof(int));
    *chave = 1;

    if(buscar(s, (void *) chave ) >= 0)
        printf("Achou");

}
