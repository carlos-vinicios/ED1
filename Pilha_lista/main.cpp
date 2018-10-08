#include <iostream>
#include <stdlib.h>
#include "Pilha_lista.h"

using namespace std;

int main()
{
    Pilha *p = criarPilha();
    int *dado;

    dado = new int[1];
    *dado = 5;
    push(p, (void *) dado);
    dado = new int[1];
    *dado = 10;
    push(p, (void *) dado);
    dado = new int[1];
    *dado = 7;
    push(p, (void *) dado);
    dado = new int[1];
    *dado = 2;
    push(p, (void *) dado);

    dado = (int *) pop(p);
    cout << *dado << '\n';
    dado = (int *) pop(p);
    cout << *dado << '\n';
    dado = (int *) pop(p);
    cout << *dado << '\n';
    dado = (int *) pop(p);
    cout << *dado << '\n';

    return 0;
}
