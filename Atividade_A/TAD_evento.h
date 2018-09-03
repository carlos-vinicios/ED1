//TAD para manipular as entradas de um evento
typedef struct _Evento_{
    int *entradas; //vetor contendo as entradas registradas
    int qtd_entradas; //quantidade de entradas realizadas
    int qtd_max; //quantidade máxima de entradas permitidas
} Evento;

/* Realiza a criação do TAD evento
    @param qtd_max o tamanho máximo desejado para o evento
    @return sequencia alocada e válida NULL em caso de erro
*/
Evento *criaEvento(int qtd_max);

/* Registra uma nova entrada no evento
    @param evento sequencia válida
    @param id número de entrada
    @return 1 sucesso 0 falha
*/
int novaEntrada(Evento *evento, int id);

/* Realiza a busca por um valor dentro da sequência
    @param evento sequencia válida
    @param chave valor buscado dentro da sequencia
    @return 1 sucesso 0 falha
*/
int procuraEntrada(Evento *evento, int chave);

/* Realiza a remoção de um valor da sequência
    @param evento sequência válida
    @param chave valor a ser excluido
    @return 1 sucesso 0 falha
*/
int removerEntrada(Evento *evento, int chave);

/* Realiza a destruição da sequência
    @param evento sequência válida
    @return 1 sucesso 0 falha
*/
int destruitEvento(Evento **evento);

