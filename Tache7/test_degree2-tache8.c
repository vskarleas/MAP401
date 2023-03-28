#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    printf("Enter the name of the image's file without any extension (pbm)\n");
    char name[256];
    double d = 0.0;
    scanf("%s", name);
    printf("D=\n");
    scanf("%lf", &d);

    char *fichier=malloc(strlen(name)+4);
    char exit_file[(strlen(name)+20)];
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    snprintf(exit_file, (strlen(name)+20), "%s-deg3-taille%.0f.txt", name, d );

    
    
    Image I;
    I = lire_fichier_image(fichier);

    Liste_Contours liste;
    liste = creer_liste_Contours_vide();
    liste = algo_contours(I);
    contours_data(liste);
    printf("\n");
    printf("\n");

    printf("================================================\n");
    Liste_Contours simple;
    simple = creer_liste_Contours_vide();
    Contour el;
    el = creer_liste_Point_vide();

    Cellule_Liste_Contours *al;
    al = liste.first;
    while (al != NULL)
    {
        Tableau_Point T = sequence_points_liste_vers_tableau(al->data);
        el = simplification_douglas_peucker_bezier2(al->data, 0,(T.taille)-1, d);
        ajouter_element_liste_Contours(&simple, el);
        al = al->suiv;
    }

    contours_data_bezier(simple);
    create_postscript_contours_bezier2(simple, exit_file, hauteur_image(I), largeur_image(I)); //Mode remplisage only

    printf("\n");

    return 0;

}
