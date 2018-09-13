#include <stdio.h>
#include <stdlib.h>
#include "TAD_imagem.h"

int **createPixel(int r, int g, int b){
    int **pixel = NULL;

    if(r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255){
        pixel = (int **) malloc(sizeof(int *));
        *pixel = (int *) malloc(3 * sizeof(int));

        pixel[0] = r;
        pixel[1] = g;
        pixel[2] = b;
    }

    return pixel;
}

void readPixel(void *pixel){
    int **px = (int **) pixel;
    printf("Vermelho: %d\nVerde: %d\nAzul: %d\n", px[0], px[1], px[2]);
}

int main()
{
    Imagem *img = construir(6, 6);

    if(img != NULL)
        printf("Setou\n");

    if(setPixel(img, 0, 0, (void *) createPixel(123, 100, 90)))
        printf("Colocou o pixel\n");

    readPixel(getPixel(img, 0, 0));

    return 0;
}
