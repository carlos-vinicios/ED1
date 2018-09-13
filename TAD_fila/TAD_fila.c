#include <stdlib.h>
#include "TAD_fila.h"

Fila *criar(int qtd_max){
    Fila *fila = NULL;

    if(qtd_max > 0){
        fila = (Fila *) malloc(sizeof(Fila));
        if(fila != NULL){
            fila->dados = (void **) malloc(qtd_max * sizeof(void *));
            if(fila->dados != NULL){
                fila->inicio = 0;
                fila->fim = 0;
                fila->qtd = 0;
                fila->qtd_max = qtd_max;
            }else{
                free(fila);
                fila = NULL;
            }
        }
    }

    return fila;
}

int enfileirar(Fila *fila, void *dado){
    if(fila != NULL && fila->dados != NULL && fila->qtd < fila->qtd_max){
        if(fila->fim == fila->qtd_max)
            fila->fim = fila->fim % fila->qtd_max;

        fila->dados[fila->fim] = dado;
        fila->qtd++;
        fila->fim++;
        return 1;
    }

    return 0;
}

void *desenfileirar(Fila *fila){
    void *aux = NULL;
    if(fila != NULL && fila->dados != NULL && fila->qtd > 0){
        if(fila->inicio == fila->qtd_max)
            fila->inicio = fila->inicio % fila->qtd_max;

        aux = fila->dados[fila->inicio];
        fila->inicio++;
        fila->qtd--;
    }

    return aux;
}

int vazia(Fila *fila){
    if(fila != NULL && fila->dados != NULL && fila->qtd > 0)
        return 0;
    else
        return 1;
}
