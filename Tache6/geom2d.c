#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "geom2d.h"

Point set_point(double x, double y)
{
    Point P = {x,y};
    return P;
}

Vecteur set_vecteur(double x, double y)
{
    Vecteur V = {x,y};
    return V;
}

Point add_point(Point P1, Point P2)
{
    return set_point(P1.x+P2.x, P1.y+P2.y);
}

Vecteur add_vecteur(Vecteur V1, Vecteur V2)
{
    return set_vecteur(V1.x+V2.x, V1.y+V2.y);
}

Vecteur vect_bipoint(Point A, Point B)
{
    Vecteur V = {B.x-A.x, B.y-A.y};
    return V;
}

Point produit(Point P1, double a)
{
    return set_point(a*P1.x, a*P1.y);
}

Vecteur produit_vect(Vecteur V1, double a)
{
    return set_vecteur(a*V1.x, a*V1.y);
}

double produit_scalaire(Vecteur V1, Vecteur V2)
{
    return (V1.x*V2.x + V1.y*V2.y);
}

double norme(Vecteur V1)
{
    return (sqrt(V1.x*V1.x + V1.y*V1.y ));
}

double distance(Point P1, Point P2)
{
    return(sqrt((P1.x-P2.x)*(P1.x-P2.x) + (P1.y-P2.y)*(P1.y-P2.y)));
}

Vecteur creer_vecteur(Point P1, Point P2)
{
    Vecteur V;
    double res = P2.x - P1.x;
    V = set_vecteur(res, P2.y - P1.y);
    return V;
}

double distance_point_segment(Point P1, Segment S1)
{
    if ((S1.A.x == S1.B.x) && (S1.A.y == S1.B.y))
    {
        return distance(P1, S1.A);
    }
    else 
    {
        double λ;
        Vecteur AP;
        Vecteur AB;
        AP = creer_vecteur(S1.A, P1);
        AB = creer_vecteur(S1.A, S1.B);
        λ = produit_scalaire(AP, AB)/produit_scalaire(AB, AB);
        if (λ < 0)
        {
            return distance(P1, S1.A);
        }
        if (λ > 1)
        {
            return distance(P1, S1.B);
        }
        else
        {
            Point Q;
            Point q;
            q = set_point(S1.B.x-S1.A.x, S1.B.y-S1.A.y);
            q = produit(q, λ);
            Q = add_point(S1.A, q);
            return distance(Q, P1);
        }
    }
}
