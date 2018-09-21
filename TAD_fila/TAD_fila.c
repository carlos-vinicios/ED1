#include <stdlib.h>
#include "TAD_fila.h"

Fila *criar(int qtd_max){
    Fila *fila = NULL;

    if(qtd_max > 0){ //a quantidade maxima precisa ser maior que 0
        fila = (Fila *) malloc(sizeof(Fila)); //aloca a fila na memória
        if(fila != NULL){ //verifica se alocou a fila
            fila->dados = (void **) malloc(qtd_max * sizeof(void *)); //aloca o vetor de dados na memória
            if(fila->dados != NULL){ //verifa o vetor de dados
                fila->inicio = 0;
                fila->fim = 0;
                fila->qtd = 0;
                fila->qtd_max = qtd_max; //define os valores iniciais da fila
            }else{ //caso o vetor de dados não tenha sido alocado corretamente, limpa a fila da memória e define a mesma NULL
                free(fila);
                fila = NULL;
            }
        }
    }

    return fila;
}

int enfileirar(Fila *fila, void *dado){
    if(fila != NULL && fila->dados != NULL && fila->qtd < fila->qtd_max){ //verifica se a fila e vetor de dados estão na memória. Verifica se o vetor ainda possui espaços vazios
        if(fila->fim == fila->qtd_max) //se a posição do fim da fila, equivaler ao seu tamanho máximo, retornando o seu valor para 0, caso verdadeiro
            fila->fim = fila->fim % fila->qtd_max;

        fila->dados[fila->fim] = dado; //realiza a inserção do dado no vetor
        fila->qtd++;
        fila->fim++;
        return 1;
    }

    return 0;
}

void *desenfileirar(Fila *fila){
    void *aux = NULL; //cria uma variável auxiliar para controle
    if(fila != NULL && fila->dados != NULL && fila->qtd > 0){//verifica se a fila e o vetor de dados estão alocados na memória, e se existe algum elemento
        if(fila->inicio == fila->qtd_max)
            fila->inicio = fila->inicio % fila->qtd_max;

        aux = fila->dados[fila->inicio]; //realiza a chamada do elemento seguinte da fila
        fila->inicio++;
        fila->qtd--;
    }

    return aux;
}

int vazia(Fila *fila){ //verifica se a fila está vázia
    if(fila != NULL && fila->dados != NULL && fila->qtd > 0)
        return 0;
    else
        return 1;
}
