#include "testes.h"
#include <stdlib.h>

//---------------------- PILHA 1 ---------------------

Pilha *criar(int tam){
    Pilha *p = NULL;
    if(tam > 0){
        p = new Pilha[1];
        if(p != NULL){
            p->dados = new void *[tam];
            if(p->dados != NULL){
                p->qtd=0;
                p->topo=-1;
                p->tam=tam;
            }else{
                delete[] p;
                p = NULL;
            }
        }
    }
    return p;
}

//Pilha *criar(int tam, Comparar c){ //para a questão 15
//    Pilha *p = NULL;
//    if(tam > 0){
//        p = new Pilha[1];
//        if(p != NULL){
//            p->dados = new void *[tam];
//            if(p->dados != NULL){
//                p->qtd=0;
//                p->topo=-1;
//                p->tam=tam;
//                p->comp = c;
//            }else{
//                delete[] p;
//                p = NULL;
//            }
//        }
//    }
//    return p;
//}

void *topo(Pilha *p){
    void *aux = NULL;
    if(p != NULL && p->dados != NULL && p->qtd > 0){
        aux = p->dados[p->topo];
    }
    return aux;
}

int push(Pilha *p, void *dado){
    if(p != NULL && p->dados != NULL && p->qtd < p->tam){
        p->topo++;
        p->dados[p->topo] = dado;
        p->qtd++;
        return 1;
    }
    return 0;
}

void *pop(Pilha *p){
    void *aux = NULL;
    if(p != NULL && p->dados != NULL && p->qtd > 0){
        aux = p->dados[p->topo];
        p->topo--;
        p->qtd--;
    }
    return aux;
}

int vazia(Pilha *p){
    if(p != NULL && p->dados != NULL){
        if(p->qtd == 0)
            return 1;
        else
            return 0;
    }
    return -1;
}

int destruir(Pilha *p){
    if(p != NULL){
        delete[] p;
        p = NULL;
        if(p == NULL){
            return 1;
        }
    }
    return 0;
}

//int busca_e_remove(Pilha *p, void *v){
//    void *aux;
//    aux = pop(p);
//    if(p->comp(aux, v)){
//        return 1;
//    }else{
//        if(p->qtd > 0){
//            if(busca_e_remove(p, v)){
//                push(p, aux);
//                return 1;
//            }
//        }
//        push(p, aux);
//        return 0;
//    }
//}

//---------------------------- PILHA 2 (DUPLA) -------------------------

PilhaDupla *criarPilhaDupla(int tam1, int tam2){
    PilhaDupla *pd = NULL;
    if(tam1 > 0 && tam2 > 0){
        pd = new PilhaDupla[1];
        if(pd != NULL){
            pd->dados = new void *[tam1 + tam2];
            if(pd->dados != NULL){
                pd->qtd1 = 0;
                pd->tam1 = tam1;
                pd->topo1 = -1;
                pd->qtd2 = 0;
                pd->tam2 = tam2;
                pd->topo2 = tam1 - 1;
            }else{
                delete[] pd;
                pd = NULL;
            }
        }
    }

    return pd;
}

void *topo1(PilhaDupla *p){
    if(p != NULL && p->dados != NULL && p->qtd1 > 0){
        return p->dados[p->topo1];
    }

    return NULL;
}

void *topo2(PilhaDupla *p){
    if(p != NULL && p->dados != NULL && p->qtd2 > 0){
        return p->dados[p->topo2];
    }

    return NULL;
}

int push1(PilhaDupla *p, void *dado){
    if(p != NULL && p->dados != NULL && p->qtd1 < p->tam1){
        p->topo1++;
        p->dados[p->topo1] = dado;
        p->qtd1++;
        return 1;
    }
    return 0;
}

int push2(PilhaDupla *p, void *dado){
    if(p != NULL && p->dados != NULL && p->qtd2 < p->tam2){
        p->topo2++;
        p->dados[p->topo2] = dado;
        p->qtd2++;
        return 1;
    }
    return 0;
}

void *pop1(PilhaDupla *p){
    void *aux = NULL;
    if(p != NULL && p->dados != NULL && p->qtd1 > 0){
        aux = p->dados[p->topo1];
        p->topo1--;
        p->qtd1--;
    }
    return aux;
}

void *pop2(PilhaDupla *p){
    void *aux = NULL;
    if(p != NULL && p->dados != NULL && p->qtd2 > 0){
        aux = p->dados[p->topo2];
        p->topo2--;
        p->qtd2--;
    }
    return aux;
}

int vazia1(PilhaDupla *p){
    if(p != NULL && p->dados != NULL){
        if(p->qtd1 == 0)
            return 1;
        else
            return 0;
    }
    return -1;
}

int vazia2(PilhaDupla *p){
    if(p != NULL && p->dados != NULL){
        if(p->qtd2 == 0)
            return 1;
        else
            return 0;
    }
    return -1;
}

//-------------------- FILA -------------------
//Fila *criarFila(int tam){
//    if(tam > 0){
//
//    }
//
//    return
//}

//----------------------- QUESTÃO 10 ----------------
//Fila *removeElemento(Fila *q, int x){
//    Fila *f;
//    int i, c;
//    if(q != NULL && q->dados != NULL && q->qtd > 0){
//        f = criarFila(q->tam);
//        c = q->qtd;
//        for(i = 0; i < c; i++){
//            if(desenfileirar(q) != x){
//                enfileirar(f, x)
//            }
//        }
//
//        return f;
//    }
//    return NULL;
//}

//--------------------- QUESTÃO 12 ----------------------------
//int pesqFila(Fila *q, int x){
//    Fila *f;
//    int i, a = 0, aux;
//
//    if(q != NULL && q->dados != NULL && q->qtd > 0){
//        f = criarFila(q->tam);
//        aux = desenfileirar(q);
//        if(aux == x)
//            a = 1;
//        enfileirar(f, aux);
//    }
//
//    q = f;
//    return f;
//}

//-----------------------------------QUESTÃO 14-------------------------------
int removeRepeticoes(Fila *f1, Fila *f2){
    Fila *f3, *f4;
    int i, j;
    if(f1 != NULL && f1->dados != NULL && f1->qtd > 0 && f2 != NULL && f2->dados != NULL && f2->qtd > 0){
//        f3 = criarFila(f1->tam);
  //      f4 = criarFila(f2->tam);
        do{
            f3->dados[f3->fim] = f1->dados[f1->inicio];
            f3->fim++;
            f3->qtd++;
            if(f1->dados[f1->inicio] != f2->dados[f2->inicio]){
                f4->dados[f4->fim] = f2->dados[f2->inicio];
                f4->fim++;
                f4->qtd++;
            }
            f1->inicio++;
            f2->inicio++;
        }while(f1->qtd > 0);
        f1 = f3;
        f2 = f4;
        return 1;
    }

    return 0;
}
