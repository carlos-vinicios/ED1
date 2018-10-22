#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

Dicionario *criarDicionario(){
    Dicionario *d1 = new Dicionario[1];
    d1->cab = NULL;
    d1->ult = NULL;
    return d1;
}

Palavra *criarPalavra(char *sintaxe){
    Palavra *p1 = NULL;
    if(sintaxe != NULL){
        p1 = new Palavra[1];
        if(p1 != NULL){
            p1->sintaxe = sintaxe;
            p1->sinonimo = NULL;
            p1->prox = NULL;
        }
    }
    return p1;
}

int add(Dicionario *d, char *palavra){
    Palavra *p1 = NULL;
    if(d != NULL && palavra != NULL && strlen(palavra) > 0){
        p1 = criarPalavra(palavra);
        if(d->cab == NULL && d->ult == NULL){
            d->cab = p1;
            d->ult = p1;
        }else {
            d->ult->prox = p1;
            d->ult = p1;
        }
        return 1;
    }
    return 0;
}

int addSinonimo(Dicionario *d, char* palavra, char *sinonimo){
    Palavra *p, *p1 = NULL, *aux;
    if(d != NULL && palavra != NULL && sinonimo != NULL){
        p = buscaPalavra(d, palavra);
        if(p != NULL){
            p1 = criarPalavra(sinonimo);
            if(p->sinonimo == NULL)
                p->sinonimo = p1;
            else{
                p1->prox = p->sinonimo;
                p->sinonimo = p1;
            }
        }
        return 1;
    }
//        if(strcmp(d->cab->sintaxe, palavra) == 0){
//            p1 = criarPalavra(sinonimo);
//            if(d->cab->sinonimo == NULL)
//                d->cab->sinonimo = p1;
//            else{
//                p1->prox = d->cab->sinonimo;
//                d->cab->sinonimo = p1;
//            }
//        }else if(strcmp(d->ult->sintaxe, palavra) == 0){
//            p1 = criarPalavra(sinonimo);
//            if(d->ult->sinonimo == NULL)
//                d->ult->sinonimo = p1;
//            else{
//                p1->prox = d->ult->sinonimo;
//                d->ult->sinonimo = p1;
//            }
//        }else{
//            aux = d->cab;
//            while(aux != NULL){
//                if(strcmp(aux->sintaxe, palavra)){
//                    p1->prox = aux->sinonimo;
//                    aux->sinonimo = p1;
//                    break;
//                }
//                aux = aux->prox;
//            }
//        }
//        return 1;
//    }
    return 0;
}

Palavra *buscaPalavra(Dicionario *d, char *palavra){
    Palavra *aux;
    if(strcmp(d->cab->sintaxe, palavra) == 0){
        return d->cab;
    }else if(strcmp(d->ult->sintaxe, palavra) == 0){
        return d->ult;
    }else{
        aux = d->cab;
        while(aux != NULL){
            if(strcmp(aux->sintaxe, palavra)){
                return aux;
            }
            aux = aux->prox;
        }
    }
}
