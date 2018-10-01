#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fruta.h"

Fruta *new_fruta(int tam_cenario, int snk_lin, int snk_col){
    Fruta *fruta = NULL;
    int lin, col, exec=1;
    srand(time(NULL));

    do{
        lin = rand() % tam_cenario + 1;
        col = rand() % 3*tam_cenario + 1;
        if((col > 0 && col < 3*tam_cenario-1) && (lin > 0 && lin < tam_cenario-1)){
            if(col != snk_col && lin != snk_lin){
                fruta = new Fruta[1];
                if(fruta != NULL){
                    fruta->lin = lin;
                    fruta->col = col;
                }
                exec = 0;
            }
        }
    }while(exec);

    return fruta;
}

void draw_fruta(char **cenario, Fruta *fruta){
    cenario[fruta->lin][fruta->col] = '0';
}

int snake_eat(int lin, int col, Fruta *fruta){
    if(lin == fruta->lin && col == fruta->col)
        return 1;
    else
        return 0;
}
