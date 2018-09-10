
typedef int (*Comparar)(void *a, void *b);

typedef struct _seq_ {
    void **dados;
    int qtd;
    int qtd_max;
    Comparar comp;
} Sequencia;

Sequencia *criar(int qtd_max, Comparar c);

int buscar(Sequencia *seq, void *chave);

int inserir(Sequencia *seq, void *chave);
