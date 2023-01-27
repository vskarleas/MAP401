#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    if (argc!=2)
    {
        printf("Image file is missing as argument. Please give an image path as argument and try again.\n");
        exit(-2);
    }
    //Test no 4
    printf("Test 4\n");
    Image I;
    char fichier[100];
    strcpy(fichier, argv[1]);
    I = lire_fichier_image(fichier);
    ecrire_image(I);

    printf("=====================\n");
    printf("Test du contour\n");
    printf("=====================\n");
    Contour k;
    k = algo_contour(I);
    ecrire_contour(k);
    return 0;

}
