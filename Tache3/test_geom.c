#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "geom2d.h"

int main(int argc, char **argv)
{
    //Test no 3
    Point A, B, C;
    A = set_point(1.0, -3.0);
    B = set_point(4.0, 1.0);
    C = add_point(A, B);
    printf("%f %f \n", C.x, C.y);

    Vecteur V, I, Z;
    V = set_vecteur(1.0, 2.0);
    I = set_vecteur(0.0, 5.0);
    Z = add_vecteur(V, I);
    printf("%f %f \n", Z.x, Z.y);

    double a = 3;
    Z = produit_vect(V, a);
    printf("%f %f \n", Z.x, Z.y);

    C = produit(A, a);
    printf("%f %f \n", C.x, C.y);

    double res;
    res = produit_scalaire(V, I);
    printf("%f \n", res);

    res = norme(I);
    printf("%f \n", res);

    res = distance(A, B);
    printf("%f \n", res);

    return 0;
}

