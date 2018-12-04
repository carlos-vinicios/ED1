#include <iostream>
#include <stdlib.h>
#include "arvore.h"
#include "lista.h"

using namespace std;

Arvore *criar(int dado){
    Arvore *novo = new Arvore[1];
    novo->dado = dado;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
}

int inserir(Arvore *a, int dado){
    if(a != NULL){
        if(dado > a->dado){
            if(a->dir != NULL)
                return inserir(a->dir, dado);
            else{
                a->dir = criar(dado);
                return 1;
            }
        }else{
            if(a->esq != NULL)
                return inserir(a->esq, dado);
            else{
                a->esq = criar(dado);
                return 1;
            }
        }
    }
    return 0;
}

Arvore *buscar(Arvore *a, int dado){
    Arvore *aux = NULL;
    if(a != NULL){
        aux = a;
        while(aux != NULL){
            if(aux->dado == dado)
                return aux;
            if(dado > aux->dado)
                aux = aux->dir;
            else
                aux = aux->esq;
        }
    }
    return NULL;
}

int remover(Arvore *a, int dado) {
    Arvore *folha = NULL, *rem = NULL;
    if(a != NULL){
        rem = buscar(a, dado);
        if(rem != NULL){
            if(rem->dir != NULL && rem->esq != NULL){
                folha = sucessor(rem);
                rem->dado = folha->dado;
                return remover(rem->esq, folha->dado);
            }else{
                if(rem->dir != NULL || rem->esq != NULL){
                    if(rem->dir != NULL){
                        rem->dado = rem->dir->dado;
                        return remover(rem->dir, rem->dir->dado);
                    }else{
                        if(rem->esq != NULL){
                            rem->dado = rem->esq->dado;
                            return remover(rem->esq, rem->esq->dado);
                        }
                    }
                }else{
                    delete[] rem;
                    rem = NULL;
                    return 1;
                }
            }
        }
    }
    return 0;
}

Arvore *sucessor(Arvore *a){
    return maior(a);
}

Arvore *maior(Arvore *a){
    Arvore *aux = NULL;
    if(a != NULL){
        aux = a;
        while(aux != NULL)
            aux = aux->dir;
        return aux;
    }
}

void print_arvore(Arvore *a){
    if(a != NULL){
        cout << a->dado <<'\n';
        if(a->dir != NULL)
            print_arvore(a->dir);
        if(a->esq != NULL)
            print_arvore(a->esq);
    }
}

void print_folhas(Arvore *a){
    if(a != NULL){
        if(a->dir == NULL && a->esq == NULL){
            cout << a->dado <<'\n';
        }else{
            if(a->dir != NULL)
                print_folhas(a->dir);
            if(a->esq != NULL)
                print_folhas(a->esq);
        }
    }
}

void print_nivel(Arvore *a, int n){
    int i=0;
    if(a != NULL){
        if(n == 0)
            cout << a->dado << '\n';
        else{
            n-=1;
            if(a->dir != NULL)
                print_nivel(a->dir, n);
            if(a->esq != NULL)
                print_nivel(a->esq, n);
        }
    }
}

void *arvore_lista(Arvore *a, Lista *l){
    if(a != NULL){
        push(l, a->dado);
        if(a->dir != NULL)
            arvore_lista(a->dir, l);
        if(a->esq != NULL)
            arvore_lista(a->esq, l);
    }
}

int comparar_arvores(Arvore *a1, Arvore *a2){
    int fal = 1;
    if(a1 != NULL && a2 != NULL){
        Lista *l1 = criarLista();
        Lista *l2 = criarLista();
        arvore_lista(a1, l1);
        arvore_lista(a2, l2);
        Node *aux1 = l1->cab;
        while(aux1 != NULL){
            if(!findElement(l2, aux1->dado))
                return 0;
            aux1 = aux1->prox;
        }
        return 1;
    }
    return 0;
}

int cont_element(Arvore *a, int elem){
    int cont = 0;
    if(a != NULL){
        if(a->dado == elem)
            cont++;
        if(a->esq != NULL)
            cont += cont_element(a->esq, elem);
        if(a->dir != NULL)
            cont += cont_element(a->dir, elem);
        return cont;
    }
    return -1;
}

int ablsFull(Arvore *a){
    int fd=1, fe=1;
    if(a != NULL){
        if(a->dir != NULL)
            fd = ablsFull(a->dir);
        if(a->esq != NULL)
            fe = ablsFull(a->esq);
        if((a->dir == NULL && a->esq == NULL || a->dir != NULL && a->esq != NULL) && fd && fe)
            return 1;
        else
            return 0;
    }
    return 0;
}

int abpNumNodesHeightH(Arvore *a, int h){
    int cont = 0, c_esq=0, c_dir=0;
    if(a != NULL){
        if(h == 0)
            return 1;
        if(a->dir != NULL)
            c_dir += abpNumNodesHeightH(a->dir, h-1);
        if(a->esq != NULL)
            c_esq += abpNumNodesHeightH(a->esq, h-1);
        return c_dir + c_esq;
    }
    return -1;
}

int espelhaArvore(Arvore *a){
    Arvore *aux1, *aux2;
    if(a != NULL){
        if(a->dir != NULL)
            espelhaArvore(a->dir);
        if(a->esq != NULL)
            espelhaArvore(a->esq);
        if(a->dir != NULL){
            aux1 = a->dir;
            if(a->esq != NULL){
                aux2 = a->esq;
                a->dir = aux2;
                a->esq = aux1;
            }else{
                a->esq = aux1;
                delete[] a->dir;
                a->dir = NULL;
            }
        }else{
            if(a->esq != NULL){
                aux1 = a->esq;
                if(a->dir != NULL){
                    aux2 = a->dir;
                    a->esq = aux2;
                    a->dir = aux1;
                }else{
                    a->dir = aux1;
                    delete[] a->esq;
                    a->esq = NULL;
                }
            }
        }
        return 1;
    }
    return 0;
}
