#include <stdint.h>
#include <string.h>
#include<stdlib.h>

#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    //Test no 9
    printf("Starting Test 9\n");
    Contour c;
    c = creer_liste_Point_vide();
    int i = 0;
    while (i<=8)
    {
        Point A;
        double x, y;
        printf("x pour point A:\n");
        scanf("%lf", &x);
        printf("y pour point A:\n");
        scanf("%lf", &y);
        A = set_point(x, y);
        ajouter_element_liste_Point(&c,A);
        printf("================================================\n");
        i++;
    }
    Bezier2 b2;
    int j1, j2;
    printf("j1:\n");
    scanf("%d", &j1);
    printf("j2:\n");
    scanf("%d", &j2);
    b2 = approx_bezier2(c, j1, j2);
    printf("--------------------------------\n");
    printf("C0: (%f, %f)\n", b2.A.x, b2.A.y);
    printf("C1: (%f, %f)\n", b2.B.x, b2.B.y);
    printf("C2: (%f, %f)\n", b2.C.x, b2.C.y);

    return 0;

}
