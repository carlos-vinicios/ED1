
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

int pushAfter(Lista *l, int index, int value);

int findElement(Lista *l, int key);

Lista *concat(Lista *l1, Lista *l2);

Lista *concatOrder(Lista *l1, Lista *l2);

int clean(Lista *l);

Lista *invert(Lista *l);

int removeLast(Lista *l);

int removeAt(Lista *l, int index);

Lista *uni(Lista *l1, Lista *l2);

Lista *intersec(Lista *l1, Lista *l2);

int removeSecond(Lista *l);

Lista *order(Lista *l);

int sum(Lista *l);

int qtdLista(Lista *l);

Lista *sendTo(Lista *l, int index1, int index2);

Lista *clone(Lista *l);
