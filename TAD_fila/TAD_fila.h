#ifndef TAD_fila
#define TAD_fila

typedef struct _Fila_{
    void **dados;
    int inicio;
    int fim;
    int qtd;
    int qtd_max;
} Fila;

Fila *criar(int qtd_max);

int enfileirar(Fila *fila, void *dado);

void *desenfileirar(Fila *fila);

int vazia(Fila *fila);

#endif // TAD_fila
