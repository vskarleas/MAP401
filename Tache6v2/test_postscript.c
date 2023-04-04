#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("No arguments are required for this test\n");
        exit(-2);
    }
    // Test no 5
    printf("Starting Test 5\n");
    Image I;
    printf("Enter the name of the image's file without any extension (pbm)\n");
    char name[256];
    scanf("%s", name);
    printf("Enter 1[stroke] or 2[fill]\n");
    int id;
    int res = 0;
    scanf("%d", &id);

    while (res >= 0)
    {
        if (id == 1 || id == 2)
        {
            res = -1;
        }
        else
        {
            printf("Please type 1 for [stroke] or 2 for [fill]\n");
            scanf("%d", &id);
            res++;
        }
    }

    char *fichier = malloc(strlen(name) + 4);
    char *exit_file = malloc(strlen(name) + 4);
    strcpy(fichier, name);
    strcat(fichier, ".pbm");

    strcpy(exit_file, name);
    strcat(exit_file, ".txt");

    I = lire_fichier_image(fichier);
    ecrire_image(I);

    printf("=====================\n");
    printf("Test du PostScript\n");
    printf("=====================\n");
    Contour k;
    k = algo_contour(I, exit_file); // 1 here will be controlled from a variable on Tache 5 where more contpurs are required to be added on the same file
    if (id == 1)
    {
        create_postscript(k, exit_file, hauteur_image(I), largeur_image(I));
        printf("Text files should have been written with title %s.txt and %s.eps in mode stroke\n", name, name);
    }
    else
    {
        create_postscript_fill(k, exit_file, hauteur_image(I), largeur_image(I));
        printf("Text files should have been written with title %s.txt and %s.eps in mode fill\n", name, name);
    }
    printf("=====================\n");

    // Test no 5
    return 0;
}
