#include <iostream>
#include <stdlib.h>

using namespace std;

char **set_cenario(int tam){
    char **cenario = NULL;
    int i;
    if(tam > 0){
        cenario = new char *[tam];
        for(i = 0; i < tam; i++)
            cenario[i] = new char[3*tam];

    }
    return cenario;
}

void start_cenario(char **cenario, int tam){
    int i, j;
    for(i = 0; i < tam; i++)
        for(j = 0; j < 3*tam; j++){
            if(i == 0 || i == tam-1){
                cenario[i][j] = '-';
            }else{
                if(j == 0 || j == 3*tam-1){
                    cenario[i][j] = '|';
                }else{
                    cenario[i][j] = ' ';
                }
            }
        }
}

void draw_cenario(char **cenario, int tam){
    int i, j;
    for(i = 0; i < tam; i++){
        for(j = 0; j < 3*tam; j++)
            cout << cenario[i][j];

        cout << '\n';
    }
}
