#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"

using namespace std;

char *to_lower(char *palavra){
    int i;
    char *lower = new char[strlen(palavra)];
    for(i=0; i < strlen(palavra); i++){
        lower[i] = tolower(palavra[i]);
    }
    return lower;
}

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
    Palavra *p1 = NULL, *p2 = NULL;
    if(d != NULL && palavra != NULL && strlen(palavra) > 1){
        p1 = buscarPalavra(d, palavra);
        if(p1 == NULL){
            p2 = criarPalavra(to_lower(palavra));
            if(d->cab == NULL && d->ult == NULL){
                d->cab = p2;
                d->ult = p2;
            }else {
                d->ult->prox = p2;
                d->ult = p2;
            }
        }else{
            p1->qtd++;
        }
    }
    return p2;
}

int addSinonimo(Dicionario *d, char* palavra, char *sinonimo){
    Palavra *p, *p1 = NULL, *p2 = NULL;
    if(d != NULL && palavra != NULL && sinonimo != NULL){
        p = buscarPalavra(d, palavra); //busca pela palavra que será adicionado o sinonimo
        p1 = buscarPalavra(d, sinonimo); //verfica a existência do sinonimo dentro do dicionario
        if(p != NULL){
            p2 = criarPalavra(to_lower(sinonimo)); //cria a palavra de sinonimo
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
    if(d != NULL && d->cab != NULL && palavra != NULL && strlen(palavra) > 1){
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
                if(resp != NULL){
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
    }
    return resp;
}

char *formalizarTexto(Dicionario *d, char *paragrafo){
    char *palavra, *paragrafo_final=NULL, element[2];
    Palavra *p=NULL;
    int i, j=0, paragrafo_size;
    if(d != NULL && paragrafo != NULL){
        paragrafo_size = (int) strlen(paragrafo);
        paragrafo_final = new char[paragrafo_size];
        strcpy(paragrafo_final, "");
        palavra = new char[paragrafo_size];
        for(i=0; i < paragrafo_size; i++){
            if(paragrafo[i] != ' ' && paragrafo[i] != ',' && paragrafo[i] != '.' && i < paragrafo_size-1){
                palavra[j]=paragrafo[i];
                j++;
            }else{
                palavra[j] = '\0';
                p = substituirPalavra(d, to_lower(palavra));
                if(p != NULL){
                    strcat(paragrafo_final, p->sintaxe);
                }else{
                    strcat(paragrafo_final, palavra);
                }
                element[0] = paragrafo[i];
                strcat(paragrafo_final, element);
                delete[] palavra;
                palavra = new char[paragrafo_size];
                j=0;
            }
        }
    }
    return paragrafo_final;
}
