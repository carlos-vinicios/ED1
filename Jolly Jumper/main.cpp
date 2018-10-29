#include <iostream>
#include <math.h>
#include "Pilha_lista.h"

using namespace std;

int main()
{
    int n, n_elm, i, a, b, result, jolly=1;

    Pilha *input = criarPilha();
    Pilha *output = criarPilha();

    cin >> n_elm;
    for(i = 0; i < n_elm; i++){
        cin >> n;
        push(input, n);
    }

    while(input->qtd > 1){
        a = pop(input);
        b = pop(input);
        push(input, b);
        push(output, abs(a-b));
    }

    while(output->qtd > 1){
        a = pop(output);
        b = pop(output);
        if(b > a || b < (a-1))
            jolly =  0;
    }

    if(jolly)
        cout << "Jolly";
    else
        cout << "Not Jolly";
    return 0;
}
