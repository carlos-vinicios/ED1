#include <stdio.h>
#include <stdlib.h>
#include "TAD_poligono.h"

int main()
{
    Poligono *pol = NULL;
    float x, y, perimetro, *lados;
    int i, res;

    pol = criarPoligono(4);

    if(pol == NULL)
        return 0;

    for(i = 0; i < pol->qtd_lados; i++){
        printf("Digite a %d º coordenada: (x, y)\n", i+1);
        scanf("%f", &x);
        scanf("%f", &y);
        res = inserirCoordenadas(pol, x, y);
        if(!res)
            printf("Erro na inserção das coordenadas\n");

    }

    perimetro = perimetroPoligono(pol);
    if(perimetro != 0)
        printf("O perimetro é: %.2f\n", perimetro);
    else
        printf("As coordenadas não são validas\n");

    lados = tamLadosPoligono(pol);
    for(i = 0; i < pol->qtd_lados; i++)
        printf("Tamanho lado %d: %.2f\n", i+1, lados[i]);

    res = imprimirPoligono(pol);
    if(!res)
        printf("Erro na exibição das coordenadas\n");

    res = destruirPoligono(&pol);

    if(pol != NULL)
        printf("Erro na exclusão do poligono\n");
    else
        printf("Exclusão realizada com sucesso\n");

    return 0;
}
