#include <stdlib.h>
#include "TAD_pilha.h"

Pilha *criarPilha(int tam){
    Pilha *p = NULL;
    if(tam > 0){
        p = new Pilha[1];
        if(p != NULL){
            p->dados = new char[tam];
            if(p->dados != NULL){
                p->qtd = 0;
                p->tam = tam;
                p->topo = -1;
            }
        }
    }

    return p;
}

int empilhar(Pilha *p, char chave){
    if(p != NULL && p->dados != NULL && p->qtd < p->tam){
        p->topo++;
        p->dados[p->topo] = chave;
        p->qtd++;
        return 1;
    }

    return 0;
}

char desempilhar(Pilha *p){
    char aux;
    aux = ' ';
    if(p != NULL && p->dados != NULL && p->qtd > 0){
        aux = p->dados[p->topo];
        p->topo--;
        p->qtd--;
    }
    return aux;
}

int destruirPilha(Pilha *p){
    if(p != NULL){
        delete[] p;
        if(p == NULL)
            return 1;
    }

    return 0;
}

int pilhaVazia(Pilha *p){
    if(p->qtd == 0)
        return 1;

    return 0;
}
