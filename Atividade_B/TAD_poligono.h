#ifndef TAD_poligono
#define TAD_poligono

//Estrutura para controle das coordenadas
typedef struct _Ponto_{
    float x;
    float y;
} Ponto;

//TAD para manipular o registro de pol�gonos
typedef struct _Poligono_{
    Ponto *ponto;
    int qtd_lados;
    int qtd_registrados;
} Poligono;

/*Cria a sequencia de coordenadas de um pol�gono
    @param qtd_lados quantidade de lados que o pol�gono apresenta
    @return sequencia alocada se sucesso, NULL em caso de erro
*/
Poligono *criarPoligono(int qtd_lados);

/*Insere todas as coordenada do poligono, sempre em sentido hor�rio dos pontos presente no pol�gono (esquerda para direita / cima para baixo )
    @param pol sequencia de um pol�gono valida
    @param x coordenadas do eixo x
    @param y coordenadas do eixo y
    @return 1 sucesso 0 falha
*/
int inserirCoordenadas(Poligono *pol, float x, float y);

/*Imprime as coordenadas do pol�gono
    @param pol sequencia de um pol�gono valida
    @return 1 sucesso 0 falha
*/
int imprimirPoligono(Poligono *pol);

/*Retorna o per�metro total de um pol�gono
    @param pol sequencia de um pol�gono valida
    @return perimetro total, sucesso; 0, falha
*/
float perimetroPoligono(Poligono *pol);

/*Imprime o tamanho de cada lado de um pol�gono
    @param pol sequencia de um pol�gono valida
    @return vetor de lados, sucesso; 0 falha
*/
float *tamLadosPoligono(Poligono *pol);

/*Destroi a sequencia de coordenadas de um pol�gono
    @param pol sequencia de um pol�gono valida
    @return 1 sucesso 0 falha
*/
int destruirPoligono(Poligono **pol);

#endif
