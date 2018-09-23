#include <iostream>
#include "testes.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

void checkPilha(Pilha *p){
    int i, qtd;
    qtd = p->qtd;
    for(i = 0; i < qtd; i++)
        cout << "Pilha: " << *((int *) pop(p)) << '\n';
}

//--------------------------Questão 2--------------------
int check_xCy(string str1){
    Pilha *p;
    int i, f=1;
    char *aux;

//    p = criar(str1.size());
    if(p == NULL)
        return 0;

    i = 0;
    while(str1[i] != 'c'){
        push(p, (void *) &str1[i]);
        i++;
    }
    i++;
    do{
        aux = (char *) pop(p);
        if(*aux != str1[i]){
            f = 0;
            break;
        }
        i++;
    }while(!vazia(p));

    if(f)
        return 1;
    else
        return 0;
}

//-----------------------------------QUESTÃO 8-------------------------------
int buscaPilha(Pilha *p, int chave){
    int *aux;
    aux = (int *) pop(p);
    if(*aux == chave){
        push(p, (void *) aux);
        return 1;
    }else{
        if(p->qtd > 0){
            if(buscaPilha(p, chave)){
                push(p, (void *) aux);
                return 1;
            }
        }

        push(p, (void *) aux);
        return 0;
    }
}

//-----------------------------------QUESTÃO 16-------------------------------
//Fila *enfileirarPilha(Pilha *p){
//    Pilha *p_aux;
//    Fila *f;
//
//    f = criarFila(p->qtd);
//    p_aux = criar(p->qtd);
//
//    while(!vazia(p)){
//        push(p_aux, pop(p));
//    }
//
//    while(!vazia(p_aux)){
//        enfileirar(f, pop(p_aux));
//    }
//
//    return f;
//}

//-----------------------------------QUESTÃO 17-------------------------------
//int remove_bloco(Sequencia *seq, int inicio, int fim){
//    int i;
//    if(seq != NULL && seq->dados != NULL && seq->qtd > 0 && inicio <= fim && (seq->qtd-1) >= inicio && fim <= (seq->qtd-1) ){
//        if((seq->qtd - 1)-fim == 0)
//            seq->qtd-=fim-inicio+1;
//        else{
//            j = 0;
//            for(i = 1; i <= (fim-inicio+1); i++){
//                seq->dados[inicio+j] = seq->dados[seq->qtd - i];
//                j++;
//            }
//        }
//        return 1;
//    }
//
//    return 0;
//}

//int comp(void *a, void *b){
//    int *e1 = (int *) a;
//    int *e2 = (int *) b;
//    if(*e1 == *e2)
//        return 1;
//
//    return 0;
//}

int main()
{
//--------------------------------QUESTÃO 1----------------------------------------
//    int *i, j, *dado;
//    Pilha *p = criar(5);
//    if(p == NULL)
//        return 0;
//
//    dado = new int[1];
//    *dado = 1;
//    push(p, (void *) dado);
//    dado = new int[1];
//    *dado = 3;
//    push(p, (void *) dado);
//    dado = new int[1];
//    *dado = 5;
//    push(p, (void *) dado);
//    dado = new int[1];
//    *dado = 8;
//    push(p, (void *) dado);
//    dado = new int[1];
//    *dado = 11;
//    push(p, (void *) dado);

    //Questão A:
//    for(j=0; j < 2; j++)
//        i = (int *) pop(p);
//
//    i = (int *) pop(p);
//
//    cout << *i << '\n';

    //Questão B:
//    int *a, *b;
//
//    a = (int *) pop(p);
//    b = (int *) pop(p);
//    i = (int *) pop(p);
//    push(p, (void *) b);
//    push(p, (void *) a);
//
//    cout << "I: " << *i << '\n';

    //Questão C
//    int n;
//
//    cin >> n;
//
//    for(j = 0; j < n; j++)
//        i = (int *) pop(p);
//
//    i = (int *) pop(p);
//
//    cout << *i << '\n';

    //Questão D
//    int n, k;
//    int **aux;
//
//    cin >> n;
//    aux = new int*[n];
//    k = n-1;
//    for(j = 0; j < n; j++){
//        i = (int *) pop(p);
//        aux[k] = i;
//        k--;
//    }
//
//    i = (int *) pop(p);
//
//    for(j=0; j < n; j++){
//        push(p, (void *) aux[j]);
//    }
//
//    cout << *i << '\n';
//
//    return 0;

    //Questão E
//    while(! vazia(p))
//        i = (int *) pop(p);
//
//    cout << *i << '\n';

    //Questão F
//    int qtd;
//    Pilha *p2;
//    p2 = criar(p->tam);
//    while(! vazia(p)){
//        i = (int *) pop(p);
//        push(p2, (void *) i);
//    }
//
//    qtd = p2->qtd;
//    for(j = 0; j < qtd; j++){
//        push(p, pop(p2));
//    }
//
//    cout << *i << '\n';

    //Questão G
//    int f;
//    f = p->qtd - 3;
//    for(j = 0; j <= f; j++)
//        i = (int *) pop(p);
//
//    cout << *i << '\n';


//-------------------------------QUESTÃO 2----------------------------------------
//    Pilha *p;
//    string str1;
//    int i, f=1;
//    char *aux;
//
//    cin >> str1;
//
//    p = criar(str1.size());
//    if(p == NULL)
//        return 0;
//
//    i = 0;
//    while(str1[i] != 'c'){
//        push(p, (void *) &str1[i]);
//        i++;
//    }
//    i++;
//    do{
//        aux = (char *) pop(p);
//        if(*aux != str1[i]){
//            f = 0;
//            break;
//        }
//        i++;
//    }while(!vazia(p));
//
//    if(f)
//        cout << "Elas sao xCy\n";
//    else
//        cout << "Nao sao xCy\n";
//
//    return 0;


//-----------------------------------QUESTÃO 3-------------------------------
//    string str1, str2;
//    int i, f=1;
//
//    cin >> str1;
//
//    for(i = 0; i < str1.size(); i++){
//        if(str1[i] != 'd'){
//            str2+=str1[i];
//        }else{
//            if(!check_xCy(str2)){
//                f=0;
//                break;
//            }
//            str2="";
//        }
//    }
//
//    if(f)
//        cout << "Sao da forma desejada";
//    else
//        cout << "Nao sao da forma desejada";
//
//    return 0;


//-----------------------------------QUESTÃO 4-------------------------------
//    int opc, operacao = 0, exec = 1;
//
//    do{
//        cout << "1 - push\n2 - pop\n";
//        cin >> opc;
//
//        switch(opc){
//            case 1:
//                operacao++;
//                break;
//            case 2:
//                operacao--;
//                break;
//            default:
//                exec = 0;
//                break;
//        }
//
//        if(operacao < 0){
//            cout << "Underflow";
//            exec = 0;
//        }
//    }while(exec);

//-----------------------------------QUESTÃO 5-------------------------------

    /*
        Para evitar o uso desnecessario de memória e para facilitar as operações na pilha

    */

//-----------------------------------QUESTÃO 6-------------------------------

//-----------------------------------QUESTÃO 7-------------------------------
//    int i, j, c1, c2, *aux, *dado;
//    Pilha *p1, *p2;
//
//    p1 = criar(5);
//    p2 = criar(5);
//
//    dado = new int[1];
//    *dado = 7;
//    push(p1, (void *) dado);
//    dado = new int[1];
//    *dado = 6;
//    push(p1, (void *) dado);
//    dado = new int[1];
//    *dado = 5;
//    push(p1, (void *) dado);
//    dado = new int[1];
//    *dado = 4;
//    push(p1, (void *) dado);
//    dado = new int[1];
//    *dado = 3;
//    push(p1, (void *) dado);
//
//    c1 = p1->qtd;
//    for(i = 0; i< c1; i++){
//        c2 = p1->qtd - 1;
//        for(j = 0; j < c2; j++){
//            aux = (int *) pop(p1);
//            push(p2, (void *) aux);
//        }
//        aux = (int *) pop(p1);
//        cout << "Atendido: " << *aux << '\n';
//        c2 = p2->qtd;
//        for(j = 0; j < c2; j++){
//            push(p1,  pop(p2));
//        }
//    }
//
//    return 0;

//-----------------------------------QUESTÃO 8-------------------------------

    //vide funções no topo da main;
//    Pilha *p1;
//    int *dado, res;
//
//    p1 = criar(5);
//
//    dado = new int[1];
//    *dado = 7;
//    push(p1, (void *) dado);
//    dado = new int[1];
//    *dado = 6;
//    push(p1, (void *) dado);
//    dado = new int[1];
//    *dado = 5;
//    push(p1, (void *) dado);
//    dado = new int[1];
//    *dado = 4;
//    push(p1, (void *) dado);
//    dado = new int[1];
//    *dado = 3;
//    push(p1, (void *) dado);
//
//    res = buscaPilha(p1, 9);
//
//    if(res)
//        cout << "Achou" << '\n';
//    else
//        cout << "Não achou" << '\n';
//
//
//    return 0;

//-----------------------------------QUESTÃO 9-------------------------------
// ver implementação das pilhas testes.cpp

//-----------------------------------QUESTÃO 10-------------------------------
//ver implementação das filas testes.cpp

//-----------------------------------QUESTÃO 11-------------------------------
//    string seq;
//    int i, f, forma = 0;
//    cin >> seq;
//    if(seq[0] == 'd')
//        cout << "Mal formada\n";
//    else
//        for(i = 1; i < seq.size(); i++){
//            switch(seq[i]){
//                case 'e':
//                    forma++;
//                    break;
//                case 'd':
//                    forma--;
//                    if(forma < 0){
//                        cout << "Mal formada\n";
//                        return 0;
//                    }
//                    break;
//                default:
//                    cout << "Valor invalido";
//                    return 0;
//                    break;
//            }
//        }
//
//    cout << "Bem formada";
//    return 0;


//-----------------------------------QUESTÃO 12-------------------------------
    //ver implementação das filas testes.cpp


//-----------------------------------QUESTÃO 13-------------------------------
    //?????????????????????? perguntar para o professor se não é igual a implementação da filaDupla


//-----------------------------------QUESTÃO 14-------------------------------
    //ver implementação das filas testes.cpp e fazer os devidos testes


//-----------------------------------QUESTÃO 15-------------------------------
    //ver implementação das pilhas testes.cpp
//        Pilha *p1;
//        int *dado, res;
//
//        p1 = criar(5, comp);
//
//        dado = new int[1];
//        *dado = 7;
//        push(p1, (void *) dado);
//        dado = new int[1];
//        *dado = 6;
//        push(p1, (void *) dado);
//        dado = new int[1];
//        *dado = 5;
//        push(p1, (void *) dado);
//        dado = new int[1];
//        *dado = 4;
//        push(p1, (void *) dado);
//        dado = new int[1];
//        *dado = 3;
//        push(p1, (void *) dado);
//
//        if(busca_e_remove(p1, (void *) dado))
//            cout << "Removido com sucesso";
//
//        checkPilha(p1);
//        return 0;

//-----------------------------------QUESTÃO 16-------------------------------
    //funções no topo da main


//-----------------------------------QUESTÃO 17-------------------------------
    //funções no topo da main testar
}
