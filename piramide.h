#define ANSI_COLOR_RED "\e[1;31m"
#define ANSI_COLOR_GREEN "\e[1;32m"
#define ANSI_COLOR_WHITE "\e[0m"

#include "hash.h"

typedef struct Piramide{
    int size;
    int **matriz;
}Piramide;

void alocaPiramide(Piramide *piramide);
void imprimePiramide(Piramide piramide);
void imprimeSolucao(Piramide piramide);
int maximoRecursivo(Piramide *piramide);
void maximoProgramacaoDinamica(Piramide *piramide);
int maximoMemoization(Piramide *piramide);