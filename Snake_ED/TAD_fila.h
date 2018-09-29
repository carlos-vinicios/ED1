#ifndef TAD_fila
#define TAD_fila

typedef struct _fila_{
    char *dados;
    int inicio;
    int fim;
    int qtd;
    int tam;
} Fila;

Fila *criarFila(int tam);

int adicionar(Fila *f, char chave);

char remover(Fila *f);

int destruirFila(Fila *f);

int filaVazia(Fila *f);

#endif
