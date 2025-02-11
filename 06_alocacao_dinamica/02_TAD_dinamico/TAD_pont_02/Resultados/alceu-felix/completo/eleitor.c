#include "eleitor.h"
#include <stdio.h>
#include <stdlib.h>


// typedef struct{
//     int id;
//     int votoP;
//     int votoG;
// } tEleitor;

/**
 * @brief Cria um eleitor "vazio".
 * Os ponteiros devem ser inicializados com NULL e os campos numéricos com o valor -1.
 * @return Ponteiro para eleitor vazio criado
 */
tEleitor* CriaEleitor()
{
    tEleitor *eleitor = (tEleitor *) malloc (sizeof(tEleitor));
    eleitor->id =  -1;
    eleitor->votoP = -1;
    eleitor->votoG = -1;

    return eleitor;
}

/**
 * @brief Apaga/Libera toda a memória alocada dinamicamente para armazenar dados de um eleitor
 * @param eleitor Ponteiro para eleitor que será apagado.
 */
void ApagaEleitor(tEleitor* eleitor)
{
    if(eleitor != NULL)
        free(eleitor);
}

/**
 * @brief Lê um eleitor do teclado.
 * @param eleitor Ponteiro para o eleitor que terá seus dados armazenados.
 */
void LeEleitor(tEleitor *eleitor)
{
    scanf("%d %d %d\n",&eleitor->id,&eleitor->votoP,&eleitor->votoG);
}

/**
 * @brief Obtém o voto para presidente do eleitor.
 * @param eleitor Ponteiro para Eleitor a ser verificado.
 * @return Voto para presidente do eleitor.
 */
int ObtemVotoPresidente(tEleitor* eleitor)
{
    return(eleitor->votoP);
}

/**
 * @brief Obtém o voto para governador do eleitor.
 * @param eleitor Ponteiro para Eleitor a ser verificado.
 * @return Voto para governador do eleitor.
 */
int ObtemVotoGovernador(tEleitor* eleitor)
{
    return(eleitor->votoG);
}

/**
 * @brief Verifica se dois eleitores são iguais (dica: use para verificar se algum eleitor tentou registar um voto novamente).
 * @param eleitor1 Ponteiro para primeiro eleitor a ser comparado.
 * @param eleitor2 Ponteiro para segundo eleitor a ser comparado.
 * @return 1 se os eleitores são iguais, 0 caso contrário.
 */
int EhMesmoEleitor(tEleitor* eleitor1, tEleitor* eleitor2)
{
    return(eleitor1->id == eleitor2->id);
}

