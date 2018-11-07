#include <iostream>
#include "stdlib.h"
#include "lista.h"

using namespace std;

void imprimeRede(Rede *r){
    Pessoa *aux = r->cab;
    while(aux != NULL){
        cout << aux->id << "\n";
        aux = aux->prox;
    }
}

int main()
{
    Rede *rede = criarRede();

    novaPessoa(rede, 125);
    novaPessoa(rede, 256);
    novaPessoa(rede, 789);

    adicionarAmigo(rede, 125, 256);
    adicionarAmigo(rede, 256, 789);

    listarAmigos(rede, 125);

    return 0;
}
