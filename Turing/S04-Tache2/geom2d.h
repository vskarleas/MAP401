#ifndef _GEOM2D_H_
#define _GEOM2D_H_

#include "types_macros.h"

//Type Vecteur 
typedef struct Vecteur_
{
   double x,y;
} Vecteur;

//Type Point 
typedef struct Point_
{
   double x,y;
} Point;

Point set_point(double x, double y);

Vecteur set_vecteur(double x, double y);

Point add_point(Point P1, Point P2);

Vecteur add_vecteur(Vecteur V1, Vecteur V2);

Vecteur vect_bipoint(Point A, Point B);

Point produit(Point P1, double a);

Vecteur produit_vect(Vecteur V1, double a);

double produit_scalaire(Vecteur V1, Vecteur V2);

double norme(Vecteur V1);

double distance(Point P1, Point P2);

#endif /* _GEOM2D_H_ */
