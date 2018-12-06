#include <stdlib.h>
#include <iostream>
#include "arvore.h"

using namespace std;

/*void imprimePosOrdemNome(ArvoreNome *nomes){
    if(nomes != NULL)
        cout << nomes->pessoa->nome << "\n";
    if(nomes->esq != NULL)
        imprimePosOrdemNome(nomes->esq);
    if(nomes->dir != NULL)
        imprimePosOrdemNome(nomes->dir);
}

void imprimePosOrdemSaida(ArvoreDataSaida *saidas){
    if(saidas != NULL)
        cout << saidas->pessoa->nome << "\n";
    if(saidas->esq != NULL)
        imprimePosOrdemSaida(saidas->esq);
    if(saidas->dir != NULL)
        imprimePosOrdemSaida(saidas->dir);
}

void imprimePosOrdemEntrada(ArvoreDataEntrada *entradas){
    if(entradas != NULL)
        cout << entradas->pessoa->nome << "\n";
    if(entradas->esq != NULL)
        imprimePosOrdemEntrada(entradas->esq);
    if(entradas->dir != NULL)
        imprimePosOrdemEntrada(entradas->dir);
}*/

int dateToInt(char *data){
    int dataInt, dia, mes, ano;
    char diaStr[3], mesStr[3], anoStr[5];
    diaStr[0] = data[0];
    diaStr[1] = data[1];
    diaStr[2] = '\0';
    mesStr[0] = data[3];
    mesStr[1] = data[4];
    mesStr[2] = '\0';
    anoStr[0] = data[6];
    anoStr[1] = data[7];
    anoStr[2] = data[8];
    anoStr[3] = data[9];
    anoStr[4] = '\0';
    dia = atoi(diaStr);
    mes = atoi(mesStr);
    ano = atoi(anoStr);
    dataInt = dia * 24 + mes * 720 + mes * 8640;
    return dataInt;
}

void cadastrar(ArvoreNome **nomes, ArvoreDataEntrada **entradas, ArvoreDataSaida **saidas){
    Pessoa *p = NULL;
    int matricula, entrada, saida;
    char *nome = new char[200];
    char *data = new char[11];

    cout << "Digite a matricula do colaborador:\n";
    cin >> matricula;
    cout << "Digite o nome do colaborador:\n";
    cin >> nome;
    cout << "Digite a data de entrada: (dia/mes/ano)\n";
    cin >> data;
    entrada = dateToInt(data);
    cout << "Digite a data de saida: (dia/mes/ano)\n";
    cin >> data;
    saida = dateToInt(data);

    p = cadastrarPessoa(matricula, nome, entrada, saida);

    if(*nomes == NULL)
        *nomes = criarArvoreNome(p);
    else
        inserirArvoreNome(*nomes, p);

    if(*entradas == NULL)
        *entradas = criarArvoreDataEntrada(p);
    else
        inserirArvoreDataEntrada(*entradas, p);

    if(*saidas == NULL)
        *saidas = criarArvoreDataSaida(p);
    else
        inserirArvoreDataSaida(*saidas, p);
}

void consultar(ArvoreNome **nomes, ArvoreDataEntrada **entradas, ArvoreDataSaida **saidas){
    char *nome = NULL;
    char *dataStr = new char[11];
    int opc, dia, mes, ano, data, i;
    Lista *pessoas=NULL, *aux=NULL;
    cout << "Qual a opção de consulta:\n1-Nome\n2-Data de entrada\n3-Data de saida\n";
    cin >> opc;
    switch(opc){
        case 1:
            cout << "Digite o nome do colaborador:\n";
            nome = new char[200];
            cin >> nome;
            pessoas = buscarArvoreNome(*nomes, nome);
            break;
        case 2:
            cout << "Digite a data desejada: (dia/mes/ano)\n";
            cin >> dataStr;
            data = dateToInt(dataStr);
            pessoas = buscarArvoreDataEntrada(*entradas, data);
            break;
        case 3:
            cout << "Digite a data desejada: (dia/mes/ano)\n";
            cin >> dataStr;
            data = dateToInt(dataStr);
            pessoas = buscarArvoreDataSaida(*saidas, data);
            break;
    }
    aux = pessoas;
    cout << '\n';
    while(aux != NULL){
        cout << aux->pessoa->nome << '\n';
        aux = aux->prox;
    }
}

void alterar(ArvoreNome **nomes, ArvoreDataEntrada **entradas, ArvoreDataSaida **saidas){
    char *nome = NULL;
    char *dataStr = new char[11];
    int opc, selec, dia, mes, ano, entrada, saida, data, i=1;
    Lista *pessoas, *aux;
    cout << "Qual a opção para busca do colaborador:\n1-Nome\n2-Data de entrada\n3-Data de saida\n";
    cin >> opc;
    switch(opc){
        case 1:
            cout << "Digite o nome do colaborador:\n";
            nome = new char[200];
            cin >> nome;
            pessoas = buscarArvoreNome(*nomes, nome);
            break;
        case 2:
            cout << "Digite a data desejada: (dia/mes/ano)\n";
            cin >> dataStr;
            data = dateToInt(dataStr);
            pessoas = buscarArvoreDataEntrada(*entradas, data);
            break;
        case 3:
            cout << "Digite a data desejada: (dia/mes/ano)\n";
            cin >> dataStr;
            data = dateToInt(dataStr);
            pessoas = buscarArvoreDataSaida(*saidas, data);
            break;
    }
    aux = pessoas;
    while(aux != NULL){
        cout << i << " " <<aux->pessoa->nome << '\n';
        i++;
        aux = aux->prox;
    }
    i = 1;
    cout << "Selecione o colaborador desejado: \n";
    cin >> selec;
    aux = pessoas;
    while(aux != NULL){
        if(i == selec)
            break;
        aux = aux->prox;
    }
    cout << "Digite o nome do colaborador:\n";
    cin >> nome;
    cout << "Digite a data de entrada: (dia/mes/ano)\n";
    cin >> dataStr;
    entrada = dateToInt(dataStr);
    cout << "Digite a data de saida: (dia/mes/ano)\n";
    cin >> dataStr;
    saida = dateToInt(dataStr);
    editarPessoa(aux->pessoa, nome, entrada, saida);
}

int main()
{
    ArvoreNome *nomes = NULL;
    ArvoreDataEntrada *entradas = NULL;
    ArvoreDataSaida *saidas = NULL;

    int opc, consulta, exec;
    do{
        cout << "Selecione o que deseja fazer:\n1-Cadastrar\n2-Edição\n3-Consulta\n";
        cin >> opc;
        switch(opc){
            case 1:
                cadastrar(&nomes, &entradas, &saidas);
                break;
            case 2:
                alterar(&nomes, &entradas, &saidas);
                break;
            case 3:
                consultar(&nomes, &entradas, &saidas);
                break;
        }

        cout << "\nDeseja fazer outra operacao?\n1-Sim 0-Nao\n";
        cin >> exec;
    }while(exec);
    return 0;
}
