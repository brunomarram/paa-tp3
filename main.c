#include <stdio.h>
#include <stdlib.h>

#include "file.h"

void menuSecundario(Piramide *piramide){
    int metodo;

    do {
        printf("\nDigite um metodo de resolucao\n\n");
        printf("1 - Recursivo\n");
        printf("2 - De tras pra frente\n");
        printf("3 - Memoization\n\n> ");
        scanf("%d", &metodo);
        getchar();
    } while (metodo != 1 && metodo != 2 && metodo != 3);

    if(metodo == 1)
        printf("Valor do maior caminho encontrado: %d\n", maximoRecursivo(piramide));
    else if(metodo == 2)
        maximoProgramacaoDinamica(piramide);
    else
        printf("Valor do maior caminho encontrado: %d\n", maximoMemoization(piramide));
}

void menuPrincipal() {
    int opc;
    Piramide piramide;

    system("clear");

    while (1) {
        do {
            system("clear");
            printf("Bem vindo ao Resolvedor de pirâmides\n\n");
            printf("Escolha um dos niveis abaixo:\n\n");
            printf("1 - Nivel 1\n");
            printf("2 - Nivel 2\n");
            printf("3 - Nivel 3\n");
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

        switch (opc) {
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

int main(int argc, char** argv) {
    menuPrincipal();
    return (EXIT_SUCCESS);
}

