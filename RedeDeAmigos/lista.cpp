#include <iostream>
#include "stdlib.h"
#include "lista.h"

using namespace std;

Pessoa *criarPessoa(int chave){
    Pessoa *p = new Pessoa[1];
    p->id = chave;
    p->prox = NULL;
    p->amigos = criarLista();
    return p;
}

Amigo *criarAmigo(int chave){
    Amigo *amigo = new Amigo[1];
    amigo->chave = chave;
    amigo->prox = NULL;
    return amigo;
}

Rede *criarRede(){
    Rede *r = new Rede[1];
    r->cab = NULL;
    r->ult = NULL;
    return r;
}

Amigos *criarLista(){
    Amigos *a = new Amigos[1];
    a->ini = NULL;
    a->ult = NULL;
    return a;
}

int novaPessoa(Rede *r, int chave){
    Pessoa *p;
    if(r != NULL){
        p = criarPessoa(chave);
        if(r->cab == NULL && r->ult == NULL){
            r->cab = p;
            r->ult = p;
        }else{
            r->ult->prox = p;
            r->ult = p;
        }
        return 1;
    }
    return 0;
}

int adicionarAmigo(Rede *r, int chave1, int chave2){
    Pessoa *aux1, *aux2;
    if(chave1 != chave2){
        aux1 = r->cab;
        aux2 = r->cab;
        while(aux1 != NULL){
            if(aux1->id == chave1)
                break;
            aux1 = aux1->prox;
        }
        while(aux2 != NULL){
            if(aux2->id == chave2)
                break;
            aux2 = aux2->prox;
        }
        adicionarNovoAmigo(aux1->amigos, chave2);
        adicionarNovoAmigo(aux2->amigos, chave1);
        return 1;
    }
    return 0;
}

int adicionarNovoAmigo(Amigos *a, int chave){
    Amigo *amigo;
    if(a != NULL && !buscarListaAmigo(a, chave)){
        amigo = criarAmigo(chave);
        if(a->ult == NULL && a->ini == NULL){
            a->ult = a->ini = amigo;
        }else{
            a->ult->prox = amigo;
            a->ult = amigo;
        }
        return 1;
    }
    return 0;
}

int buscarListaAmigo(Amigos *a, int chave){
    Amigo *aux;
    if(a != NULL){
        aux = a->ini;
        while(aux != NULL){
            if(aux->chave == chave)
                return 1;
            aux = aux->prox;
        }
    }
    return 0;
}

void indiretos(Rede *r, int chave, int atual){
    Pessoa *aux = r->cab;
    while(aux != NULL){
        if(aux->id == chave)
            break;
        aux = aux->prox;
    }
    Amigo *aux_a = aux->amigos->ini;
    cout << "Indiretos:\n";
    while(aux_a != NULL){
        if(aux_a->chave != atual)
            cout << aux_a->chave << '\n';
        aux_a = aux_a->prox;
    }
}

void listarAmigos(Rede *r, int chave){
    Pessoa *aux = r->cab;
    while(aux != NULL){
        if(aux->id == chave)
            break;
        aux = aux->prox;
    }
    Amigo *aux_a = aux->amigos->ini;
    cout << "Diretos:\n";
    while(aux_a != NULL){
        cout << aux_a->chave << '\n';
        aux_a = aux_a->prox;
    }
    aux_a = aux->amigos->ini;
    while(aux_a != NULL){
        indiretos(r, aux_a->chave, chave);
        aux_a = aux_a->prox;
    }
}

