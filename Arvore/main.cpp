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

    cout << abpNumNodesHeightH(arvore1, 1);

    return 0;
}
