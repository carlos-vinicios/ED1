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
    _lista_pessoa_ *prox;
} Lista;

Pessoa *cadastrarPessoa(int matricula, char *nome, int dataEntrada, int dataSaida);

int editarPessoa(Pessoa *p, char *nome, int dataEntrada, int dataSaida);

ArvoreNome *criarArvoreNome(Pessoa *p);

int inserirArvoreNome(ArvoreNome *an, Pessoa *p);

Lista *buscarArvoreNome(ArvoreNome *an, char *nome);

ArvoreNome *buscarFolhaArvoreNome(ArvoreNome *an, char *nome);

int removerArvoreNome(ArvoreNome *an, Pessoa *p);

ArvoreNome *maiorArvoreNome(ArvoreNome *an);

ArvoreDataEntrada *criarArvoreDataEntrada(Pessoa *p);

int inserirArvoreDataEntrada(ArvoreDataEntrada *ade, Pessoa *p);

Lista *buscarArvoreDataEntrada(ArvoreDataEntrada *ade, int data);

ArvoreDataEntrada *buscarFolhaArvoreDataEntrada(ArvoreDataEntrada *ade, int data);

int removerArvoreDataEntrada(ArvoreDataEntrada *ade, Pessoa *p);

ArvoreDataEntrada *maiorArvoreDataEntrada(ArvoreDataEntrada *ade);

ArvoreDataSaida *criarArvoreDataSaida(Pessoa *p);

int inserirArvoreDataSaida(ArvoreDataSaida *ads, Pessoa *p);

Lista *buscarArvoreDataSaida(ArvoreDataSaida *ads, int data);

ArvoreDataSaida *buscarFolhaArvoreDataSaida(ArvoreDataSaida *ads, int data);

int removerArvoreDataSaida(ArvoreDataSaida *ads, Pessoa *p);

ArvoreDataSaida *maiorArvoreDataSaida(ArvoreDataSaida *ads);

Lista *criarNoLista(Pessoa *p);

int acrescentar(Lista *l, Pessoa *p);

int destruirLista(Lista *l);
