#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "geom2d.h"
#include "contour.h"
#include "image.h"

void init_robot(Robot *r, int x, int y, Orientation o)
{
    r->x = x;
    r->y = y;
    r->o = o;
}

/* faire avancer le robot d'une case */
void avancer(Robot *r)
{
    switch (r->o)
    {
    case Nord:
        r->y--;
        break;
    case Sud:
        r->y++;
        break;
    case Ouest:
        r->x--;
        break;
    case Est:
        r->x++;
    }
}

/* faire tourner le robot à gauche */
void tourner_a_gauche(Robot *r)
{
    switch (r->o)
    {
    case Nord:
        r->o = Ouest;
        break;
    case Ouest:
        r->o = Sud;
        break;
    case Sud:
        r->o = Est;
        break;
    case Est:
        r->o = Nord;
        break;
    }
}

/* faire tourner le robot à droite */
void tourner_a_droite(Robot *r)
{
    switch (r->o)
    {
    case Nord:
        r->o = Est;
        break;
    case Ouest:
        r->o = Nord;
        break;
    case Sud:
        r->o = Ouest;
        break;
    case Est:
        r->o = Sud;
        break;
    }
}

/* recupere la position de la case du robot */
void position(Robot *r, int *x, int *y)
{
    *x = r->x;
    *y = r->y;
}

/* recupere la position en abscisse de la case du robot */
int abscisse(Robot *r)
{
    return r->x;
}

/* recupere la position en ordonnee de la case du robot */
int ordonnee(Robot *r)
{
    return r->y;
}

/* recupere l'orientation du robot */
Orientation orient(Robot *r)
{
    return r->o;
}

/* recupere la position de la case devant le robot */
void position_devant(Robot *r, int *x, int *y)
{
    switch (r->o)
    {
    case Nord:
        *x = r->x;
        *y = r->y - 1;
        break;
    case Sud:
        *x = r->x;
        *y = r->y + 1;
        break;
    case Ouest:
        *x = r->x - 1;
        *y = r->y;
        break;
    case Est:
        *x = r->x + 1;
        *y = r->y;
    }
}

void nouvelle_orientation(Robot *r, int x, int y, Image I)
{
    Pixel pG;
    Pixel pD;
    switch (r->o)
    {
    case (Est):
        pG = get_pixel_image(I, x + 1, y);
        pD = get_pixel_image(I, x + 1, y + 1);
        if (pG == NOIR)
        {
            r->o = Nord;
            break;
        }
        else if (pD == BLANC)
        {
            r->o = Sud;
            break;
        }
        else
        {
            break;
        }
    case (Nord):
        pG = get_pixel_image(I, x, y);
        pD = get_pixel_image(I, x + 1, y);
        if (pG == NOIR)
        {
            r->o = Ouest;
            break;
        }
        else if (pD == BLANC)
        {
            r->o = Est;
            break;
        }
        else
        {
            break;
        }
    case (Sud):
        pG = get_pixel_image(I, x + 1, y + 1);
        pD = get_pixel_image(I, x, y + 1);
        if (pG == NOIR)
        {
            r->o = Est;
            break;
        }
        else if (pD == BLANC)
        {
            r->o = Ouest;
            break;
        }
        else
        {
            break;
        }
    case (Ouest):
        pG = get_pixel_image(I, x, y + 1);
        pD = get_pixel_image(I, x, y);
        if (pG == NOIR)
        {
            r->o = Sud;
            break;
        }
        else if (pD == BLANC)
        {
            r->o = Nord;
            break;
        }
        else
        {
            break;
        }
    }
}

Point trouver_pixel_depart(Image I)
{
    int hauteur = I.la_hauteur_de_l_image;
    int largeur = I.la_largeur_de_l_image;
    Point depart;
    Pixel voisin;
    Pixel A;
    for (int i = 1; i <= hauteur; i++)
    {
        for (int j = 1; j <= largeur; j++)
        {
            A = get_pixel_image(I, j, i);
            switch (A)
            {
            case (BLANC):
                break;
            case (NOIR):
                if (j != largeur)
                {
                    voisin = get_pixel_image(I, j, i - 1);
                    if (voisin == BLANC)
                    {
                        depart = set_point(j, i);
                        return depart;
                    }
                }
            }
        }
    }
    printf("Can't a pixel to get initialised. The return point is (-1.0 , -1.0)");
    depart = set_point(-1.0, -1.0);
    return depart;
}

//Retruns the contour and also writes the contour <file>.txt - This function will be modfied in order to write multiple contours in the <file>.txt
Contour algo_contour(Image I, char *file_name)
{
    // Managing specific contour
    Point depart = trouver_pixel_depart(I);
    if (depart.x == -1 && depart.y == -1)
    {
        fprintf(stderr, "No starting point found");
        exit(-1);
    }
    else
    {
        // Initialisation du position du robot
        Point rb = set_point(depart.x - 1, depart.y - 1);

        /* Code for Partie 1 is commented since Partie 2 is what is required for the rest of the project*/
        // printf("Pixel de depart: %f , %f\n", rb.x, rb.y);
        // printf("-----------\n");
        Point original_position = set_point(depart.x - 1, depart.y - 1);
        Robot robot;
        init_robot(&robot, rb.x, rb.y, Est);

        // Initialisation de la sequence des points
        Contour c;
        c = creer_liste_Point_vide();

        // Parcours du robot pour la creation du contour
        bool repeat = true;
        while (repeat)
        {
            // Faire partie du Partie 1
            // printf("(%f , %f)\n", rb.x, rb.y);
            ajouter_element_liste_Point(&c, rb);
            avancer(&robot);
            rb = set_point(robot.x, robot.y);
            nouvelle_orientation(&robot, rb.x, rb.y, I);
            if ((robot.o == Est) && (original_position.x == rb.x) && (original_position.y == rb.y))
            {
                repeat = false;
            }
        }
        ajouter_element_liste_Point(&c, rb);

        // Managing file writing
        // File in which will be writted the contour
        FILE *fptr;

        // use appropriate location if you are using MacOS or Linux
        fptr = fopen(file_name, "w");
        if (fptr == NULL)
        {
            printf("TXT File Error!");
            exit(1);
        }

        fprintf(fptr, "1\n");

        Tableau_Point TP = sequence_points_liste_vers_tableau(c);
        int k;
        int nP = TP.taille;
        fprintf(fptr, "\n");
        fprintf(fptr, "%d\n", nP);
        for (k = 0; k < nP; k++)
        {
            Point P = TP.tab[k];
            fprintf(fptr, "%.1f %.1f\n", P.x, P.y);
        }
        free(TP.tab);

        // Faire du partie de Partie 1
        // printf("(%f , %f)\n", rb.x, rb.y);
        return c;
    }
}

void create_postscript(Contour c, char *file_name, int hauteur, int largeur)
{
    // Extension managment
    char *no_extension = strtok(file_name, ".");
    char *with_extension = malloc(strlen(no_extension) + 4);
    strcpy(with_extension, no_extension);
    strcat(with_extension, ".eps");

    FILE *fptr;
    fptr = fopen(with_extension, "w");
    if (fptr == NULL)
    {
        printf("EPS File Error!");
        exit(1);
    }

    fprintf(fptr, "%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(fptr, "%%%%BoundingBox:   %d   %d   %d   %d\n", 0, 0, largeur, hauteur);

    Cellule_Liste_Point *el;
    el = c.first;
    fprintf(fptr, "%.0f %.0f moveto ", el->data.x, el->data.y);
    el = el->suiv;
    while (el != NULL)
    {
        fprintf(fptr, "%.0f %.0f lineto ", el->data.x, el->data.y);
        el = el->suiv;
    }
    fprintf(fptr, "\n");
    fprintf(fptr, "stroke\n");
    fprintf(fptr, "showpage\n");
    fclose(fptr);
    return;
}

void create_postscript_fill(Contour c, char *file_name, int hauteur, int largeur)
{
    // Extension managment
    char *no_extension = strtok(file_name, ".");
    char *with_extension = malloc(strlen(no_extension) + 4);
    strcpy(with_extension, no_extension);
    strcat(with_extension, ".eps");

    FILE *fptr;
    fptr = fopen(with_extension, "w");
    if (fptr == NULL)
    {
        printf("EPS File Error!");
        exit(1);
    }

    fprintf(fptr, "%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(fptr, "%%%%BoundingBox:   %d   %d   %d   %d\n", 0, 0, largeur, hauteur);

    Cellule_Liste_Point *el;
    el = c.first;
    fprintf(fptr, "%.0f %.0f moveto ", el->data.x, el->data.y);
    el = el->suiv;
    while (el != NULL)
    {
        fprintf(fptr, "%.0f %.0f lineto ", el->data.x, el->data.y);
        el = el->suiv;
    }
    fprintf(fptr, "\n");
    fprintf(fptr, "fill\n");
    fprintf(fptr, "showpage\n");
    fclose(fptr);
    return;
}