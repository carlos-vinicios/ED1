#include <stdlib.h>
#include "TAD_fila.h"
#include "TAD_pilha.h"
#include "snake.h"

/*Para setar o tamanho máximo que a snake terá, será passado o tamanho do cenário*/
Fila *set_snake(int tam){
    Fila *snake;
    int i;
    snake = criarFila(tam);
    for(i=0;i<3;i++)
        adicionar(snake, '*');
    return snake;
}

void draw_snake(Fila *snake, char **cenario, int linha, int col, int orientacao, int direcao, int tam_cenario){
    Fila *f_aux = criarFila(snake->qtd);
    char aux;
    if(cenario != NULL){
        if(orientacao == 180){
            if(direcao > 0){
                while(!filaVazia(snake)){
                    aux = remover(snake);
                    if(col > 0)
                        cenario[linha][col] = aux;
                    adicionar(f_aux, aux);
                    col--;
                }
            }else{
                while(!filaVazia(snake)){
                    aux = remover(snake);
                    if(col < 3*tam_cenario-1)
                        cenario[linha][col] = aux;
                    adicionar(f_aux, aux);
                    col++;
                }
            }
        }else{
            if(direcao > 0){
                while(!filaVazia(snake)){
                    aux = remover(snake);
                    if(linha > 0)
                        cenario[linha][col] = aux;
                    adicionar(f_aux, aux);
                    linha--;
                }
            }else{
                while(!filaVazia(snake)){
                    aux = remover(snake);
                    if(linha < tam_cenario-1)
                        cenario[linha][col] = aux;
                    adicionar(f_aux, aux);
                    linha++;
                }
            }
        }
        while(!filaVazia(f_aux)){
            adicionar(snake, remover(f_aux));
        }
        destruirFila(f_aux);
    }
}

void move_snake(int direcao, int orientacao, int *linha, int *coluna){
    if(orientacao == 180){
        if(direcao > 0){ //direta
            (*coluna)++;
        }else{ //esquerda
            (*coluna)--;
        }
    }else{ //== 90
        if(direcao > 0){ //cima
            (*linha)++;
        }else{ //baixo
            (*linha)--;
        }
    }
}

/*A primeira linha e coluna, assim como, a última linha e coluna são as paredes do cenário */
int hit_wall(int linha, int coluna, int tam_cenario){
    if(linha == 0 || linha == tam_cenario-1)
        return 1;
    if(coluna == 0 || coluna == 3*tam_cenario-1 )
        return 1;

    return 0;
}

void lose_life(Fila *snake){
    remover(snake);
}

void eat_fruit(Fila *snake){
    int i;
    Pilha *p = criarPilha(snake->tam);
    empilhar(p, '*');
    for(i = 0; i < 2; i++){
        while(!filaVazia(snake)){
            empilhar(p, remover(snake));
        }
        while(!pilhaVazia(p)){
            adicionar(snake, desempilhar(p));
        }
    }
    destruirPilha(p);
}

int snake_die(Fila *snake){
    if(snake->qtd < 5)
        return 1;
    else
        return 0;
}
