
#include "piramide.h"

void alocaPiramide(Piramide *piramide){
    int size = piramide->size, i = 0;
    
    piramide->matriz = (int **) calloc(size, sizeof(int *));
    
    for(i = 0; i < size; i++)
        piramide->matriz[i] = (int *) calloc(size, sizeof(int));
}

void imprimePiramide(Piramide piramide){
    printf("|----- IMPRIMINDO PIRAMIDE -----|\n\n");
    int i = 0, j = 0;
    
    for(i = 0; i < piramide.size; i++){
        if(i % 2 == 0){
            for(int k = 0; k < (piramide.size - i) / 2; k++)
                printf("\t");    
        } else {
            for(int k = 0; k < (piramide.size - (i+1)) / 2; k++)
                printf("\t"); 
            printf("    ");
        }
        for(j = 0; j <= i; j++){
            if(i % 2 == 0)
                printf("%d\t", piramide.matriz[i][j]);
            else {
                printf("%d\t", piramide.matriz[i][j]);
                printf("    ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeSolucao(Piramide piramide){
    printf("|----- IMPRIMINDO SOLUCAO -----|\n\n");
    int i = 0, j = 0, k = 0, greaterI, greaterJ;
    
    for(i = 0; i < piramide.size; i++){
        if(i != piramide.size - 1){
            for(j = 0; j <= i; j++){
                if(j == 0){
                    greaterI = i;
                    greaterJ = j;
                } else if(piramide.matriz[i][j] > piramide.matriz[greaterI][greaterJ]){
                    greaterI = i;
                    greaterJ = j;
                }
            }                
        }
        
        if(i % 2 == 0){
            for(k = 0; k < (piramide.size - i) / 2; k++)
                printf("\t");    
        } else {
            for(int k = 0; k < (piramide.size - (i+1)) / 2; k++)
                printf("\t"); 
            printf("    ");
        }
        
        for(j = 0; j <= i; j++) {
            if(i % 2 == 0){
                if(piramide.matriz[i][j] == piramide.matriz[greaterI][greaterJ])
                    printf(ANSI_COLOR_GREEN "%d\t" ANSI_COLOR_WHITE, piramide.matriz[i][j]);
                else if(
                        piramide.matriz[i][j] == max(piramide.matriz[greaterI+1][greaterJ], 
                            piramide.matriz[greaterI+1][greaterJ+1]) &&
                        (j == greaterJ || j == greaterJ+1)
                )
                    printf(ANSI_COLOR_GREEN "%d\t" ANSI_COLOR_WHITE, piramide.matriz[i][j]);
                else
                    printf("%d\t", piramide.matriz[i][j]);                
            } else {
                if(piramide.matriz[i][j] == piramide.matriz[greaterI][greaterJ])
                    printf(ANSI_COLOR_GREEN "%d\t" ANSI_COLOR_WHITE, piramide.matriz[i][j]);
                else if(
                        piramide.matriz[i][j] == max(piramide.matriz[greaterI+1][greaterJ], 
                            piramide.matriz[greaterI+1][greaterJ+1]) &&
                        (j == greaterJ || j == greaterJ+1)
                )
                    printf(ANSI_COLOR_GREEN "%d\t" ANSI_COLOR_WHITE, piramide.matriz[i][j]);
                else
                    printf("%d\t", piramide.matriz[i][j]);  
                printf("    ");
            }
        }
        printf("\n");
    }
    printf("\n");    
}

int max(int i, int j){
    if(i > j) return i;
    else return j;
}

int maximoRecursivoAux(Piramide *piramide, int i, int j) {
    if(i == piramide->size - 1)
        return piramide->matriz[i][j];
    else
        return piramide->matriz[i][j] + 
                max(maximoRecursivoAux(piramide, i+1, j), 
                    maximoRecursivoAux(piramide, i+1, j+1));
}

int maximoRecursivo(Piramide *piramide){
    return maximoRecursivoAux(piramide, 0, 0);
}

void maximoProgramacaoDinamica(Piramide *piramide) {
    int i = piramide->size - 1, j = 0;
    Piramide solucao;
    solucao.size = piramide->size;
    alocaPiramide(&solucao);
    for(j = 0; j <= i; j++)
        solucao.matriz[i][j] = piramide->matriz[i][j];
    while(i >= 0){
        i--;
        for(j = 0; j <= i; j++) {
            solucao.matriz[i][j] = piramide->matriz[i][j] + 
                    max(solucao.matriz[i+1][j], solucao.matriz[i+1][j+1]);
        }
    }
    imprimeSolucao(solucao);
}

int memo(Hash *tabela, Piramide *piramide, int i, int j){

    insereHash(tabela, maximoMemoizationAux(tabela, piramide, i, j));
//    printf("%d, %d \n", , piramide->matriz[i][j]);
    return buscaHash(tabela, piramide->matriz[i][j]);
}

int maximoMemoizationAux(Hash *tabela, Piramide *piramide, int i, int j){
    if(i == piramide->size - 1)
        return piramide->matriz[i][j];
    else
        return piramide->matriz[i][j] + 
                max(memo(tabela, piramide, i+1, j), 
                    memo(tabela, piramide, i+1, j+1));    
}

int maximoMemoization(Piramide *piramide) {
    Hash tabela;
    inicializaHash(tabela);
    return maximoMemoizationAux(&tabela, piramide, 0, 0);
}