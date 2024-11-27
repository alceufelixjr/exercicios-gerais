#include "ponto.h"
#include <stdio.h>

int main(void)
{
    Ponto p1, p2;
    float x1, y1;
    float x2, y2;
    float distancia;
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);

    p1 = pto_cria(x1, y1);
    p2 = pto_cria(x2, y2);

    printf("P1 --> %f %f\n", p1.x, p1.y);
    printf("P2 --> %f %f\n", p2.x, p2.y);

    distancia = pto_distancia(p1, p2);
    printf("%.3f", distancia);
}