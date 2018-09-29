#ifndef TAD_pilha
#define TAD_pilha

typedef struct _pilha_{
    char *dados;
    int topo;
    int qtd;
    int tam;
} Pilha;

Pilha *criarPilha(int tam);

int empilhar(Pilha *p, char chave);

char desempilhar(Pilha *p);

int destruirPilha(Pilha *p);

int pilhaVazia(Pilha *p);

#endif
