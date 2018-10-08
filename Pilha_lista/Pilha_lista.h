
typedef struct _Lista_{
    void *dado;
    struct _Lista_ *prox;
} Lista;

typedef struct _Pilha_{
    Lista *dados;
    int qtd;
} Pilha;

Pilha *criarPilha();

int push(Pilha *p, void *dado);

void *pop(Pilha *p);
