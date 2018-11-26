
typedef struct _palavra_{
    char *sintaxe;
    int qtd;
    _palavra_ *sinonimo;
    _palavra_ *prox;
} Palavra;

typedef struct _dicionario_{
    Palavra *cab;
    Palavra *ult;
} Dicionario;

/*Aloca um novo dicionario na memória
    @return um dicionario alocado
*/
Dicionario *criarDicionario();

/*Aloca uma nova palavra na memória
    @param sintaxe palavra a ser criada
    @return um dicionario alocado
*/
Palavra *criarPalavra(char *sintaxe);

/*Adiciona uma palavra ao dicionario
    @param d um dicionario válido
    @param palavra a palavra que será adicionada
    @return o ponteiro contendo a palavra adicionada
*/
Palavra *addPalavra(Dicionario *d, char *palavra);

/*Adiciona um sinônimo a uma palavra
    @param d um dicionario válido
    @param palavra a palavra que irá se adicionar o sinonimo
    @param sinonimo o sinônimo da palavra
    @return 1 sucesso 0 falha
*/
int addSinonimo(Dicionario *d, char *palavra, char *sinonimo);

/*Busca uma palavra dentro do dicionario
    @param d um dicionario válido
    @param palavra a palavra que será buscada
    @return o ponteiro contendo a palavra buscada, NULL em caso de falha
*/
Palavra *buscarPalavra(Dicionario *d, char *palavra);

/*Busca uma palavra dentro do dicionario que seja ideal para a substituição de uma dada palavra
    @param d um dicionario válido
    @param palavra a palavra que será substituida
    @return o ponteiro contendo a nova palavra
*/
Palavra *substituirPalavra(Dicionario *d, char *palavra);

/*Realiza a substituição das palavras em um paragrafo
    @param d um dicionario válido
    @param paragrafo o paragrafo que será formatado
    @return paragrafo com as palavras substituidas
*/
char *formalizarTexto(Dicionario *d, char *paragrafo);
