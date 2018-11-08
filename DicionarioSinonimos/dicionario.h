
typedef struct _palavra_{
    char *sintaxe;
    int qtd;
    _palavra_ *sinonimo;
    _palavra_ *prox;
} Palavra;

typedef struct _dicionario_{
    Palavra *cab;
    Palavra *ult;
} Dicionario;

Dicionario *criarDicionario();

Palavra *criarPalavra(char *sintaxe);

Palavra *addPalavra(Dicionario *d, char *palavra);

int addSinonimo(Dicionario *d, char *palavra, char *sinonimo);

Palavra *buscarPalavra(Dicionario *d, char *palavra);

Palavra *substituirPalavra(Dicionario *d, char *palavra);

char *formalizarTexto(Dicionario *d, char *paragrafo);
