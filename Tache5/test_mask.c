#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    //Test no 6
    printf("Starting Test 6\n");
    printf("Enter the name of the image's file without any extension (pbm)\n");
    char name[256]="test3";

    char *fichier=malloc(strlen(name)+4);
    //char *exit_file=malloc(strlen(name)+4);
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    //strcpy(exit_file,name);
    //strcat(exit_file,".txt");
    
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
    printf("Starting Test 7\n");
    printf("=====================\n");
    printf("Test du multiple contours de l'image\n");
    printf("=====================\n");
    Liste_Contours liste;
    liste = creer_liste_Contours_vide();
    liste = algo_contours(I);

    Cellule_Liste_Contours *el;
    el = liste.first;
    int id =1;
    while (el!=NULL)
    {
        printf("========= %d =========\n", id);
        Tableau_Point TP = sequence_points_liste_vers_tableau(el->data);
        int k;
        int nP = TP.taille;
        printf("%d\n", nP);
        for (k = 0; k < nP; k++)
        {
            Point P = TP.tab[k];
            printf("%.1f %.1f\n", P.x, P.y);
        }
        free(TP.tab);
        id++;
        printf("======================\n");
        printf("----------------------\n");
        printf("======================\n");
        el = el->suiv;
    }

    
   // Contour k;
    //k = algo_contour(I, exit_file); //1 here will be controlled from a variable on Tache 5 where more contpurs are required to be added on the same file
    //printf("=====================\n");
    //printf("Text file should have been written with title %s\n", exit_file); //The file is handled on the algo_contour function
    //printf("=====================\n");
    return 0;

}
