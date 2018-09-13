#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_fila.h"

int main()
{
    int exec = 1, opc, novaSenha, open = 0, cont = 1;
    Fila *filaNormal = criar(20);
    Fila *filaPrioridade = criar(20);
    srand(time(NULL));

    do{
        printf("Opção:\n1 - Nova senha normal\n2 - Nova senha prioridade\n3 - Chamar\n4 - Sair\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                novaSenha = rand() % 100;
                if(!enfileirar(filaNormal, (void *) novaSenha))
                    printf("Erro\n");

                break;
            case 2:
                novaSenha = rand() % 100;
                if(!enfileirar(filaPrioridade, (void *) novaSenha))
                    printf("Erro\n");

                break;
            case 3:
                if(filaNormal->qtd + filaPrioridade->qtd >= 10)
                    open = 1;

                if(!vazia(filaPrioridade) && cont <= 3){
                    if(open)
                        printf("(prioridade) Senha: %d \n", (int *) desenfileirar(filaPrioridade));
                    else
                        printf("Limite minimo de pessoas ainda não foi atendido\n");

                    cont++;
                }else{
                    cont = (--cont%3) + 1;
                    if(!vazia(filaNormal)){
                        if(open)
                            printf("Senha: %d \n", (int *) desenfileirar(filaNormal));
                        else
                            printf("Limite minimo de pessoas ainda não foi atendido\n");
                    }else{
                        printf("A fila está vazia\n");
                    }
                }
                break;
            case 4:
                exec = 0;
                break;
        }

        printf("Normal\n");
        for(int i = filaNormal->inicio; i < filaNormal->fim; i++)
                printf("%d ", (int *) filaNormal->dados[i]);

        printf("\nPrioridade\n");
        for(int i = filaPrioridade->inicio; i < filaPrioridade->fim; i++)
                printf("%d ", (int *) filaPrioridade->dados[i]);

        printf("\n");
    }while(exec);

    return 0;
}
