#include <stdio.h>
#include <stdlib.h>

#include "file.h"

void menuSecundario(Piramide *piramide)
{
    int metodo;

    do
    {
        printf("\nDigite um metodo de resolucao\n\n");
        printf("1 - Recursivo\n");
        printf("2 - De tras pra frente\n");
        printf("3 - Memoization\n\n> ");
        scanf("%d", &metodo);
        getchar();
    } while (metodo != 1 && metodo != 2 && metodo != 3);

    if (metodo == 1)
        maximoRecursivo(piramide);
    else if (metodo == 2)
        maximoTrasPraFrente(piramide);
    else
        maximoMemoization(piramide);
}

void menuPrincipal(int analise)
{
    int opc;
    Piramide piramide;

    system("clear");

    while (1)
    {
        do
        {
            system("clear");
            if (analise)
                printf("Bem vindo ao Resolvedor das piramides de Gize (Modo Analise)\n\n");
            else
                printf("Bem vindo ao Resolvedor das piramides de Gize\n\n");
            printf("Escolha um dos niveis abaixo:\n\n");
            printf("1 - Miquerinos\n");
            printf("2 - Quefren\n");
            printf("3 - Queops (Grande Piramide)\n");
            printf("0 - Sair\n\n");
            printf("> ");
            scanf("%d", &opc);
            if (opc < 0 || opc > 3)
            {
                printf("Opção inválida\n");
                printf("Pressione enter para continuar...");
                getchar();
            }
        } while (opc < 0 || opc > 3);

        switch (opc)
        {
        case 1:
            system("clear");
            readFile("piramide1.txt", &piramide);
            imprimePiramide(piramide);
            menuSecundario(&piramide);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 2:
            system("clear");
            readFile("piramide2.txt", &piramide);
            imprimePiramide(piramide);
            menuSecundario(&piramide);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 3:
            system("clear");
            readFile("piramide3.txt", &piramide);
            imprimePiramide(piramide);
            menuSecundario(&piramide);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 0:
            system("clear");
            printf("Até mais :)\n\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
        }

        if (opc == 0)
            break;
    }
}

int main(int argc, char **argv)
{
    menuPrincipal(0);
    return (EXIT_SUCCESS);
}
