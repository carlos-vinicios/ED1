#include <iostream>
#include <string.h>
#include "dicionario.h"

using namespace std;

/*void printDic(Dicionario *d1){
    Palavra *aux = d1->cab;
    while(aux != NULL){
        cout << aux->sintaxe << " qtd:" << aux->qtd << '\n';
        aux=aux->prox;
    }
}

void printSin(Dicionario *d1, char *palavra){
    Palavra *aux;
    Palavra *p = buscarPalavra(d1, palavra);
    if(p != NULL){
        aux = p->sinonimo;
        while(aux != NULL){
            cout << aux->sintaxe << '\n';
            aux = aux->prox;
        }
    }
}*/

/* Arquivo para registro das palavras:
    dicionario.txt
    formato: palavra-sinonimo;sinonimo;sinonimo;\n
*/

/* Arquivo para entrada do texto:
    texto.txt
*/

int main()
{
    FILE *arq, *arq2;
    int opc, exec1=1, exec2=1, tam;
    int i,j,k=0;
    char *texto, *formalizado, *palavra1, *palavra2, *linha;
    Dicionario *d1 = criarDicionario();

    palavra1 = new char[50];
    palavra2 = new char[50];

    do{
        cout << "O que deseja fazer?\n1-Entrada de palavras\n2-Entrada de texto para formalização\n3-Sair\n";
        cin >> opc;
        switch(opc){
            case 1:
                cout << "Como deseja fazer o registro das palavras?\n1-Digitar\n2-Ler de arquivo\n3-Menu principal\n";
                cin >> opc;
                switch(opc){
                    case 1:
                        do{
                            cout << "1-Entrar com uma palavra\n2-Entrar com um sinonimo\n3-Sair\n";
                            cin >> opc;
                            switch(opc){
                                case 1:
                                    cin >> palavra1;
                                    addPalavra(d1, palavra1);
                                    break;
                                case 2:
                                    cout << "Palavra";
                                    cin >> palavra1;
                                    cout << "Sinonimo";
                                    cin >> palavra2;
                                    addSinonimo(d1, palavra1, palavra2);
                                    break;
                                case 3:
                                    exec2 = 0;
                                    break;
                            }
                        }while(exec2);
                        break;
                    case 2:
                        arq = fopen("dicionario.txt", "r");
                        fseek(arq, 0, SEEK_END);
                        tam = ftell(arq);
                        linha = new char[tam];
                        rewind(arq);
                        while(fgets(linha, tam, arq) != NULL){
                            k=0;
                            memset(palavra1, 0, 50);
                            memset(palavra2, 0, 50);
                            for(i = 0; i < strlen(linha); i++){
                                if(linha[i] == '-'){
                                    palavra1[k] = '\0';
                                    addPalavra(d1, palavra1);
                                    k = 0;
                                    for(j = i+1; j < strlen(linha); j++){;
                                        if(linha[j] != ';'){
                                            palavra2[k]=linha[j];
                                            k++;
                                        }else{
                                            palavra2[k]='\0';
                                            addSinonimo(d1, palavra1, palavra2);
                                            memset(palavra2, 0, 50);
                                            k=0;
                                        }
                                    }
                                }else{
                                    palavra1[k]=linha[i];
                                    k++;
                                }
                            }
                        }
                        fclose(arq);
                        break;
                }
                break;
            case 2:
                arq2 = fopen("texto.txt", "r");
                fseek(arq2, 0, SEEK_END);
                tam = ftell(arq2);
                texto = new char[tam];
                rewind(arq2);
                while(fgets(texto, tam, arq2) != NULL){
                    if(strlen(texto) < 2)
                        break;
                    formalizado = formalizarTexto(d1, texto);
                    cout << "\n" << formalizado << "\n";
                }
                fclose(arq2);
                break;
            case 3:
                return 0;
                break;
        }
    }while(exec1);
}
