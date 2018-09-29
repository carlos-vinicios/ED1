#ifndef Snake
#define Snake

Fila *set_snake(int tam);

int draw_snake(Fila *snake, char **cenario, int linha, int coluna, int orientacao, int direcao);

void move_snake(int direcao, int orientacao, int *linha, int *coluna);

int hit_wall(int linha, int coluna, int tam_cenario);

void lose_life(Fila *snake);

void eat_fruit(Fila *snake);

int snake_die(Fila *snake);

#endif
