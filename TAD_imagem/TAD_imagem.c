#include <stdlib.h>
#include "TAD_imagem.h"

Imagem *construir(int altura_max, int largura_max){
    Imagem *img = NULL;
    if(altura_max > 0 && largura_max > 0){
        img = (Imagem *) malloc(sizeof(Imagem));
        if(img != NULL){
            img->pixels = (void **) malloc(altura_max * largura_max * sizeof(void *));
            if(img->pixels != NULL){
                img->qtd_pixels = 0;
                img->altura = altura_max;
                img->largura = largura_max;
            }else{
                free(img);
                img = NULL;
            }
        }
    }

    return img;
}

int setPixel(Imagem *img, int x, int y, void *px){
    if(img != NULL && img->pixels != NULL && x >= 0 && y >= 0 && img->qtd_pixels < (img->altura * img->largura)){
        img->pixels[x * img->largura + y] = px;
        img->qtd_pixels++;
        return 1;
    }

    return 0;
}

void *getPixel(Imagem *img, int x, int y){
    void *pixel = NULL;
    if(img != NULL && img->pixels != NULL && x >= 0 && y >= 0 && img->qtd_pixels > 0)
        pixel = img->pixels[x * img->largura + y];

    return pixel;
}

Imagem *getRect(Imagem *img, int x, int y, int largura, int comprimento){
    Imagem *newImg = NULL;
    int i, j;

    if(img != NULL && img->pixels != NULL && x >= 0 && y >= 0 && img->qtd_pixels > 0 && comprimento <= img->altura && largura <= img->largura){
        newImg = (Imagem *) malloc(sizeof(Imagem));
        if(newImg != NULL){
            newImg->pixels = (void **) malloc(comprimento * largura * sizeof(void *));
            if(newImg->pixels != NULL){
                newImg->qtd_pixels = 0;
                for(i = x; i < img->altura; i++)
                    for(j = y; j < img->largura; j++){
                        newImg->pixels[newImg->qtd_pixels] = img->pixels[i*largura+j];
                        newImg->qtd_pixels++;
                    }

                newImg->altura = comprimento;
                newImg->largura = largura;
            }else{
                free(newImg);
                newImg = NULL;
            }
        }
    }

    return newImg;
}
