#ifndef TAD_sequencia
#define TAD_sequencia

//TAD para minipular dados sequencias em vetor
typedef struct _Sequencia_{
    int *dados; //seus dados
    int tamanho; //qtd total de elementos
    int qtd; //qtd atual de elementos
} Sequencia;

/* Cria o TAD Sequencia
    @param tamanho o tamanho desejado
    @return sequencia alocada e válida NULL em caso de erro
*/
Sequencia *Create(int tamanho);

/* Insere novo elemento na sequencia se houver espaço
    @param seq a sequencia válida
    @param dado o novo elemento
    @return 1 sucesso 0 falha
*/
int Insert(Sequencia *seq, int dado);

/* Remove um dado elemento na sequencia se o mesmo existir
    @param seq a sequencia válida
    @param chave o parametro que deseja remover
    @return 1 sucesso 0 elemento não existe na sequencia
*/
int Remove(Sequencia *seq, int chave);

/* Procura um dado elemento na sequencia
    @param seq a sequencia válida
    @param chave o parametro que deseja buscar
    @return 1 caso exista 0 caso não exista ou dê algum erro
*/
int Search(Sequencia *seq, int chave);

/* Realiza a destruição da sequencia
    @param seq a sequencia válida
    @return 1 sucesso 0 falha
*/
int Destroy(Sequencia **seq);

#endif
