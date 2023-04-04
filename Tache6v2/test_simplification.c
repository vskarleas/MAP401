#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    //Test no 8
    printf("Starting Test 8\n");
    printf("Enter the name of the image's file without any extension (pbm)\n");
    char name[256];
    scanf("%s", name);

    char *fichier=malloc(strlen(name)+4);
    char *exit_file=malloc(strlen(name)+17);
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    strcpy(exit_file,name);
    strcat(exit_file,"-simp-taille1.txt");

    char *exit_file2=malloc(strlen(name)+17);
    strcpy(exit_file2,name);
    strcat(exit_file2,"-simp-taille2.txt");
    
    Image I;
    I = lire_fichier_image(fichier);

    Liste_Contours liste;
    liste = creer_liste_Contours_vide();
    liste = algo_contours(I);
    contours_data(liste);
    printf("\n");
    printf("\n");

    printf("d = 1\n");
    Liste_Contours simple;
    simple = creer_liste_Contours_vide();
    Contour el;
    el = creer_liste_Point_vide();

    Cellule_Liste_Contours *al;
    al = liste.first;
    while (al != NULL)
    {
        Tableau_Point T = sequence_points_liste_vers_tableau(al->data);
        el = simplification_douglas_peucker(T, 0,(T.taille)-1, 1);
        ajouter_element_liste_Contours(&simple, el);
        al = al->suiv;
    }


    ecrire_fichier_contours(simple, exit_file);
    contours_data_simplification(simple);
    create_postscript_contours(simple, exit_file, hauteur_image(I), largeur_image(I)); //Mode remplisage only
    printf("================================================");

    printf("\n");

    printf("d = 2\n");
    Liste_Contours simple2;
    simple2 = creer_liste_Contours_vide();
    Contour el2;
    el2 = creer_liste_Point_vide();

    Cellule_Liste_Contours *al2;
    al2 = liste.first;
    while (al2 != NULL)
    {
        Tableau_Point T2 = sequence_points_liste_vers_tableau(al2->data);
        el2 = simplification_douglas_peucker(T2, 0,(T2.taille)-1, 2);
        ajouter_element_liste_Contours(&simple2, el2);
        al2 = al2->suiv;
    }


    ecrire_fichier_contours(simple2, exit_file2);
    contours_data_simplification(simple2);
    create_postscript_contours(simple2, exit_file2, hauteur_image(I), largeur_image(I)); //Mode remplisage only

    printf("Text file should have been written with title %s\n", exit_file); //The file is handled on the algo_contour function
    printf("=====================\n");
    return 0;

}
