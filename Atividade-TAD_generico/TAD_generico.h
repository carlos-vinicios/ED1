#ifndef TAD_generico
#define TAD_generico

typedef int (*Comparar)(void *a, void *b);

typedef struct _sequencia_{
    void **dados;
    int qtd;
    int qtd_max;
    Comparar comp;
} Sequencia;

/*Cria uma nova sequencia para alocação dos dados
    @param qtd_max a quantidade maxima de elementos contidas na sequência
    @param c função para comparar dois elementos contidos na sequência
    @return sequencia alocada na memoria
*/
Sequencia *criar(int qtd_max, Comparar c);

/*Insere um novo elemento na sequencia
    @param seq uma sequencia válida
    @param chave elemento a ser inserido na sequencia
    @return 1 sucesso 0 falha
*/
int inserir(Sequencia *seq, void *chave);

int inserirNull(Sequencia *seq, void *chave);

int inserirOrdenado(Sequencia *seq, void *chave);

/*Busca um elemento na sequencia dada
    @param seq sequencia válida
    @param chave elemento a ser buscado dentro da sequencia
    @return 1 encontrado 0 não encontrado
*/
int buscar(Sequencia *seq, void *chave);

int buscaIgnoreNull(Sequencia *seq, void *chave);

/*Remove todos os elemento, iguais aos dados, da sequencia
    @param seq sequencia válida
    @param chave elemento a ser removido da sequencia
    @return 1 sucesso 0 falha
*/
int remover(Sequencia *seq, void *chave);

int setNull(Sequencia *seq, void *chave);

/*Destroi um sequencia de elementos
    @param seq sequencia válida para a exclusão
    return 1 sucesso 0 falha
*/
int destruir(Sequencia *seq);

#endif // TAD_generico
