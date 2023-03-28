#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    //Test de robusteuse pour zebres-4000x3000
    printf("Test pour zebres-4000x3000\n");
    char name[256] = "zebres-4000x3000";

    char *fichier=malloc(strlen(name)+4);
    char *exit_file=malloc(strlen(name)+17);
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    strcpy(exit_file,name);
    strcat(exit_file,"-simp-taille1.txt");

     char *image_file=malloc(strlen(name)+4);
    strcpy(image_file,name);
    strcat(image_file,".eps");
    
    Image I;
    I = lire_fichier_image(fichier);

    Liste_Contours liste;
    liste = creer_liste_Contours_vide();
    liste = algo_contours(I);
    contours_data(liste);
    create_postscript_contours(liste, image_file, hauteur_image(I), largeur_image(I)); //Mode remplisage only
    printf("\n");
    printf("\n");

    printf("d = 0\n");
    Liste_Contours simple;
    simple = creer_liste_Contours_vide();
    Contour el;
    el = creer_liste_Point_vide();

    Cellule_Liste_Contours *al;
    al = liste.first;
    while (al != NULL)
    {
        Tableau_Point T = sequence_points_liste_vers_tableau(al->data);
        el = simplification_douglas_peucker(al->data, 0,(T.taille)-1, 0);
        ajouter_element_liste_Contours(&simple, el);
        al = al->suiv;
    }


    ecrire_fichier_contours(simple, exit_file);
    contours_data_simplification(simple);
    create_postscript_contours(simple, exit_file, hauteur_image(I), largeur_image(I)); //Mode remplisage only
    printf("================================================");

    printf("\n");
    return 0;

}
