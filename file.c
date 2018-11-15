#include "file.h"

int readFile(char *fileName, Piramide *piramide)
{
    FILE *file = NULL; // Arquivo TXT lido
    file = fopen(fileName, "r");

    int size = 0, i = 0, j = 0;
    char c;

    if (file == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else
        while ((c = fgetc(file)) != EOF)
            if (c == '\n')
                size++;
    
    piramide->size = size;
    alocaPiramide(piramide);
    
    file = fopen(fileName, "r");
    if (file == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    
    else
    {
        while ((c = fgetc(file)) != EOF)
        {
            if (c != ' ' && c != '\n')
            {
                piramide->matriz[i][j] = c - 48;
                j++;
            }
            else if (c == '\n')
            {
                j = 0;
                i++;
            }
        }
    }
    
    fclose(file);
    return 1;
}