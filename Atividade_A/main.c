#include <stdio.h>
#include <stdlib.h>
#include "TAD_evento.h"

int main()
{
    Evento *evento;
    int res;

    evento = criaEvento(10);

    if(evento == NULL){
        printf("Erro na criacao do evento\n");
        return 0;
    }

    res = novaEntrada(evento, 1234);
    if(!res){
        printf("Erro na nova entrada\n");
    }
    res = novaEntrada(evento, 9878);
    if(!res){
        printf("Erro na nova entrada\n");
    }
    res = novaEntrada(evento, 5712);
    if(!res){
        printf("Erro na nova entrada\n");
    }
    res = novaEntrada(evento, 5421);
    if(!res){
        printf("Erro na nova entrada\n");
    }
    res = novaEntrada(evento, 8794);
    if(!res){
        printf("Erro na nova entrada\n");
    }
    res = novaEntrada(evento, 7234);
    if(!res){
        printf("Erro na nova entrada\n");
    }
    res = novaEntrada(evento, 7932);
    if(!res){
        printf("Erro na nova entrada\n");
    }
    res = novaEntrada(evento, 9312);
    if(!res){
        printf("Erro na nova entrada\n");
    }
    res = novaEntrada(evento, 4734);
    if(!res){
        printf("Erro na nova entrada\n");
    }

    res = removerEntrada(evento, 4734);
    if(!res){
        printf("Erro na remoção de entrada\n");
    }

    for(int i = 0; i < evento->qtd_entradas; i++)
        printf("Entrada %d: %d\n", i + 1, evento->entradas[i]);

    res = destruitEvento(&evento);
    if(res)
        printf("Exclusão com sucesso\n");
    else
        printf("Erro na exclusão\n");

    return 0;
}
