#ifndef TAD_evento
#define TAD_evento

//TAD para manipular as entradas de um evento
typedef struct _Evento_{
    int *entradas; //vetor contendo as entradas registradas
    int qtd_entradas; //quantidade de entradas realizadas
    int qtd_max; //quantidade m�xima de entradas permitidas
} Evento;

/* Realiza a cria��o do TAD evento
    @param qtd_max o tamanho m�ximo desejado para o evento
    @return sequencia alocada e v�lida NULL em caso de erro
*/
Evento *criaEvento(int qtd_max);

/* Registra uma nova entrada no evento
    @param evento sequencia v�lida
    @param id n�mero de entrada
    @return 1 sucesso 0 falha
*/
int novaEntrada(Evento *evento, int chave);

/* Realiza a busca por um valor dentro da sequ�ncia
    @param evento sequencia v�lida
    @param chave valor buscado dentro da sequencia
    @return 1 sucesso 0 falha
*/
int procuraEntrada(Evento *evento, int chave);

/* Realiza a remo��o de um valor da sequ�ncia
    @param evento sequ�ncia v�lida
    @param chave valor a ser excluido
    @return 1 sucesso 0 falha
*/
int removerEntrada(Evento *evento, int chave);

/* Realiza a destrui��o da sequ�ncia
    @param evento sequ�ncia v�lida
    @return 1 sucesso 0 falha
*/
int destruitEvento(Evento **evento);

#endif
