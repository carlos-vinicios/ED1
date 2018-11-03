#include <iostream>
#include <stdlib.h>
#include "lista.h"

using namespace std;

void printConjunto(Lista *l){
    ListaDupla *aux = l->cab;
    while(l->cab != NULL){
        cout << l->cab->dado << " ";
        l->cab = l->cab->prox;
    }
    l->cab = aux;
}

void uniao(Lista *a, Lista *b){
    ListaDupla *aux = b->cab;
    while(b->cab != NULL){
        if(buscar(a, b->cab->dado) == NULL){
            adicionar(a, b->cab->dado);
        }
        b->cab = b->cab->prox;
    }
    b->cab = aux;
}

void diferenca(Lista *a, Lista *b){
    ListaDupla *aux = b->cab;
    while(b->cab != NULL){
        if(buscar(a, b->cab->dado) != NULL){
            remover(a, b->cab->dado);
        }
        b->cab = b->cab->prox;
    }
    b->cab = aux;
}

void intersecao(Lista *a, Lista *b){
    ListaDupla *aux = b->cab;
    while(b->cab != NULL){
        if(buscar(a, b->cab->dado) == NULL)
            remover(b, b->cab->dado);

        b->cab = b->cab->prox;
    }
    a->cab = aux;
}

int main(){
    Lista *a = criarLista();
    Lista *b = criarLista();

    adicionar(a, 11);
    adicionar(a, 3);
    adicionar(a, 5);
    adicionar(a, 2);
    adicionar(a, 10);
    adicionar(b, 1);
    adicionar(b, 5);
    adicionar(b, 10);

    intersecao(a, b);
    printConjunto(a);
    return 0;
}
