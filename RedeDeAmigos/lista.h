
typedef struct _amigo_{
    int chave;
    _amigo_ *prox;
} Amigo;

typedef struct _amigos_{
    Amigo *ini;
    Amigo *ult;
} Amigos;

typedef struct _pessoa_{
    int id;
    _pessoa_ *prox;
    Amigos *amigos;
} Pessoa;

typedef struct _Rede_{
    Pessoa *cab;
    Pessoa *ult;
} Rede;

Pessoa *criarPessoa(int chave);

Rede *criarRede();

Amigo *criarAmigo(int chave);

Amigos *criarLista();

int novaPessoa(Rede *r, int chave);

int adicionarAmigo(Rede *r, int chave1, int chave2);

int adicionarNovoAmigo(Amigos *a, int chave);

int buscarListaAmigo(Amigos *a, int chave);

void listarAmigos(Rede *r, int chave);
