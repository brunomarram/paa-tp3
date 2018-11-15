#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash.h"

/*funcaoHash  recebe como parametro uma variavel do tipo inteiro(num),
retorna a  restra da divisao do valor dessa variavel pela tamanho da tabela*/
int funcaoHash(int num) {
    return (num % tam);
}

/*O procedimento inicializaHash recebe como parametro uma variavel do tipo
 Hash e sua funcao e que todas as posicoes da tab se tornem nulas*/
void inicializaHash(Hash tab) {
    int i;
    for (i = 0; i < tam; i++) {
        tab[i] = NULL;
    }
}

/*O procedimento insererHash recebe como parametro dois argumentos uma
variavel do tipo Hash e outra do tipo num. Sua funcao e inserir os elementos
na tabela atraveis da funcaoHash e caso esta posicao ja esteja preenchida,
como colisao esta sendo adotado neste procedimento o encadeamento direto.*/
void insereHash(Hash tab, int num) {
    int i = 0;
    int chave = funcaoHash(num);
    Dados* aux = tab[chave];
    while (aux != NULL) {
        if (aux->info == num) {
            break;
        }
        aux = aux->prox;
    }
    if (aux == NULL) {
        aux = (Dados*) malloc(sizeof (Dados));
        aux->info = num;
        aux->prox = tab[chave];
        tab[chave] = aux;
    }
}

/*O procedimento buscaHash recebe como parametro duas variaveis uma do
tipo Hash(tab) e outra do tipo inteiro(num),A variavel tab tem como funcao
 passar a tabela e a variavel num tem como funcao determinar a posicao da
 tabela que o usuario deseja visualizar*/
int buscaHash(Hash tab, int num) {
    int pos = num;
    if (num > tam || num < 0) {
        printf("\nPosicao nao encontrada!");
    } else {
        return imprimeColisao(tab, pos);
        Dados* aux = tab[pos];
        if (aux == NULL)
            return 0;
        
        if(aux->info == num)
            return aux->info;
        
        while (aux->prox != NULL) {
            if(aux->info == num)
                return aux->info;
            aux = aux->prox;
        }
    }
    return 0;
}

/*O procedimento imprimeColisaon mostra uma posicao
e todas as suas colisoes.*/
int imprimeColisao(Hash tab, int pos) {
    Dados* aux = tab[pos];
    if (aux == NULL) {
        return 0;
    } else {
        if (aux != NULL) {
            return aux->info;
            while (aux->prox != NULL) {
                printf(" -> %d", aux->prox->info);
                aux = aux->prox;
            }
        }
    }
}

/*O procedimento imprimeHash recebe como parametro uma variavel do tipo Hash.
Sua funcao e imprimir todos os elementos da variavel do tipo Hash*/
void imprimeHash(Hash tab) {
    int i = 0, cont = 0;
    for (i = 0; i < tam; i++) {
        if (tab[i] != NULL) {
            printf("\n %d", tab[i]->info);
            Dados* aux = tab[i]->prox;
            while (aux != NULL) {
                printf(" -> %3d", aux->info);
                aux = aux->prox;
            }
        }
    }
}