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
    if(res){
        printf("Erro na nova entrada\n");
        return 0;
    }
    res = novaEntrada(evento, 6587);
    if(res){
        printf("Erro na nova entrada\n");
        return 0;
    }
    res = novaEntrada(evento, 5712);
    if(res){
        printf("Erro na nova entrada\n");
        return 0;
    }
    res = novaEntrada(evento, 5421);
    if(res){
        printf("Erro na nova entrada\n");
        return 0;
    }
    res = novaEntrada(evento, 8794);
    if(res){
        printf("Erro na nova entrada\n");
        return 0;
    }
    res = novaEntrada(evento, 7234);
    if(res){
        printf("Erro na nova entrada\n");
        return 0;
    }
    res = novaEntrada(evento, 7932);
    if(res){
        printf("Erro na nova entrada\n");
        return 0;
    }
    res = novaEntrada(evento, 9312);
    if(res){
        printf("Erro na nova entrada\n");
        return 0;
    }

    for(int i = 0; i < evento->qtd_entradas; i++)
        printf("Entrada %d: %d\n", i + 1, evento->entradas[i]);

    return 0;
}
