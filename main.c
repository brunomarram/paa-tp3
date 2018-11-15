#include <stdio.h>
#include <stdlib.h>

#include "file.h"

int main(int argc, char** argv) {
    Piramide piramide;
    readFile("piramide1.txt", &piramide);
//    imprimePiramide(piramide);
//    maximoProgramacaoDinamica(&piramide);
    
//    readFile("piramide1.txt", &piramide);
//    printf("%d ", maximoRecursivo(&piramide));
    
    imprimePiramide(piramide);
    printf("%d", maximoMemoization(&piramide));
    maximoProgramacaoDinamica(&piramide);
    return (EXIT_SUCCESS);
}

