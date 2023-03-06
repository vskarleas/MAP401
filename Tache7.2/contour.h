
#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include <stdbool.h>
#include "geom2d.h"
#include "image.h"
#include "sequence_point.h"

typedef enum {Nord, Est, Sud, Ouest} Orientation;

typedef struct {
  int x, y;
  Orientation o;
} Robot;

/* initialiser le robot r en position (x,y) et orientation o */
void init_robot(Robot *r, int x, int y, Orientation o);

/* faire avancer le robot d'une case */
void avancer(Robot *r);

/* faire tourner le robot à gauche */
void tourner_a_gauche(Robot *r);

/* faire tourner le robot à droite */
void tourner_a_droite(Robot *r);

/* recupere la position de la case du robot */
void position(Robot *r, int *x, int *y);

/* recupere la position en abscisse de la case du robot */
int abscisse(Robot *r);

/* recupere la position en ordonnee de la case du robot */
int ordonnee(Robot *r);

/* recupere l'orientation du robot */
Orientation orient(Robot *r);

/* recupere la position de la case devant le robot */
void position_devant(Robot *r, int *x, int *y);

/* Logic de calcul de la nouvelle orientation */
void nouvelle_orientation(Robot *r, int x, int y, Image I);

/* Fonction qui renvoi les coordonees du pixel de depart */
Point trouver_pixel_depart(Image I);

Image mask_image(Image I);

bool image_blache(Image I);

Contour algo_contour(Image I, char *file_name);

Liste_Contours algo_contours(Image I);

void ecrire_fichier_contours(Liste_Contours c, char *file_name);

void contours_data(Liste_Contours c);

void contours_data_simplification(Liste_Contours c);

void contours_data_bezier(Liste_Contours c);

void create_postscript(Contour c, char *file_name, int hauteur, int largeur);

void create_postscript_fill(Contour c, char *file_name, int hauteur, int largeur);

void create_postscript_contours(Liste_Contours c, char *file_name, int hauteur, int largeur);

Contour simplification_douglas_peucker(Contour C, int j1, int j2, double d);

Point calcul_ct_bezier2(Bezier2 b2, double t);

Point calcul_ct_bezier3(Bezier3 b3, double t);

Bezier3 conversion_bezier2_to_bezier3 (Bezier2 b2);

Bezier2 approx_bezier2(Contour c, int j1, int j2);

Bezier3 approx_bezier3(Contour c, int j1, int j2);

double distance_point_bezier2(Point P1, Bezier2 b2, double ti);

double distance_point_bezier3(Point P1, Bezier3 b3, double ti);

Contour simplification_douglas_peucker_bezier2(Contour C, int j1, int j2,double d);

Contour simplification_douglas_peucker_bezier3(Contour C, int j1, int j2,double d);

void create_postscript_contours_bezier2(Liste_Contours c, char *file_name, int hauteur, int largeur);

void create_postscript_contours_bezier3(Liste_Contours c, char *file_name, int hauteur, int largeur);

#endif /* _CONTOUR_H_ */