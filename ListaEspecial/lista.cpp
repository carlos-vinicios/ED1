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
        }else if(index == (l->qtd-1)){
            l->ult->prox = n1;
            l->ult = n1;
        }else{
            aux = l->cab;
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
        return 1;
    }
    return 0;
}

int findElement(Lista *l, int key){
    Node *aux;
    if(l != NULL){
        aux = l->cab;
        while(aux != NULL){
            if(aux->dado == key)
                return 1;
            aux = aux->prox;
        }
    }
    return 0;
}

Lista *concat(Lista *l1, Lista *l2){
    l1->ult->prox = l2->cab;
    l1->ult = l2->ult;
    return l1;
}

Lista *concatOrder(Lista *l1, Lista *l2){
    l1->ult->prox = l2->cab;
    l1->ult = l2->ult;
    order(l1);
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

Lista *invert(Lista *l){
    Lista *nova = NULL;
    int i;
    if(l != NULL){
        nova = criarLista();
        for(i=0; i < l->qtd; i++){
            push(nova, l->ult->dado);
            removeLast(l);
        }
    }
    return nova;
}

int removeLast(Lista *l){
    Node *aux;
    if(l != NULL){
        aux = l->cab;
        if(aux != l->ult){
            while(aux->prox != l->ult)
                aux = aux->prox;
            aux->prox = NULL;
            delete[] l->ult;
            l->ult = aux;
        }else{
            delete[] l->cab;
            delete[] l->ult;
            l->cab = NULL;
            l->ult = NULL;
        }
        return 1;
    }
    return 0;
}

int removeAt(Lista *l, int index){
    Node *aux;
    int i = 0;
    if(l != NULL && index < l->qtd){
        if(index == 0){
            aux = l->cab;
            l->cab = l->cab->prox;
            delete[] aux;
        } else if(index == l->qtd - 1){
            removeLast(l);
        }else {
            aux = l->cab;
            while(aux != NULL && i < (index-1)){
                aux = aux->prox;
                i++;
            }
            aux->prox = aux->prox->prox;
        }
        return 1;
    }
    return 0;
}

Lista *uni(Lista *l1, Lista *l2){
    Node *aux;
    if(l1 != NULL && l2 != NULL){
        aux = l2->cab;
        while(aux != NULL){
            if(!findElement(l1, aux->dado))
                push(l1, aux->dado);
            aux = aux->prox;
        }
        return l1;
    }
    return NULL;
}

Lista *intersec(Lista *l1, Lista *l2){
    Lista *nova = NULL;
    Node *aux;
    if(l1 != NULL && l2 != NULL){
        nova = new Lista[1];
        aux = l2->cab;
        while(aux != NULL){
            if(findElement(l1, aux->dado))
                push(nova, aux->dado);
            aux = aux->prox;
        }
    }
    return nova;
}

int removeSecond(Lista *l){
    if(l != NULL && l->qtd >= 2){
        l->cab->prox = l->cab->prox->prox;
        return 1;
    }
    return 0;
}

Lista *order(Lista *l){
    Node *a, *b;
    int c;
    if(l != NULL){
        if(l->qtd >= 2){
            a = l->cab;
            b = l->cab->prox;
            while(a != NULL && b != NULL){
                if(a->dado > b->dado){
                    c = a->dado;
                    a->dado = b->dado;
                    b->dado = c;
                }
                a = b;
                b = b->prox;
            }
        }
        return l;
    }
    return NULL;
}

int sum(Lista *l){
    Node *aux;
    int soma = -99999999;
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

Lista *sendTo(Lista *l, int index1, int index2){
    Node *aux, *ant;
    int i=0;
    if(l != NULL && index1 < l->qtd && index2 < l->qtd){
        aux = l->cab;
        while(i != index1){
            aux = aux->prox;
            i++;
        }
        pushAfter(l, index2, aux->dado);
        removeAt(l, index1);
        //if(index1 == 0)
            //l->cab = l->cab->prox;
        return l;
    }
    return NULL;
}

Lista *clone(Lista *l){
    return l;
}

