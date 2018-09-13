#ifndef TAD_imagem
#define TAD_imagem

typedef int (* Comparar)(void *a, void *b);

typedef struct _imagem_{
    void **pixels;
    int qtd_pixels;
    int largura;
    int altura;
} Imagem;


/*Constroi uma imagem baseada na altura e largura fornecida
    @param altura_max altura maxima para a imagem
    @param largura_max largura maxima para a imagem
    @return um TAD_imagem definido de acordo com os atributos fornecidos
*/
Imagem *construir(int altura_max, int largura_max);

/*Define o valor de um pixel
    @param img uma imagem válida
    @param x coordenada no eixo X do pixel a ser modificado
    @param y coordenada no euxo Y do pixel a ser modificado
    @return 1 sucesso 0 falha
*/
int setPixel(Imagem *img, int x, int y, void *px);

/*Fornece as informações de um dado pixel
    @param img uma imagem válida
    @param x coordenada no eixo X do pixel a ser fornecido as informações
    @param y coordenada no eixo Y do pixel a ser fornecido as informações
    @return Pixel sucesso NULL falha
*/
void *getPixel(Imagem *img, int x, int y);

/*Retorna as informações de um certo espaço da imagem
    @param img uma imagem válida
    @param x coordenada no eixo X mais a esquerda do ponto desejado
    @param y coordenada no eixo Y mais a esquerda do ponto desejado
    @param largura a largura da da area na imagem que deseja receber informações
    @param comprimento  o comprimento da area na imagem que deseja receber informações
    @return TAD_imagem com as novas dimensões definidas
*/
Imagem *getRect(Imagem *img, int x, int y, int largura, int comprimento);

#endif
