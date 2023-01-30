#include <stdint.h>
#include <string.h>
#include<stdlib.h>
#include <stdio.h>

#include "geom2d.h"

int main(int argc, char **argv)
{
    printf("Testing equestions of geometry in 2 axes space\n");

    //Test no 3
    Point A, B, C;
    A = set_point(1.0, -3.0);
    B = set_point(4.0, 1.0);
    C = add_point(A, B);
    printf("Points utilise dans ce test:\n");
    printf("A:(%f,%f)\n",A.x,A.y);
    printf("B:(%f,%f)\n",B.x,B.y);
    printf("==========");
    printf("Test additon des point\n");
    printf("%f %f \n", C.x, C.y);
    printf("\n");

    printf("\n");
    printf("----------");
    Vecteur V, I, Z;
    V = set_vecteur(1.0, 2.0);
    I = set_vecteur(0.0, 5.0);
    printf("Vecteurs utilise dans ce test:\n");
    printf("Vecteur V:(%f->%f)\n",V.x,V.y);
    printf("Vecteur I:(%f->%f)\n",I.x,I.y);
    printf("==========");
    Z = add_vecteur(V, I);
    printf("Test additon des vecteurs\n");
    printf("%f %f \n", Z.x, Z.y);
    printf("\n");

    double a = 3;
    Z = produit_vect(V, a);
    printf("Test produit de vecteur avec un nombre naturel\n");
    printf("%f %f \n", Z.x, Z.y);
    printf("\n");

    C = produit(A, a);
    printf("Test produit d'un point avec un nombre naturel\n");
    printf("%f %f \n", C.x, C.y);
    printf("\n");

    double res;
    res = produit_scalaire(V, I);
    printf("Test produit scalaire\n");
    printf("%f \n", res);
    printf("\n");

    res = norme(I);
    printf("Test norme\n");
    printf("%f \n", res);
    printf("\n");

    res = distance(A, B);
    printf("Test distance entre deux points\n");
    printf("%f \n", res);
    printf("\n");
}

