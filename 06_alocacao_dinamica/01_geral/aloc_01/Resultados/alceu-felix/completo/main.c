#include "utils.h"
#include <stdio.h>


int main(){
    
    int qtdInteiros;
    scanf("%d\n",&qtdInteiros);
    
    int *vetorInteiros = CriaVetor(qtdInteiros);
    LeVetor(vetorInteiros,qtdInteiros);

    float mediaInteiros = CalculaMedia(vetorInteiros,qtdInteiros);
    printf("%.2f\n",mediaInteiros);

    LiberaVetor(vetorInteiros);
    
    return 0;
}