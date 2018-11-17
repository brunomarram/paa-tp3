#define ANSI_COLOR_RED "\e[1;31m"
#define ANSI_COLOR_GREEN "\e[1;32m"
#define ANSI_COLOR_WHITE "\e[0m"

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Piramide{
    int size;
    int **matriz;
}Piramide;

void alocaPiramide(Piramide *piramide);
void imprimePiramide(Piramide piramide);
void imprimeSolucao(Piramide piramide);
int max(int i, int j);
int maximoRecursivo(Piramide *piramide);
void maximoProgramacaoDinamica(Piramide *piramide);
int maximoMemoizationAux(Hash *tabela, Piramide *piramide, int i, int j);
int maximoMemoization(Piramide *piramide);