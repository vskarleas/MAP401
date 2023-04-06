#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

/* Verifier que la simplifcation par courbe bezier des degrees 3 */
int main(int argc, char **argv)
{
    printf("Enter the name of the image's file without any extension (pbm)\n");
    char name[256];
    double d = 0.0;
    scanf("%s", name);
    //Distance seuil passe en terminal
    printf("D=");
    scanf("%lf", &d);
    printf("\n");

    char *fichier=malloc(strlen(name)+4);
    char exit_file[(strlen(name)+20)];
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    //Automatic traitment of output files (eps and txt)
    if (d != 0.5)
    {
        snprintf(exit_file, (strlen(name)+20), "%s-deg3-taille%.0f.txt", name, d );
    }
    else
    {
        snprintf(exit_file, (strlen(name)+20), "%s-deg3-taille%.0f-5.txt", name, d );
    }
    
    
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
        el = simplification_douglas_peucker_bezier3(al->data, 0,(T.taille)-1, d);
        ajouter_element_liste_Contours(&simple, el);
        al = al->suiv;
    }

    //Affichage des donnes apres la simplification 
    contours_data_bezier3(simple);
    create_postscript_contours_bezier3(simple, exit_file, hauteur_image(I), largeur_image(I)); //Mode remplisage only

    printf("\n");

    return 0;

}
