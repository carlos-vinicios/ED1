
typedef struct _lista_dupla_{
    int dado;
    _lista_dupla_ *prox;
    _lista_dupla_ *ant;
} ListaDupla;

typedef struct _listaL{
    ListaDupla *cab;
    ListaDupla *rabo;
} Lista;

ListaDupla *criarNo(int valor);

Lista *criarLista();

void adicionar(Lista *l, int valor);

int remover(Lista *l, int dado);

ListaDupla *buscar(Lista *l, int dado);
