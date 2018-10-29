#include <stdlib.h>
#include "Pilha_lista.h"

Pilha *criarPilha(){
    Pilha *p = NULL;
    p = new Pilha[1];
    if(p != NULL){
        p->dados = NULL;
        p->qtd = 0;
    }
    return p;
}

int push(Pilha *p, int dado){
    if(p != NULL){
        Lista *antigo = p->dados;
        Lista *novo = new Lista[1];
        novo->dado = dado;
        novo->prox = antigo;
        p->dados = novo;
        p->qtd++;
        return 1;
    }
    return 0;
}

int pop(Pilha *p){
    Lista *rem; //elemento a ser removido
    int dado = -99999999999999999; //dado que irá ser retornado
    if(p != NULL && p->dados->dado != NULL){
        rem = p->dados;
        dado = rem->dado;
        p->dados = rem->prox;
        p->qtd--;
        delete[] rem;
    }
    return dado;
}
