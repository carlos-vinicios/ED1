#include <stdlib.h>
#include <iostream>
#include "arvore.h"

using namespace std;

int dateToInt(int dia, int mes, int ano){
    int data;
    data = dia * 24 + mes * 720 + mes * 720;
    return data;
}

void cadastrar(ArvoreNome *nomes, ArvoreDataEntrada *entradas, ArvoreDataSaida *saidas){
    Pessoa *p = NULL;
    int matricula, dia, mes, ano, entrada, saida;
    char *nome = new char[200];

    cout << "Digite a matricula do colaborador:\n";
    cin >> matricula;
    cout << "Digite o nome do colaborador:\n";
    cin >> nome;
    cout << "Digite a data de entrada: (dia mes ano)\n";
    cin >> dia;
    cin >> mes;
    cin >> ano;
    entrada = dateToInt(dia, mes, ano);
    cout << "Digite a data de saida: (dia mes ano)\n";
    cin >> dia;
    cin >> mes;
    cin >> ano;
    saida = dateToInt(dia, mes, ano);

    p = cadastrarPessoa(matricula, nome, entrada, saida);

    if(nomes == NULL)
        nomes = criarArvoreNome(p);
    else
        inserirArvoreNome(nomes, p);

    if(entradas == NULL)
        entradas = criarArvoreDataEntrada(p);
    else
        inserirArvoreDataEntrada(entradas, p);

    if(saidas == NULL)
        saidas = criarArvoreDataSaida(p);
    else
        inserirArvoreDataSaida(saidas, p);
}

void consultar

int main()
{
    ArvoreNome *nomes = NULL;
    ArvoreDataEntrada *entradas = NULL;
    ArvoreDataSaida *saidas = NULL;

    int opc;
    cout << "Selecione o que deseja fazer:\n1-Cadastrar\n2-Edição\n3-Consulta\n";
    cin >> opc;
    switch(opc){
        case 1:
            cadastrar(nomes, entradas, saidas);
            break;
        case 2:
            break;
        case 3:
            break;
    }
    return 0;
}
