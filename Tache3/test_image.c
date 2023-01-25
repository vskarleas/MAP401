#include <stdint.h>
#include <string.h>
#include<stdlib.h>
#include"types_macros.h"
#include"image.h"

int main(int argc, char **argv)
{
    //Test no 1
    printf("Test 1\n");
    Image I;
    char fichier[100];
    strcpy(fichier, argv[1]);
    I = lire_fichier_image(fichier);
    ecrire_image(I);

    printf("\n");
    //Test no 2
    Image neg;
    printf("Test 2\n");
    neg = negatif_image(I);
    ecrire_image(neg);

    return 0;
}