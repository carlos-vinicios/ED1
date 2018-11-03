#include "stdlib.h"
#include "lista.h"

Pessoa *novaPessoa(int chave){
    Pessoa *p = new Pessoa[1];
    p->id = chave;
    p->prox = NULL;
    p->amigo = NULL;
    p->prox_amigo = NULL;
    return p;
}

Rede *criarRede(){
    Rede *r = new Rede[1];
    r->cab = NULL;
    r->ult = NULL;
    return r;
}

int adicionarPessoa(Rede *r, int chave){
    Pessoa *p;
    if(r != NULL){
        p = novaPessoa(chave);
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
        aux2 = aux1;
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
        if(aux1->amigos == NULL){
            Rede *r1 = new Rede[1];
            adicionarPessoa(r1, )
            aux1->amigos = new Pessoa[1];

        }else{
            aux1->amizades = aux2;
            aux1->amizades = aux2;
        }
    }
    return 0;
}
