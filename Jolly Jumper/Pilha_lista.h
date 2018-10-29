
typedef struct _Lista_{
    int dado;
    struct _Lista_ *prox;
} Lista;

typedef struct _Pilha_{
    Lista *dados;
    int qtd;
} Pilha;

Pilha *criarPilha();

int push(Pilha *p, int dado);

int pop(Pilha *p);
