#include <stdio.h>
#include <stdlib.h>
#include "TAD_evento.h"

Evento *criaEvento(int qtd_max){
    Evento *evento = NULL;
    if(qtd_max > 0){
        evento = (Evento *) malloc( sizeof(Evento) );
        evento->entradas = NULL;
        if(evento == NULL)
            return evento;

        evento->entradas = (int *) malloc( qtd_max * sizeof(int));
        if(evento->entradas == NULL){
            free(evento);
            evento = NULL;
            return evento;
        }
        evento->qtd_entradas = 0;
        evento->qtd_max = qtd_max;
    }
    return evento;
}

int novaEntrada(Evento *evento, int id){
    int i;
    if(evento != NULL && evento->entradas != NULL && evento->qtd_entradas < evento->qtd_max){
        for(i = 0; i < evento->qtd_entradas; i++)
            if(evento->entradas[i] == id)
                return 0;

        evento->entradas[evento->qtd_entradas] = id;
        evento->qtd_entradas++;
        return 1;
    }
    return 0;
}

int procuraEntrada(Evento *evento, int chave){
    int i;
    if(evento != NULL && evento->entradas != NULL && evento->qtd_entradas > 0)
        for(i = 0; i < evento->qtd_entradas; i++)
            if(evento->entradas[i] == chave)
                return 1;

    return 0;
}

int removerEntrada(Evento *evento, int chave){
    int i;
    if(evento != NULL && evento->entradas != NULL && evento->qtd_entradas > 0)
        for(i = 0; i < evento->qtd_entradas; i++){
            if(evento->entradas[i] == chave){
                evento->entradas[i] = evento->entradas[evento->qtd_entradas - 1];
                evento->qtd_entradas--;
                return 1;
            }
        }

    return 0;
}

int destruitEvento(Evento **evento){
    if(*evento != NULL){
        free(*evento);
        *evento = NULL;
        if(*evento == NULL)
            return 1;
        else
            return 0;
    }
    return 0;
}
