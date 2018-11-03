#include "lista.h"
#include <stdlib.h>

ListaDupla *criarNo(int valor){
    ListaDupla *novo = new ListaDupla[1];
    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

Lista *criarLista(){
    Lista *l1 = new Lista[1];
    l1->cab = NULL;
    l1->rabo = NULL;
    return l1;
}

void adicionar(Lista *l, int valor){
    ListaDupla *novo = criarNo(valor);
    if(l->cab == NULL && l->rabo == NULL){
        l->cab = novo;
        l->rabo = novo;
    }else{
        novo->ant = l->rabo;
        l->rabo->prox = novo;
        l->rabo = novo;
    }
    return;
}

int remover(Lista *l, int dado){
    ListaDupla *cab_aux = l->cab;
    ListaDupla *re = NULL;
    if(dado == l->cab->dado){
        re = l->cab;
        cab_aux = l->cab->prox;
        cab_aux->ant = NULL;
    }else if(dado == l->rabo->dado){
        re = l->rabo;
        l->rabo->ant->prox = NULL;
    }else{
        while(l->cab != NULL){
            if(l->cab->dado == dado){
                re = l->cab;
                l->cab->ant->prox = re->prox;
                l->cab->prox->ant = re->ant;
                break;
            }
            l->cab = l->cab->prox;
        }
    }
    if(re != NULL){
        delete[] re;
        re = NULL;
        l->cab = cab_aux;
        return 1;
    }
    l->cab = cab_aux;
    return 0;
}

ListaDupla *buscar(Lista *l, int dado){
    int c = 0;
    ListaDupla *cab_aux = l->cab;
    ListaDupla *elemento;
    while(l->cab != NULL){
        if(l->cab->dado == dado){
            elemento = l->cab;
            l->cab = cab_aux;
            return elemento;
        }
        c++;
        l->cab = l->cab->prox;
    }
    l->cab = cab_aux;
    return NULL;
}
