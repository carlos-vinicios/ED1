#ifndef TAD_fila
#define TAD_fila

/*Fila para controle do antendimento a coordenação*/
typedef struct _Fila_{
    void **dados; //vetor de dados a ser armazenado
    int inicio; //variavel de inicio do vetor
    int fim; //variavel de fim do vetor
    int qtd; //quantidade de elementos dentro do vetor
    int qtd_max; //quantidade máxima de elementos dentro do vetor
} Fila;

/*Cria a fila de dados
    @param qtd_max é quantidade máxima de elementos que o vetor de dados pode armazenar
    @return um fila alocada, caso sucesso. NULL, caso erro
*/
Fila *criar(int qtd_max);

/*Adiciona elementos a fila, respeitando a ordem de chegada de cada elemento
    @param fila uma fila válida para registro e controle dos dados
    @param dado elemento que deve ser adicionado ao fim da fila de elementos
    @return 1 sucesso, 0 erro
*/
int enfileirar(Fila *fila, void *dado);

/*Remove elementos da fila, respeitando a ordem de chegada de cada elemento
    @param fila uma fila váida para controle dos dados
    @return um dado correspondente a dada posição da fila
*/
void *desenfileirar(Fila *fila);

/*Verifica se a fila está vázia
    @param fila uma fila válida
    @return 1 em caso seja verdade 0 em caso não esteja vázia
*/
int vazia(Fila *fila);

#endif // TAD_fila
