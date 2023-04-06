#ifndef _GEOM2D_H_
#define _GEOM2D_H_

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

//Profil d'un segment 
typedef struct Segment_
{
   Point A, B;
} Segment;

//Profil d'une courbe de bezier de degree 2
typedef struct Bezier2_
{
   Point A, B, C;
} Bezier2;

//Profil d'une courbe de bezier de degree 3
typedef struct Bezier3_
{
   Point A, B, C, D;
} Bezier3;

/* Initialisation d'un point  */ 
Point set_point(double x, double y);

/* Initialisation d'un vecteur  */
Vecteur set_vecteur(double x, double y);

/* Addition de deux points */
Point add_point(Point P1, Point P2);

/* Additon des deux vecteurs */
Vecteur add_vecteur(Vecteur V1, Vecteur V2);

Vecteur vect_bipoint(Point A, Point B);

/* Produit d'un point avec un nombre reel */
Point produit(Point P1, double a);

/* Produit d'un vencteur avec un nombre reel */
Vecteur produit_vect(Vecteur V1, double a);

/* Produit scalaire entre deux vecteurs */
double produit_scalaire(Vecteur V1, Vecteur V2);

/* Norme d'un vecteur */
double norme(Vecteur V1);

/* Distance entre deux points */
double distance(Point P1, Point P2);

/* Vecteur par deux points initiaux */
Vecteur creer_vecteur(Point P1, Point P2);

/* Distance netre point et segment */
double distance_point_segment(Point P1, Segment S1);

#endif /* _GEOM2D_H_ */
