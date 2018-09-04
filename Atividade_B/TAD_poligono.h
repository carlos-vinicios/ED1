#ifndef TAD_poligono
#define TAD_poligono

//Estrutura para controle das coordenadas
typedef struct _Ponto_{
    float x;
    float y;
} Ponto;

//TAD para manipular o registro de polígonos
typedef struct _Poligono_{
    Ponto *ponto;
    int qtd_lados;
    int qtd_registrados;
} Poligono;

/*Cria a sequencia de coordenadas de um polígono
    @param qtd_lados quantidade de lados que o polígono apresenta
    @return sequencia alocada se sucesso, NULL em caso de erro
*/
Poligono *criarPoligono(int qtd_lados);

/*Insere todas as coordenada do poligono, sempre em sentido horário dos pontos presente no polígono (esquerda para direita / cima para baixo )
    @param pol sequencia de um polígono valida
    @param x coordenadas do eixo x
    @param y coordenadas do eixo y
    @return 1 sucesso 0 falha
*/
int inserirCoordenadas(Poligono *pol, float x, float y);

/*Imprime as coordenadas do polígono
    @param pol sequencia de um polígono valida
    @return 1 sucesso 0 falha
*/
int imprimirPoligono(Poligono *pol);

/*Retorna o perímetro total de um polígono
    @param pol sequencia de um polígono valida
    @return perimetro total, sucesso; 0, falha
*/
float perimetroPoligono(Poligono *pol);

/*Imprime o tamanho de cada lado de um polígono
    @param pol sequencia de um polígono valida
    @return vetor de lados, sucesso; 0 falha
*/
float *tamLadosPoligono(Poligono *pol);

/*Destroi a sequencia de coordenadas de um polígono
    @param pol sequencia de um polígono valida
    @return 1 sucesso 0 falha
*/
int destruirPoligono(Poligono **pol);

#endif
