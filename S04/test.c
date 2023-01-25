#include <stdint.h>
#include <string.h>
#include<stdlib.h>
#include"types_macros.h"
#include"image.h"

int main(int argc, char **argv)
{
    Image I;
    char fichier[100];
    strcpy(fichier, argv[1]);
    I = lire_fichier_image(fichier);
    ecrire_image(I);
}