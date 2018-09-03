#include "TAD_sequencia.h"
#include "stdio.h"
#include "stdlib.h"

Sequencia *Create(int tamanho){
    Sequencia *seq = NULL;
    if(tamanho > 0){
        seq = (Sequencia *) malloc(sizeof(Sequencia)); //alocação da estrutura
        if(seq != NULL){
            seq->dados = (int *) malloc(tamanho * sizeof(int)); //alocação do vetor
            if(seq->dados != NULL){
                seq->qtd = 0; //quantidade de elementos presentes no vetor, iniciado com o número 0 representando um vetor vazio
                seq->tamanho = tamanho; //declara o tamanho do vetor
            }else{
                free(seq);
                seq = NULL;
            }
        }
    }
    return seq; //retorna a sequencia criada
}

int Insert(Sequencia *seq, int dado){
    if(seq != NULL){
        if(seq->qtd < seq->tamanho && seq->dados != NULL){ //se a quantidade de elementos mais o adicionado for menor que o tamanho permitido
            seq->dados[seq->qtd] = dado; //adiciona o elemento ao vetor da sequencia
            seq->qtd++; //incrementa a quantidade de elementos dentro do vetor
            return 1; //retorna 1 para o inserção do vetor
        }
    }
    return 0; //retorna 0 pois não pode inserir o elemento no vetor
}

int Remove(Sequencia *seq, int chave){ //pega o elemento que deseja excluir e joga para o final do vetor, substituindo a posição pelo que está na última
    int i;
    if(seq != NULL && seq->dados != NULL && seq->qtd > 0){
        for(i = 0; i < seq->qtd; i++){ //procura o elemento dentro do vetor para ser excluido
            if(seq->dados[i] == chave){
                seq->dados[i] = seq->dados[seq->qtd - 1]
                seq->qtd--;
            }else{
                i++;
            }
        }
        return 1;
    }
    return 0;
}

int Search(Sequencia *seq, int chave){
    int i;
    if(seq != NULL && seq->dados != NULL && seq->qtd > 0){
            for(i = 0; i < seq->qtd; i++){ //realiza a busca do elemento dentro do vetor da sequencia
                if(seq->dados[i] == chave) //caso ache o elemento retorna a posição do mesmo
                    return 1;
            }
    }
    return 0;
}

int Destroy(Sequencia **seq){
    if(*seq != NULL){
        free(*seq);
        *seq = NULL; //atribui null a sequencia para nao deixar
        if(*seq != NULL){
            return 0; //erro na exclusão da sequencia
        }
        return 1; //seqeuncia excluida com sucesso
    }
    return 0;
}
