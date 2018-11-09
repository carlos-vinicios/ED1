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
    Palavra *p = buscarPalavra(d1, palavra);
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
    char *texto;
    Dicionario *d1 = criarDicionario();

    addPalavra(d1, "Testar");
    addPalavra(d1, "Executar");
    addSinonimo(d1, "testar", "verificar");
    addSinonimo(d1, "testar", "analisar");
    addSinonimo(d1, "executar", "fazer");
    addSinonimo(d1, "executar", "realizar");

    texto = formalizarTexto(d1, "Desejo executar varios projetos, afim de testar a capacidade de nossa equipe");

    cout << texto;
    return 0;
}
