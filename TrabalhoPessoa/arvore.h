typedef struct _pessoa_{
    int matricula;
    char *nome;
    int date_in;
    int date_out;
} Pessoa;

typedef struct _ar_nome_{
    Pessoa *pessoa;
    _ar_nome_ *dir;
    _ar_nome_ *esq;
} ArvoreNome;

typedef struct _ar_date_in_{
    Pessoa *pessoa;
    _ar_date_in_ *dir;
    _ar_date_in_ *esq;
} ArvoreDataEntrada;

typedef struct _ar_date_out_{
    Pessoa *pessoa;
    _ar_date_out_ *dir;
    _ar_date_out_ *esq;
} ArvoreDataSaida;

typedef struct _lista_pessoa_{
    Pessoa *pessoa;
    int qtd;
    _lista_pessoa_ *prox;
} Lista;

Pessoa *cadastrarPessoa(int matricula, char *nome, int dataEntrada, int dataSaida);

int editarPessoa(Pessoa *p, char *nome, int dataEntrada, int dataSaida);

ArvoreNome *criarArvoreNome(Pessoa *p);

int inserirArvoreNome(ArvoreNome *an, Pessoa *p);

Lista *buscarArvoreNome(ArvoreNome *an, char *nome);

ArvoreDataEntrada *criarArvoreDataEntrada(Pessoa *p);

int inserirArvoreDataEntrada(ArvoreDataEntrada *ade, Pessoa *p);

Lista *buscarArvoreArvoreDataEntrada(ArvoreDataEntrada *ade, int data);

ArvoreDataSaida *criarArvoreDataSaida(Pessoa *p);

int inserirArvoreDataSaida(ArvoreDataSaida *ads, Pessoa *p);

Lista *buscarArvoreDataSaida(ArvoreDataSaida *ads, int data);

Lista *criarNoLista(Pessoa *p);

int acrescentar(Lista *l, Pessoa *p);

int destruirLista(Lista *l);
