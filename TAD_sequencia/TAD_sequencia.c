#include "TAD_sequencia.h"
#include "stdio.h"
#include "stdlib.h"

Sequencia *Create(int tamanho){
    Sequencia *seq;
    seq = (Sequencia *) malloc(sizeof(Sequencia)); //alocação da estrutura
    seq->dados = (int *) malloc(tamanho * sizeof(int)); //alocação do vetor
    seq->qtd = 0; //quantidade de elementos presentes no vetor, iniciado com o número 0 representando um vetor vazio
    seq->tamanho = tamanho; //declara o tamanho do vetor
    return seq; //retorna a sequencia criada
}

int Insert(Sequencia *seq, int dado){
    if(seq->qtd + 1 <= seq->tamanho){ //se a quantidade de elementos mais o adicionado for menor que o tamanho permitido
        seq->dados[seq->qtd] = dado; //adiciona o elemento ao vetor da sequencia
        seq->qtd++; //incrementa a quantidade de elementos dentro do vetor
        return 1; //retorna 1 para o inserção do vetor
    }
    return 0; //retorna 0 pois não pode inserir o elemento no vetor
}

int Remove(Sequencia *seq, int chave){
    int i, pos = -1;
    if(seq->dados[seq->qtd] == chave){ //se o ultimo elemento do vetor deve ser excluido, apenas atribui null
        seq->dados[seq->qtd] = NULL;
        seq->qtd--;
        return 1; //confirma a exclusão
    }else{
        for(i = 0; i < seq->qtd; i++){ //procura o elemento dentro do vetor para ser excluido
            if(seq->dados[i] == chave){
                pos = i;
                break; //quebra o laço
            }
        };
        if(pos >= 0){ //se encontrou o dado dentro do vetor, move todas as posições seguintes do vetor para a anterior
            for(i = pos; i < seq->qtd-1; i++){
                seq->dados[i] = seq->dados[i+1];
            }
            seq->dados[seq->qtd] = NULL;
            seq->qtd--;
            return 1;
        }
    }
    return 0;
}

int Search(Sequencia *seq, int chave){
    int i;
    for(i = 0; i < seq->qtd; i++){ //realiza a busca do elemento dentro do vetor da sequencia
        if(seq->dados[i] == chave) //caso ache o elemento retorna a posição do mesmo
            return i;
    }
    return -1;
}

int Destroy(Sequencia **seq){
    seq = NULL; //atribui null a sequencia para nao deixar
    if(seq != NULL){
        return 0; //erro na exclusão da sequencia
    }
    return 1; //seqeuncia excluida com sucesso
}
