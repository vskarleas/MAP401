#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

/* Test de verification de la methode de simplification par segments */
int main(int argc, char **argv)
{
    printf("Enter the name of the image's file without any extension (pbm)\n");
    char name[256];
    scanf("%s", name);
    double d;
    printf("D=");
    scanf("%lf", &d);
    printf("\n");

    char *fichier=malloc(strlen(name)+4);
    char exit_file[(strlen(name)+20)];
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    if (d != 0.5)
    {
        snprintf(exit_file, (strlen(name)+20), "%s-simp-taille%.0f.txt", name, d );
    }
    else
    {
        snprintf(exit_file, (strlen(name)+20), "%s-simp-taille%.0f-5.txt", name, d );
    }
    
    Image I;
    I = lire_fichier_image(fichier);

    Liste_Contours liste;
    liste = creer_liste_Contours_vide();
    liste = algo_contours(I);
    contours_data(liste);
    printf("\n");
    printf("\n");

    Liste_Contours simple;
    simple = creer_liste_Contours_vide();
    Contour el;
    el = creer_liste_Point_vide();

    Cellule_Liste_Contours *al;
    al = liste.first;
    while (al != NULL)
    {
        Tableau_Point T = sequence_points_liste_vers_tableau(al->data);
        //Simplification par segments
        el = simplification_douglas_peucker(T, 0,(T.taille)-1, d);
        ajouter_element_liste_Contours(&simple, el);
        al = al->suiv;
    }


    ecrire_fichier_contours(simple, exit_file);
    contours_data_simplification(simple);
    create_postscript_contours(simple, exit_file, hauteur_image(I), largeur_image(I)); //Mode remplisage only
    printf("================================================");
    return 0;

}
