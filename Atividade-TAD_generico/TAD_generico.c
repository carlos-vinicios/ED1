#include <stdlib.h>
#include "TAD_generico.h"

Sequencia *criar(int qtd_max, Comparar c){
    Sequencia *seq = NULL;
    if(qtd_max > 0){
        seq = (Sequencia *) malloc(sizeof(Sequencia));
        if(seq != NULL){
            seq->dados = (void **) malloc(qtd_max * sizeof(void *));
            if(seq->dados != NULL){
                seq->qtd = 0;
                seq->qtd_max = qtd_max;
                seq->comp = c;
            }else{
                free(seq);
                seq = NULL;
            }
        }
    }

    return seq;
}

int inserir(Sequencia *seq, void *chave){
    if(seq != NULL && seq->qtd < seq->qtd_max && seq->dados != NULL){
        seq->dados[seq->qtd] = chave;
        seq->qtd++;
        return 1;
    }

    return 0;
}

int inserirNull(Sequencia *seq, void *chave){
    int i;
    if(seq != NULL && seq->dados != NULL && seq->qtd == seq->qtd_max){
        for(i = 0; i < seq->qtd; i++)
            if(seq->dados[i] == NULL)
                seq->dados[i] = chave;

        return 1;
    }

    return 0;
}

int inserirOrdenado(Sequencia *seq, void *chave){
    int i, j;
    if(seq != NULL && seq->dados != NULL && seq->qtd < seq->qtd_max){
        for(i = 0; i < seq->qtd; i++)
            if(seq->comp(seq->dados[i], chave) > 0){
                for(j = seq->qtd; j > i; j--)
                    seq->dados[j] = seq->dados[j-1];

                seq->dados[i] = chave;
                seq->qtd++;
                return 1;
            }

        seq->dados[seq->qtd] = chave;
        seq->qtd++;
        return 1;
    }

    return 0;
}

int buscar(Sequencia *seq, void *chave){
    int i;

    if(seq != NULL && seq->dados != NULL && seq->qtd > 0){
        for(i = 0; i < seq->qtd; i++)
            if(seq->comp(seq->dados[i], chave) == 0)
                return 1;
    }

    return 0;
}

int buscaIgnoreNull(Sequencia *seq, void *chave){
    int i;

    if(seq != NULL && seq->dados != NULL && seq->qtd > 0){
        for(i = 0; i < seq->qtd; i++)
            if(seq->dados[i] != NULL)
                if(seq->comp(seq->dados[i], chave) == 0)
                    return 1;
    }

    return 0;
}

int remover(Sequencia *seq, void *chave){
    int i;

    if(seq != NULL && seq->dados != NULL && seq->qtd > 0){
        for(i = 0; i < seq->qtd; i++)
            if(seq->comp(seq->dados[i], chave) == 0){
                seq->dados[i] = seq->dados[seq->qtd - 1];
                seq->qtd--;
            }//else{
                //i++;
            //}

        return 1;
    }

    return 0;
}

int setNull(Sequencia *seq, void *chave){
    int i;

    if(seq != NULL && seq->dados != NULL && seq->qtd > 0)
        for(i = 0; i < seq->qtd; i++)
            if(seq->comp(seq->dados[i], chave) == 0){
                seq->dados[i] = NULL;
                return 1;
            }

    return 0;
}

int destruir(Sequencia *seq){
    if(seq != NULL){
        free(seq);
        seq = NULL;
        if(seq == NULL)
            return 1;
    }

    return 0;
}
