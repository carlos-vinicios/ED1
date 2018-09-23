#ifndef TESTES
#define TESTES

//----------------- PILHA 1 -------------------

//typedef int (*Comparar)(void *a, void *b); //para questão 15

typedef struct _Pilha_{
    void **dados;
    int topo;
    int qtd;
    int tam;
    //Comparar comp; //apenas para a questão 15
} Pilha;

Pilha *criar(int tam);

//Pilha *criar(int tam, Comparar c); //para a questão 15

void *topo(Pilha *p);

int push(Pilha *p, void *dado);

void *pop(Pilha *p);

int vazia(Pilha *p);

int destruir(Pilha *p);

int busca_e_remove(Pilha *p, void *v);

//-------------------- PILHA 2 (DUPLA) -------------
typedef struct _PilhaDupla_{
    void **dados;
    int topo1;
    int topo2;
    int qtd1;
    int qtd2;
    int tam1;
    int tam2;
} PilhaDupla;

Pilha *criarPilhaDupla(int tam);

void *topo1(Pilha *p);

int push1(Pilha *p, void *dado);

void *pop1(Pilha *p);

int vazia1(Pilha *p);

void *topo2(Pilha *p);

int push2(Pilha *p, void *dado);

void *pop2(Pilha *p);

int vazia2(Pilha *p);

//-------------------- FILA -------------
typedef struct _Fila_{
    int *dados;
    int inicio;
    int fim;
    int qtd;
    int tam;
} Fila;

Fila *criarFila(int tam);

int enfileirar(Fila q, void *chave);

void *desenfileirar(Fila q);

int removeElemento(Fila q, int x);

int pesqFila(Fila q, int x);

//-------------------------------- QUESTÃO 6 (A) ----------------------------
typedef struct _Deque_{
    void **dados;
    int inicio;
    int fim;
    int qtd;
    int tam;
} Deque;

Deque *criarDeque(int tam);

int enfileira_esq(Deque *d, void *v);

int enfileira_dir(Deque *d, void *v);

void *desenfileirar_esq(Deque *d);

void *desenfileirar_dir(Deque *d);

//-------------------------------- QUESTÃO 6 (B) ----------------------------

#endif // TESTES
