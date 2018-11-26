#include <iostream>
#include "arvore.h"

using namespace std;

int main()
{
    Arvore *arvore1 = criar(7);
    inserir(arvore1, 10);
    inserir(arvore1, 9);
    inserir(arvore1, 11);
    inserir(arvore1, 3);
    inserir(arvore1, 4);
    inserir(arvore1, 2);

    Arvore *arvore2 = criar(7);
    inserir(arvore2, 10);
    inserir(arvore2, 9);
    inserir(arvore2, 11);
    inserir(arvore2, 3);
    inserir(arvore2, 4);
    inserir(arvore2, 11);

    cout << comparar_arvores(arvore1, arvore2);

    return 0;
}
