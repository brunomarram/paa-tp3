
#include "piramide.h"

void alocaPiramide(Piramide *piramide)
{
    int size = piramide->size, i = 0;

    piramide->matriz = (int **)calloc(size, sizeof(int *));

    for (i = 0; i < size; i++)
        piramide->matriz[i] = (int *)calloc(size, sizeof(int));
}

void imprimePiramide(Piramide piramide)
{
    printf("|----- IMPRIMINDO PIRAMIDE -----|\n\n");
    int i = 0, j = 0;

    for (i = 0; i < piramide.size; i++)
    {
        if (i % 2 == 0)
        {
            for (int k = 0; k < (piramide.size - i) / 2; k++)
                printf("\t");
        }
        else
        {
            for (int k = 0; k < (piramide.size - (i + 1)) / 2; k++)
                printf("\t");
            printf("    ");
        }
        for (j = 0; j <= i; j++)
        {
            if (i % 2 == 0)
                printf("%d\t", piramide.matriz[i][j]);
            else
            {
                printf("%d\t", piramide.matriz[i][j]);
                printf("    ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeSolucao(Piramide piramide)
{
    printf("|----- IMPRIMINDO SOLUCAO -----|\n\n");
    int i = 0, j = 0, k = 0, greater = piramide.matriz[i][j], fim = 0;

    for (i = 0; i < piramide.size; i++)
    {
        if (i % 2 == 0)
        {
            for (k = 0; k < (piramide.size - i) / 2; k++)
                printf("\t");
        }
        else
        {
            for (int k = 0; k < (piramide.size - (i + 1)) / 2; k++)
                printf("\t");
            printf("    ");
        }

        for (j = 0; j <= i; j++)
        {
            if (piramide.matriz[i][j] == greater && !fim)
            {
                printf(ANSI_COLOR_GREEN "%d\t" ANSI_COLOR_WHITE, piramide.matriz[i][j]);
                if (i != piramide.size - 1)
                    greater = max(piramide.matriz[i + 1][j],
                                  piramide.matriz[i + 1][j + 1]);
                else
                    fim = 1;
            }
            else
                printf("%d\t", piramide.matriz[i][j]);

            if (i % 2 != 0)
                printf("    ");
        }
        printf("\n");
    }
    printf("\n");
}

int max(int i, int j)
{
    if (i > j)
        return i;
    else
        return j;
}

int maximoRecursivoAux(Piramide *piramide, int i, int j)
{
    if (i == piramide->size - 1)
        return piramide->matriz[i][j];
    else
        return piramide->matriz[i][j] +
               max(maximoRecursivoAux(piramide, i + 1, j),
                   maximoRecursivoAux(piramide, i + 1, j + 1));
}

int maximoRecursivo(Piramide *piramide)
{
    int max = maximoRecursivoAux(piramide, 0, 0);
    printf("Valor do maior caminho encontrado: %d\n", max);
    return max;
}

void maximoTrasPraFrente(Piramide *piramide)
{
    int i = piramide->size - 1, j = 0;
    Piramide solucao;
    solucao.size = piramide->size;
    alocaPiramide(&solucao);
    for (j = 0; j <= i; j++)
        solucao.matriz[i][j] = piramide->matriz[i][j];
    while (i >= 0)
    {
        i--;
        for (j = 0; j <= i; j++)
        {
            solucao.matriz[i][j] = piramide->matriz[i][j] +
                                   max(solucao.matriz[i + 1][j], solucao.matriz[i + 1][j + 1]);
        }
    }
    imprimeSolucao(solucao);
}

int maximoMemoizationAux(Piramide *tabela, Piramide *piramide, int i, int j)
{
    if (i == piramide->size - 1)
        return piramide->matriz[i][j];
    else
    {
        if (tabela->matriz[i][j])
            return tabela->matriz[i][j];
        else
        {
            tabela->matriz[i][j] = piramide->matriz[i][j] +
                                   max(maximoMemoizationAux(tabela, piramide, i + 1, j),
                                       maximoMemoizationAux(tabela, piramide, i + 1, j + 1));
            return tabela->matriz[i][j];
        }
    }
}

int maximoMemoization(Piramide *piramide)
{
    Piramide solucao;
    solucao.size = piramide->size;
    alocaPiramide(&solucao);
    int max = maximoMemoizationAux(&solucao, piramide, 0, 0);
    printf("Valor do maior caminho encontrado: %d\n", max);
    return max;
}