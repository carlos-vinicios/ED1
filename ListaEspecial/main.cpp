#include <iostream>
#include "lista.h"

using namespace std;

void printLista(Lista *l){
    Node *aux = l->cab;
    while(aux != NULL){
        cout << aux->dado << '\n';
        aux = aux->prox;
    }
}

int main()
{
    Lista *l1 = criarLista();
    Lista *l2 = criarLista();
    Lista *l3;
    push(l1, 1);
    push(l1, 4);
    push(l1, 6);
    push(l2, 2);
    push(l2, 3);
    push(l2, 8);
    push(l2, 6);

    l3 = invert(l2);

    printLista(l3);
    //cout << '\n';
    //printLista(l2);
    return 0;
}
