
typedef struct _node_{
    int dado;
    _node_ *prox;
} Node;

typedef struct _lista_{
    Node *cab;
    Node *ult;
    int qtd;
} Lista;

Node *criarNode(int value);

Lista *criarLista();

int push(Lista *l, int value);

int findElement(Lista *l, int key);
