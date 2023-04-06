#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    //Test no 6
    /* Test de verification que l'image mask est correct */
    printf("Starting Test 6\n");
    printf("Enter the name of the image's file without any extension (pbm)\n");
    char name[256];
    scanf("%s", name);

    char *fichier=malloc(strlen(name)+4);
    char *exit_file=malloc(strlen(name)+4);
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    strcpy(exit_file,name);
    strcat(exit_file,".txt");
    
    Image I;
    I = lire_fichier_image(fichier);
    ecrire_image(I);

    printf("=====================\n");
    printf("Test du mask de l'image\n");
    printf("=====================\n");
    Image mask;
    mask = mask_image(I);
    ecrire_image(mask);


    //Test no 7
    /* Test de verifications que la lecture des multiples contours ainsi que la creation du postscript des multiples contours marche aussi */
    printf("Starting Test 7\n");
    printf("=====================\n");
    printf("Test du multiple contours de l'image:\n");
    Liste_Contours liste;
    liste = creer_liste_Contours_vide();
    liste = algo_contours(I);
    ecrire_fichier_contours(liste, exit_file);
    contours_data(liste);
    create_postscript_contours(liste, exit_file, hauteur_image(I), largeur_image(I)); //Mode remplisage only

    printf("Text file should have been written with title %s\n", exit_file); //The file is handled on the algo_contour function
    printf("=====================\n");
    return 0;

}
