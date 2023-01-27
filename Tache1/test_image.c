#include <stdint.h>
#include <string.h>
#include<stdlib.h>
#include"types_macros.h"
#include"image.h"

int main(int argc, char **argv)
{
    if (argc!=2)
    {
        printf("Image file is missing as argument. Please give an image path as argument and try again.\n");
        exit(-2);
    }
    //Test no 1
    printf("==========\n");
    printf("Test 1\n");
    printf("==========\n");
    Image I;
    char fichier[100];
    strcpy(fichier, argv[1]);
    I = lire_fichier_image(fichier);
    ecrire_image(I);

    printf("\n");
    printf("\n");
    //Test no 2
    Image neg;
    printf("==========\n");
    printf("Test 2\n");
    printf("==========\n");
    neg = negatif_image(I);
    ecrire_image(neg);

    return 0;
}