#include <stdio.h>
#include <stdlib.h>
#include "TAD_evento.h"

Evento *criaEvento(int qtd_max){
    Evento *evento = NULL;
    if(qtd_max > 0){ //a quantidade maxima deve ser maior que 0 elementos
        evento = (Evento *) malloc( sizeof(Evento) ); //aloca espaço para o vetor de participantes
        if(evento != NULL){ //se a estrutura do evento for alocada com sucesso
            evento->entradas = (int *) malloc( qtd_max * sizeof(int));//aloca o vetor de participantes
            if(evento->entradas == NULL){//caso não aloque corretamentes limpa a memoria alocada e atribui null ao evento
                free(evento);
                evento = NULL;
            }
        }
        evento->qtd_entradas = 0; //inicia com 0 participantes
        evento->qtd_max = qtd_max; //define a quantidade maxima de participantes
    }
    return evento;
}

int novaEntrada(Evento *evento, int chave){
    int i;
    if(evento != NULL && evento->entradas != NULL && evento->qtd_entradas < evento->qtd_max){ //faz os testes basicos para a existencia da estrutura, do vetor de participantes e da quantidade presente
        for(i = 0; i < evento->qtd_entradas; i++) //a chave (ID) deve ser única para cada participante, assim, procura se já existe uma chave igual no vetor
            if(evento->entradas[i] == chave)
                return 0;

        evento->entradas[evento->qtd_entradas] = chave; //salva a chave (ID) e incrementa a quantidade de entradas
        evento->qtd_entradas++;
        return 1;
    }
    return 0;
}

int procuraEntrada(Evento *evento, int chave){
    int i;
    if(evento != NULL && evento->entradas != NULL && evento->qtd_entradas > 0) //faz o teste da estrutura, vetor e quantidade de entradas
        for(i = 0; i < evento->qtd_entradas; i++) //procura a chave dentro do vetor
            if(evento->entradas[i] == chave)
                return 1;

    return 0;
}

int removerEntrada(Evento *evento, int chave){
    int i;
    if(evento != NULL && evento->entradas != NULL && evento->qtd_entradas > 0) //faz o teste da estrutura, vetor e quantidade de entradas
        for(i = 0; i < evento->qtd_entradas; i++){ //percorre o vetor procurando todas as entradas correspondentes e removendo-as da sequencia
            if(evento->entradas[i] == chave){
                evento->entradas[i] = evento->entradas[evento->qtd_entradas - 1];
                evento->qtd_entradas--;
                return 1;
            }
        }

    return 0;
}

int destruitEvento(Evento **evento){
    if(*evento != NULL){ //verifica se a estrutura é válida
        free(*evento); //limpa a memória
        *evento = NULL;
        if(*evento == NULL) //caso a mesma fique nula, destruiu com sucesso, caso contrario erro na destruiçao
            return 1;
    }
    return 0;
}
