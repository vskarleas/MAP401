#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    //Test no 10
    printf("Starting Test 10\n");
    printf("Enter the name of the image's file without any extension (pbm)\n");
    char name[256];
    scanf("%s", name);

    char *fichier=malloc(strlen(name)+4);
    char *exit_file=malloc(strlen(name)+17);
    strcpy(fichier,name);
    strcat(fichier,".pbm");

    strcpy(exit_file,name);
    strcat(exit_file,"-deg2-taille1.txt");

    char *exit_file2=malloc(strlen(name)+17);
    strcpy(exit_file2,name);
    strcat(exit_file2,"-deg2-taille2.txt");

    char *exit_file10=malloc(strlen(name)+18);
    strcpy(exit_file10,name);
    strcat(exit_file10,"-deg2-taille10.txt");

    char *exit_file30=malloc(strlen(name)+18);
    strcpy(exit_file30,name);
    strcat(exit_file30,"-deg2-taille30.txt");
    
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
        el = simplification_douglas_peucker_bezier2(al->data, 0,(T.taille)-1, 1);
        ajouter_element_liste_Contours(&simple, el);
        al = al->suiv;
    }

    ecrire_fichier_contours(simple, exit_file);
    contours_data_simplification(simple);
    create_postscript_contours_bezier2(simple, exit_file, hauteur_image(I), largeur_image(I)); //Mode remplisage only
    printf("================================================");

    printf("\n");

    printf("d = 3\n");
    Liste_Contours simple2;
    simple2 = creer_liste_Contours_vide();
    Contour el2;
    el2 = creer_liste_Point_vide();

    Cellule_Liste_Contours *al2;
    al2 = liste.first;
    while (al2 != NULL)
    {
        Tableau_Point T2 = sequence_points_liste_vers_tableau(al2->data);
        el2 = simplification_douglas_peucker_bezier2(al2->data, 0,(T2.taille)-1, 3);
        ajouter_element_liste_Contours(&simple2, el2);
        al2 = al2->suiv;
    }


    ecrire_fichier_contours(simple2, exit_file2);
    contours_data_simplification(simple2);
    create_postscript_contours_bezier2(simple2, exit_file2, hauteur_image(I), largeur_image(I)); //Mode remplisage only

    printf("Text file should have been written with title %s\n", exit_file); //The file is handled on the algo_contour function
    printf("=====================\n");

    printf("================================================");

    printf("\n");

    printf("d = 10\n");
    Liste_Contours simple10;
    simple10 = creer_liste_Contours_vide();
    Contour el10;
    el10 = creer_liste_Point_vide();

    Cellule_Liste_Contours *al10;
    al10 = liste.first;
    while (al10 != NULL)
    {
        Tableau_Point T2 = sequence_points_liste_vers_tableau(al10->data);
        el10 = simplification_douglas_peucker_bezier2(al10->data, 0,(T2.taille)-1, 10);
        ajouter_element_liste_Contours(&simple10, el10);
        al10 = al10->suiv;
    }


    ecrire_fichier_contours(simple10, exit_file10);
    contours_data_simplification(simple10);
    create_postscript_contours_bezier2(simple10, exit_file10, hauteur_image(I), largeur_image(I)); //Mode remplisage only

    printf("Text file should have been written with title %s\n", exit_file); //The file is handled on the algo_contour function
    printf("=====================\n");

    printf("================================================");

    printf("\n");

    printf("d = 30\n");
    Liste_Contours simple30;
    simple30 = creer_liste_Contours_vide();
    Contour el30;
    el2 = creer_liste_Point_vide();

    Cellule_Liste_Contours *al30;
    al30 = liste.first;
    while (al30 != NULL)
    {
        Tableau_Point T2 = sequence_points_liste_vers_tableau(al30->data);
        el30 = simplification_douglas_peucker_bezier2(al30->data, 0,(T2.taille)-1, 30);
        ajouter_element_liste_Contours(&simple30, el30);
        al30 = al30->suiv;
    }


    ecrire_fichier_contours(simple30, exit_file30);
    contours_data_simplification(simple30);
    create_postscript_contours_bezier2(simple30, exit_file30, hauteur_image(I), largeur_image(I)); //Mode remplisage only

    printf("Text file should have been written with title %s\n", exit_file); //The file is handled on the algo_contour function
    printf("=====================\n");
    return 0;

}
