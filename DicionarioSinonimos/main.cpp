#include <iostream>
#include "dicionario.h"

using namespace std;

void printDic(Dicionario *d1){
    Palavra *aux = d1->cab;
    while(aux != NULL){
        cout << aux->sintaxe << '\n';
        aux=aux->prox;
    }
}

void printSin(Dicionario *d1, char *palavra){
    Palavra *aux;
    Palavra *p = buscaPalavra(d1, palavra);
    if(p != NULL){
        aux = p->sinonimo;
        while(aux != NULL){
            cout << aux->sintaxe << '\n';
            aux = aux->prox;
        }
    }
}

int main()
{
    Dicionario *d1 = criarDicionario();
    return 0;
}
