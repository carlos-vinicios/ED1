#include <stdlib.h>
#include <string.h>
#include "arvore.h"

Pessoa *cadastrarPessoa(int matricula, char *nome, int dataEntrada, int dataSaida){
    Pessoa *p = new Pessoa[1];
    p->matricula = matricula;
    p->nome = nome;
    p->date_in = dataEntrada;
    p->date_out = dataSaida;
    return p;
}

int editarPessoa(Pessoa *p, char *nome, int dataEntrada, int dataSaida){
    if(p != NULL){
        p->nome = nome;
        p->date_in = dataEntrada;
        p->date_out = dataSaida;
    }
    return 0;
}

ArvoreNome *criarArvoreNome(Pessoa *p){
    ArvoreNome *novo = new ArvoreNome[1];
    novo->pessoa = p;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

int inserirArvoreNome(ArvoreNome *an, Pessoa *p){
    if(an != NULL){
        if(p->nome[0] > an->pessoa->nome[0])
            if(an->dir != NULL)
                return inserirArvoreNome(an->dir, p);
            else{
                an->dir = criarArvoreNome(p);
                return 1;
            }
        else
            if(an->esq != NULL)
                return inserirArvoreNome(an->esq, p);
            else{
                an->esq = criarArvoreNome(p);
                return 1;
            }
    }
    return 0;
}

Lista *buscarArvoreNome(ArvoreNome *an, char *nome){ //e se tiver mais um "Carlos" - melhor retornar uma lista
    ArvoreNome *aux = NULL
    Lista *pessoas = NULL;
    if(an != NULL){
        aux = an;
        while(aux->pessoa != NULL){
            if(aux->pessoa->nome[0] == nome[0])
                if(strstr(aux->pessoa->nome, nome) != NULL)
                    if(pessoas == NULL)
                        pessoas = criarNoLista(aux->pessoa);
                    else
                        acrescentar(pessoas, aux->pessoa);
            if(nome[0] > aux->pessoa->nome[0])
                aux = aux->dir;
            else
                aux = aux->esq;
        }
    }
    return pessoas;
}

ArvoreDataEntrada *criarArvoreDataEntrada(Pessoa *p){
    ArvoreDataEntrada *novo = new ArvoreDataEntrada[1];
    novo->pessoa = p;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

int inserirArvoreDataEntrada(ArvoreDataEntrada *ade, Pessoa *p){
    if(ade != NULL){
        if(p->date_in > ade->pessoa->date_in)
            if(ade->dir != NULL)
                return inserirArvoreDataEntrada(ade->dir, p);
            else{
                ade->dir = criarArvoreDataEntrada(p);
                return 1;
            }
        else
            if(ade->esq != NULL)
                return inserirArvoreDataEntrada(ade->esq, p);
            else{
                ade->esq = criarArvoreDataEntrada(p);
                return 1;
            }
    }
    return 0;
}

Lista *buscarArvoreArvoreDataEntrada(ArvoreDataEntrada *ade, int data){//e se tiver mais um com a mesma data de entrada?
    ArvoreDataEntrada *aux = NULL
    Lista *pessoas = NULL;
    if(ade != NULL){
        aux = ade;
        while(aux->pessoa != NULL){
            if(aux->pessoa->date_in == data)
                if(pessoas == NULL)
                    pessoas = criarNoLista(aux->pessoa);
                else
                    acrescentar(pessoas, aux->pessoa);
            if(data > aux->pessoa->date_in)
                aux = aux->dir;
            else
                aux = aux->esq;
        }
    }
    return pessoas;
}

ArvoreDataSaida *criarArvoreDataSaida(Pessoa *p){
    ArvoreDataSaida *novo = new ArvoreDataSaida[1];
    novo->pessoa = p;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

int inserirArvoreDataSaida(ArvoreDataSaida *ads, Pessoa *p){
    if(ads != NULL){
        if(p->date_in > ads->pessoa->date_in)
            if(ads->dir != NULL)
                return inserirArvoreDataSaida(ads->dir, p);
            else{
                ads->dir = criarArvoreDataSaida(p);
                return 1;
            }
        else
            if(ads->esq != NULL)
                return inserirArvoreDataSaida(ads->esq, p);
            else{
                ads->esq = criarArvoreDataSaida(p);
                return 1;
            }
    }
    return 0;
}

Lista *buscarArvoreDataSaida(ArvoreDataSaida *ads, int data){//e se tiver mais de um com a mesma data de saida?
    ArvoreDataSaida *aux = NULL
    Lista *pessoas = NULL;
    if(ads != NULL){
        aux = ads;
        while(aux->pessoa != NULL){
            if(aux->pessoa->date_out == data)
                if(pessoas == NULL)
                    pessoas = criarNoLista(aux->pessoa);
                else
                    acrescentar(pessoas, aux->pessoa);
            if(data > aux->pessoa->date_out)
                aux = aux->dir;
            else
                aux = aux->esq;
        }
    }
    return pessoas;
}

Lista *criarNoLista(Pessoa *p){
    Lista *l = new Lista[1];
    l->pessoa = p;
    l->qtd = 1;
    l->prox = NULL;
    return l;
}

int acrescentar(Lista *l, Pessoa *p){
    Lista *novo = NULL;
    if(l != NULL){
        novo = criarLista(p);
        novo->prox = l;
        l = novo;
        return 1;
    }
    return 0;
}

int destruirLista(Lista *l){
    Lista *aux = NULL;
    if(l != NULL){
        while(l != NULL){
            aux = l;
            delete[] aux;
            l = l->prox;
        }
        return 1;
    }
    return 0;
}
