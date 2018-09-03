#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD_poligono.h"

Poligono *criarPoligono(int qtd_lados){
    Poligono *pol = NULL;
    if(qtd_lados > 0){
        pol = (Poligono *) malloc(sizeof(Poligono));
        if(pol != NULL){
            pol->x = (float *) malloc(qtd_lados * sizeof(float));
            pol->y = (float *) malloc(qtd_lados * sizeof(float));
            if(pol->x != NULL && pol->y != NULL){
                pol->qtd_lados = qtd_lados;
            }else{
                free(pol);
                pol = NULL;
            }
        }
    }
    return pol;
}

int inserirCoordenadas(Poligono *pol, float *x, float *y){
    int i;
    if(pol != NULL){
        if(x[pol->qtd_lados - 1 ] != NULL && y[pol->qtd_lados - 1 ] != NULL){
            for(i = 0; i < pol->qtd_lados; i++){
                pol->x[i] = x[i];
                pol->y[i] = y[i];
            }
            return 1;
        }
    }
    return 0;
}

int imprimirPoligono(Poligono *pol){
    int i;
    if(pol != NULL){
        for(i = 0; i < pol->qtd_lados; i++){
            printf("Coordenada %d: (%.2f, %.2f)\n", i + 1, pol->x[i], pol->y[i]);
        }
        return 1;
    }
    return 0;
}

float *tamLadosPoligono(Poligono *pol){
    int i;
    float *lados = NULL;
    lados = (float *) malloc(pol->qtd_lados * sizeof(float));
    if(pol != NULL && lados != NULL){
        for(i = 0; i < pol->qtd_lados; i++){
            if(i != (qtd_lados - 1))
                lados[i] = sqrt(pow((pol->x[i + 1] - pol->x[i]), 2) + pow((pol->y[i + 1] - pol->y[i]), 2));
            else
                lados[i] = sqrt(pow((pol->x[0] - pol->x[i]), 2) + pow((pol->y[0] - pol->y[i]), 2));
        }
        return lados;
    }
    return 0;
}

float perimetroPoligono(Poligono *pol){
    int i;
    float perimetro = 0;
    if(pol != NULL){
        for(i = 0; i < pol->qtd_lados; i++){
            if(i != (qtd_lados - 1))
                lados += sqrt(pow((pol->x[i + 1] - pol->x[i]), 2) + pow((pol->y[i + 1] - pol->y[i]), 2));
            else
                lados += sqrt(pow((pol->x[0] - pol->x[i]), 2) + pow((pol->y[0] - pol->y[i]), 2));
        }
        if(lados > 0)
            return lados;
    }
    return 0;
}

int destruirPoligono(Poligono **pol){
    if(*pol != NULL){
        free(*pol);
        *pol = NULL;
        if(*pol != NULL)
            return 0;

        return 1;
    }
    return 0;
}
