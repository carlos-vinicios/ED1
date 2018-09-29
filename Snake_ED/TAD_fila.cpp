#include <stdlib.h>
#include "TAD_fila.h"

Fila *criarFila(int tam){
    Fila *f = NULL;
    if(tam > 0){
        f = new Fila[1];
        if(f != NULL){
            f->dados = new char[tam];
            if(f->dados != NULL){
                f->inicio = 0;
                f->fim = 0;
                f->qtd = 0;
                f->tam = tam;
            }else{
                delete[] f;
                f = NULL;
            }
        }
    }

    return f;
}

int adicionar(Fila *f, char chave){
    if(f != NULL && f->dados != NULL && f->qtd < f->tam){
        f->dados[f->fim] = chave;
        f->fim = (f->fim++) % f->tam;
        f->qtd++;
        return 1;
    }
    return 0;
}

char remover(Fila *f){
    char aux = ' ';
    if(f != NULL && f->dados != NULL && f->qtd > 0){
        aux = f->dados[f->inicio];
        f->inicio = (f->inicio++) % f->tam;
        f->qtd--;
    }
    return aux;
}

int destruirFila(Fila *f){
    if(f != NULL){
        delete[] f;
        if(f == NULL){
            return 1;
        }
    }

    return 0;
}

int filaVazia(Fila *f){
    if(f->qtd == 0)
        return 1;

    return 0;
}
