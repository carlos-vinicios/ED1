#include <stdio.h>
#include <stdlib.h>
#include "TAD_generico.h"

Sequencia *criar(int qtd_max, Comparar c){
    Sequencia *ret = NULL;
    ret = (Sequencia *) malloc(sizeof(Sequencia));
    if(ret != NULL){
        ret->dados = (void **) malloc(qtd_max * sizeof(void *)); //ver essa alocação aqui
        if(ret->dados != NULL){
            ret->qtd = 0;
            ret->qtd_max = qtd_max;
            ret->comp = c;
        }else{
            free(ret);
            ret = NULL;
        }
    }

    return ret;
}

int inserir(Sequencia *seq, void *chave){
    if((seq == NULL) || (seq->dados == NULL) || (seq->qtd >= seq->qtd_max)){
        return 0;
    }else{
        seq->dados[seq->qtd] = chave;
        seq->qtd++;
    }

    return 1;
}

int buscar(Sequencia *seq, void *chave){
    if((seq == NULL) || (seq->dados == NULL) || (seq->qtd == 0))
        return -1;

    int i;
    for(i = 0; i < seq->qtd; i++)
        if(seq->comp(seq->dados[i], chave))
            return i;

    return -1;
}
