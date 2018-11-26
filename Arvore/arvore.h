typedef struct _arvore_{
    int dado;
    struct _arvore_ *pai;
    struct _arvore_ *esq;
    struct _arvore_ *dir;
} Arvore;

Arvore *criar(int dado);

int inserir(Arvore *a, int dado);

Arvore *buscar(Arvore *a, int dado);

Arvore *sucessor(Arvore *a);

Arvore *maior(Arvore *a);

int remover(Arvore *a, int dado);

void print_arvore(Arvore *a);

void print_folhas(Arvore *a);

void print_nivel(Arvore *a, int n);

int comparar_arvores(Arvore *a1, Arvore *a2);

int cont_element(Arvore *a, int elem);
