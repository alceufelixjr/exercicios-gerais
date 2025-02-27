#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic
{
    void *numeros;
    Type tipo;
    int qtdElementos;
};

tGeneric* CriaGenerico(Type type, int numElem)
{
    tGeneric *generic = (tGeneric *) malloc (sizeof(tGeneric));
    generic->tipo = type;
    generic->qtdElementos = numElem;
    if(type)
        generic->numeros = (int *) malloc (sizeof(int)*numElem); 
    else if(!type)
        generic->numeros = (float *) malloc (sizeof(float)*numElem);
}

void DestroiGenerico(tGeneric* gen)
{
    
}