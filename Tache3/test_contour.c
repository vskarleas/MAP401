#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    if (argc!=3)
    {
        printf("Image file or/and fexit are missing as arguments. Please give the path of appropriate files and try again.\n");
        exit(-2);
    }
    //Test no 4
    printf("Test 4\n");
    Image I;
    char fichier[256];
    char exit_file[256];
    strcpy(fichier, argv[1]);
    strcpy(exit_file, argv[2]);

    I = lire_fichier_image(fichier);
    ecrire_image(I);

    printf("=====================\n");
    printf("Test du contour\n");
    printf("=====================\n");
    Contour k;
    k = algo_contour(I, exit_file, 1); //1 here will be controlled from a variable on Tache 5 where more contpurs are required to be added on the same file
    ecrire_contour(k); //Printing concours on the terminal
    printf("=====================\n");
    printf("Text file should have been written\n"); //The file is handled on the algo_contour function
    //We could definitely pass the FILE ready from here, but there was an issue with the file's signatures for access
    printf("=====================\n");
    return 0;

}
