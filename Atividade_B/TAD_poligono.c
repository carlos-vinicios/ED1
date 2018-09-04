#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD_poligono.h"

Poligono *criarPoligono(int qtd_lados){
    Poligono *pol = NULL;
    if(qtd_lados > 0){
        pol = (Poligono *) malloc(sizeof(Poligono)); //aloca espaço na memoria para a estrutura
        if(pol != NULL){ //caso a estrutura tenha sido alocada corretamente
            pol->ponto = (Ponto *) malloc( qtd_lados * sizeof(Ponto));
            if(pol->ponto != NULL){  //caso tenha sido alocado corretamente
                pol->qtd_lados = qtd_lados;
                pol->qtd_registrados = 0;
            }else{ //se não alocou corretamente, limpa a estrutura da memoria
                free(pol);
                pol = NULL;
            }
        }
    }
    return pol;
}

int inserirCoordenadas(Poligono *pol, float x, float y){
    int i;
    if(pol != NULL && pol->qtd_registrados < pol->qtd_lados){ //verifica se o poligono e uma sequencia valida e verifica se ainda pode inserir coordenadas
        pol->ponto[pol->qtd_registrados].x = x;
        pol->ponto[pol->qtd_registrados].y = y;
        pol->qtd_registrados++;
        return 1;
    }
    return 0;
}

int imprimirPoligono(Poligono *pol){
    int i;
    if(pol != NULL && pol->qtd_registrados == pol->qtd_lados){ //verifica se e uma estrutura váilida, depois imprime com printf
        for(i = 0; i < pol->qtd_lados; i++){
            printf("Coordenada %d: (%.2f, %.2f)\n", i + 1, pol->ponto[i].x, pol->ponto[i].y);
        }
        return 1;
    }
    return 0;
}

float *tamLadosPoligono(Poligono *pol){
    int i;
    float *lados = NULL;
    lados = (float *) malloc(pol->qtd_lados * sizeof(float)); //aloca um vetor para armazenar a medida dos lados do poligono
    if(pol != NULL && lados != NULL && pol->qtd_registrados == pol->qtd_lados){
        for(i = 0; i < pol->qtd_lados; i++){ //caso a Estrutura e o vetor estejam alocados corretamentes, realiza o calculo de tamanho dos lados, assim como, todas as suas coordenadas preenchidas
            if(i != (pol->qtd_lados - 1))
                lados[i] = sqrt(pow((pol->ponto[i + 1].x - pol->ponto[i].x), 2) + pow((pol->ponto[i + 1].y - pol->ponto[i].y), 2));
            else
                lados[i] = sqrt(pow((pol->ponto[0].x - pol->ponto[i].x), 2) + pow((pol->ponto[0].y - pol->ponto[i].y), 2));
        }
        return lados;
    }
    return 0;
}

float perimetroPoligono(Poligono *pol){
    int i;
    float perimetro = 0;
    if(pol != NULL && pol->qtd_registrados == pol->qtd_lados){ //verifica se a estrutura e valida
        for(i = 0; i < pol->qtd_lados; i++){ //caso a Estrutura e o vetor estejam alocados corretamentes, realiza o calculo de tamanho dos lados, assim como, todas as suas coordenadas preenchidas
            if(i != (pol->qtd_lados - 1))
                perimetro += sqrt(pow((pol->ponto[i + 1].x - pol->ponto[i].x), 2) + pow((pol->ponto[i + 1].y - pol->ponto[i].y), 2));
            else
                perimetro += sqrt(pow((pol->ponto[0].x - pol->ponto[i].x), 2) + pow((pol->ponto[0].y - pol->ponto[i].y), 2));

        }
        if(perimetro > 0) //se o perimetro for maior que 0, significa que não ocorreram erros
            return perimetro;
    }
    return 0;
}

int destruirPoligono(Poligono **pol){
    if(*pol != NULL){ //verifica se uma estrutura valida
        free(*pol); //libera o espaço da memoria
        *pol = NULL;
        if(*pol != NULL) //verifica se limpou o vetor
            return 0;

        return 1;
    }
    return 0;
}
