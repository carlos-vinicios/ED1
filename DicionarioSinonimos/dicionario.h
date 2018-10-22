
typedef struct _palavra_{
    char *sintaxe;
    _palavra_ *sinonimo;
    _palavra_ *prox;
} Palavra;

typedef struct _dicionario_{
    Palavra *cab;
    Palavra *ult;
} Dicionario;

Dicionario *criarDicionario();

Palavra *criarPalavra(char *sintaxe);

int add(Dicionario *d, char *palavra);

int addSinonimo(Dicionario *d, char *palavra, char *sinonimo);

Palavra *buscaPalavra(Dicionario *d, char *palavra);
