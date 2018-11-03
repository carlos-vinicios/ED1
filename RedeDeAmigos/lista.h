typedef struct _pessoa_{
    int id;
    _pessoa_ *prox;
    _pessoa_ *amigos;
} Pessoa;

typedef struct _Rede_{
    Pessoa *cab;
    Pessoa *ult;
} Rede;

Pessoa *novaPessoa(int chave);

Rede *criarRede();

int adicionarAmigo(int chave1, int chave2);

int adicionarPessoa(Rede *r, int chave);
