#ifndef FRUTA
#define FRUTA

typedef struct _Fruta_{
    int lin;
    int col;
}Fruta;

Fruta *new_fruta(int tam_cenario, int snk_lin, int snk_col);

void draw_fruta(char **cenario, Fruta *fruta);

int snake_eat(int lin, int col, Fruta *fruta);

#endif // FRUTA
