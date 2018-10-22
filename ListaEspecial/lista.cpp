#include <stdlib.h>
#include "lista.h"

Node *criarNode(int value){
    Node *n1 = new Node[1];
    n1->dado = value;
    n1->prox = NULL;
    return n1;
}

Lista *criarLista(){
    Lista *l = new Lista[1];
    l->cab = NULL;
    l->ult = NULL;
    l->qtd = 0;
    return l;
}

int push(Lista *l, int value){
    Node *n1 = NULL;
    if(l != NULL){
        n1 = criarNode(value);
        if(l->qtd == 0){
            l->cab = n1;
            l->ult = n1;
        }else{
            l->ult->prox = n1;
            l->ult = n1;
        }
        l->qtd++;
        return 1;
    }
    return 0;
}

int pushAfter(Lista *l, int index, int value){
    Node *n1 = NULL, *aux;
    int i = 0;
    if(l != NULL && index < l->qtd){
        n1 = criarNode(value);
        if(index == 0){
            n1->prox = l->cab->prox;
            l->cab->prox = n1;
        }else if(index == (qtd-1)){
            l->ult->prox = n1;
            l->ult = n1;
        }else{
            aux = l->cab
            while(aux != NULL){
                if(index ==  i){
                    n1->prox = aux->prox;
                    aux->prox = n1;
                    break;
                }
                i++;
                aux = aux->prox;
            }
        }
    }
}

Lista *concat(Lista *l1, Lista *l2){
    l1->ult->prox = l2->cab;
    l1->ult = l2->ult
    return l1;
}

Lista *concatOrder(Lista *l1, Lista *l2){
    l1->ult->prox = l2->cab;
    l1->ult = l2->ult;
    order(l1);
    return l1;
}

int clean(Lista *l){
    Node *aux, *aux2;
    if(l != NULL){
        aux = l->cab;
        while(aux != NULL){
            aux2 = aux->prox;
            delete[] aux;
            aux = aux2;
        }
        delete[] l->cab;
        delete[] l->ult;
        l->cab = NULL;
        l->ult = NULL;
        l->qtd = 0;
        return 1;
    }
    return 0;
}

Lista *invert(Lista *l);

int removeLast(Lista *l){
    Node *aux;
    if(l != NULL){
        aux = l->cab;
        while(aux->prox != l->ult)
            aux = aux->prox;

        aux->prox = NULL;
        delete[] l->ult;
        l->ult = aux;
        return 1;
    }
    return 0;
}

//fazer o caso para a última e a primeira posição da lista para não SF
int removeAt(Lista *l, int index){
    Node *aux;
    int i = 0;
    if(l != NULL && index < l->qtd){
        aux = l->cab;
        while(aux != NULL && i < index)
            aux = aux->prox;

        aux->prox = aux->prox->prox;
        return 1;
    }
    return 0;
}

Lista *uni(Lista *l1, Lista *l2);

Lista *intersec(Lista *l1, Lista *l2);

int removeSecond(Lista *l);

Lista *order(Lista *l);

int sum(Lista *l){
    Node *aux;
    int soma = -9999999999999999;
    if(l != NULL){
        soma = 0;
        aux = l->cab;
        while(aux != NULL){
            soma += aux->dado;
            aux = aux->prox;
        }
    }
    return soma;
}

int qtdLista(Lista *l){
    if(l != NULL)
        return l->qtd;

    return -1;
}

Lista *sendTo(Lista *l, int index1, int index2);

Lista *clone(Lista *l){
    return l;
}

