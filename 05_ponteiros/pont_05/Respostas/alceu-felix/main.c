#include "esfera_utils.h"
#include <stdio.h>


int main()
{
    float raio, v1, a1;
    float *vol, *area;
    
    vol = &v1;
    area = &a1;

    scanf("%f\n",&raio);
    CalculaVolume(raio,vol);
    CalculaArea(raio,area);
    printf("Area: %.2f\n",*area);
    printf("Volume: %.2f\n",*vol);
    return 0;
}