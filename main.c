#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "file.h"

void menuSecundario(Piramide *piramide, int analise)
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

    clock_t inicio;
    inicio = clock();

    if (metodo == 1)
        maximoRecursivo(piramide);
    else if (metodo == 2)
        maximoTrasPraFrente(piramide);
    else
        maximoMemoization(piramide);

    double tempo = (clock() - inicio) * 1000.0 / (double)CLOCKS_PER_SEC;

    if (analise)
        printf("Tempo de execucao: %lf ms\n\n", tempo);
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
            printf("Historia: \n");
            printf("Menkauré foi um rei da IV dinastia egípcia. Em português, é também conhecido como Miquerinos, que é oriundo da versão helenizada do seu nome. Menkauré significa 'estaveis são os kau de Ré' (sendo kau o plural de ka, elemento constituinte do ser humano na mentalidade egípcia).\nEra filho de Khafré (também conhecido como Quéfren, rei da segunda pirâmide de Gizé) e da rainha Khamerernebti I. Foi casado com a sua irmã Khamerernebti II, tendo tido mais duas esposas. Mikerinos teve pelo menos dois filhos do sexo masculino: um faleceu e o outro, Chepseskaf, foi o seu sucessor.\n\n");
            menuSecundario(&piramide, analise);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 2:
            system("clear");
            readFile("piramide2.txt", &piramide);
            imprimePiramide(piramide);
            printf("Historia: \n");
            printf("Quéfren foi um faraó egipcio da quarta dinastia. Ele construiu a segunda maior das pirâmides de Gizé, a Pirâmide de Quéfren, a Esfínge de Gizé e um templo, que é o único exemplo de templo remanescente do período do Antigo Império egípcio. Seu nome, Khaf-Re, significa 'da coroa de Rá' para alguns tradutores e 'suba Ra !' para outros; o significado mais provável é o primeiro, por os hieróglifos representando seu nome possuem tal coroa.\n\n");
            menuSecundario(&piramide, analise);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 3:
            system("clear");
            readFile("piramide3.txt", &piramide);
            imprimePiramide(piramide);
            printf("Historia: \n");
            printf("Quéops foi um faraó do Antigo Império do Egito antigo. Ele reinou por volta de de 2551 a.C. a 2528 a.C.. Foi o segundo faraó da Quarta dinastia. Quéops foi filho do Rei Snefru e, ao contrário de seu pai, foi lembrado como um faraó cruel e sem piedade. Quéops teve diversos filhos, um dos quais, Djedefré, foi seu sucessor imediato. Ele teve uma filha chamada Rainha Hetepheres II.\n\n");
            menuSecundario(&piramide, analise);
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
    if (strcmp(argv[1], "analysis") == 0)
        menuPrincipal(1);
    else
        menuPrincipal(0);
    return (EXIT_SUCCESS);
}
