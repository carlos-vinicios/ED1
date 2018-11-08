#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

using namespace std;

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
            p1->qtd = 1;
        }
    }
    return p1;
}

Palavra *addPalavra(Dicionario *d, char *palavra){
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
    }
    return p1;
}

int addSinonimo(Dicionario *d, char* palavra, char *sinonimo){
    Palavra *p, *p1 = NULL, *p2 = NULL;
    if(d != NULL && palavra != NULL && sinonimo != NULL){
        p = buscarPalavra(d, palavra); //busca pela palavra que será adicionado o sinonimo
        p1 = buscarPalavra(d, sinonimo); //verfica a existência do sinonimo dentro do dicionario
        if(p != NULL){
            p2 = criarPalavra(sinonimo); //cria a palavra de sinonimo
            if(p1 != NULL){
                p1->qtd++; //caso o sinonimo já tenho sido cadastrado no dicionario, atualiza a quantidade
            }else{
                p1 = addPalavra(d, sinonimo); //caso não exista, adiciona a mesma ao dicionario e incrementa a quantidade da mesma
                p1->qtd++;
            }
            if(p->sinonimo == NULL) //adiciona a lista de sinonimos
                p->sinonimo = p2;
            else{
                p2->prox = p->sinonimo;
                p->sinonimo = p2;
            }
        }
        return 1;
    }
    return 0;
}

Palavra *buscarPalavra(Dicionario *d, char *palavra){
    Palavra *aux;
    if(strcmp(d->cab->sintaxe, palavra) == 0){
        return d->cab;
    }else if(strcmp(d->ult->sintaxe, palavra) == 0){
        return d->ult;
    }else{
        aux = d->cab;
        while(aux != NULL){
            if(strcmp(aux->sintaxe, palavra) == 0){
                return aux;
            }
            aux = aux->prox;
        }
    }
    return NULL;
}

Palavra *substituirPalavra(Dicionario *d, char *palavra){
    Palavra *p = NULL, *p2 = NULL, *aux = NULL, *resp = NULL;
    if(d != NULL && palavra != NULL){
        p = buscarPalavra(d, palavra);
        if(p != NULL){
            aux = p->sinonimo;
            if(aux != NULL){
                resp = buscarPalavra(d, aux->sintaxe);
                aux = aux->prox;
                while(aux != NULL){
                    p2 = buscarPalavra(d, aux->sintaxe);
                    if(p2->qtd < resp->qtd)
                        resp = p2;
                    aux = aux->prox;
                }
            }
        }
    }
    return resp;
}

char *formalizarTexto(Dicionario *d, char *paragrafo){
    char *palavra, *paragrafo_final=NULL, element[2];
    Palavra *p=NULL;
    int i, j=0;
    if(d != NULL && paragrafo != NULL){
        paragrafo_final = new char[strlen(paragrafo)];
        palavra = new char[strlen(paragrafo)];
        for(i=0; i < strlen(paragrafo); i++){
            if(paragrafo[i] != ' ' && paragrafo[i] != ',' && paragrafo[i] != '.'){
                palavra[j]=paragrafo[i];
                j++;
            }else{
                palavra[j] = '\0';
                j=0;
                cout << palavra;
                p = substituirPalavra(d, palavra);
                if(p != NULL){
                    strcat(paragrafo_final, p->sintaxe);
                }else{
                    strcat(paragrafo_final, palavra);
                }
                element[0] = paragrafo[i];
                strcat(paragrafo_final, element);
                delete[] palavra;
                palavra = new char[strlen(paragrafo)];
            }
        }
    }
    cout << paragrafo_final;
    return paragrafo_final;
}
