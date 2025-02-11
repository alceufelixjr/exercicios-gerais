#include "lesao.h"
#include <stdio.h>
#include <stdlib.h>

struct lesao{
    char * id; /**< O identificador da lesão. */
    char * diagnostico; /**< O diagnóstico da lesão. */
    char * regiao_corpo; /**< A região do corpo da lesão. */
    int chance_malignidade; /**< A chance de malignidade da lesão. */
};

/**
 * @brief Cria uma estrutura do tipo lesão
 * 
 * @return ponteiro para estrutura do tipo lesão
 */ 
tLesao* CriaLesao()
{
    tLesao *l = (tLesao *) malloc (sizeof(tLesao));
    l->id = (char *) malloc (sizeof(char)*TAM_ID);
    l->diagnostico = (char *) malloc (sizeof(char)*TAM_DIAG);
    l->regiao_corpo = (char *) malloc (sizeof(char)*TAM_REG);

    return l;
}

/**
 * @brief Lê informações sobre uma lesão da entrada padrão.
 * 
 * @param l ponteiro para lesão que terá seus dados preenchidos
 */
void LeLesao(tLesao* l)
{
    scanf("%[^\n]\n",l->id);
    scanf("%[^\n]\n",l->diagnostico);
    scanf("%[^\n]\n",l->regiao_corpo);
    scanf("%d\n",&l->chance_malignidade);
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tLesao.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao a ser liberada.
 */
void LiberaLesao(tLesao* l)
{
    if(l != NULL)
    {
        free(l->diagnostico);
        free(l->id);
        free(l->regiao_corpo);
        free(l);
    }
    
}

/**
 * @brief Retorna o identificador da lesão.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna uma string contendo o identificador da lesão.
 */
char* GetIdLesao(tLesao* l)
{
    return l->id;
}

/**
 * @brief Verifica se a lesão precisa de cirurgia.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna 1 se a lesão precisa de cirurgia e 0 caso contrário.
 */
int PrecisaCirurgiaLesao(tLesao* l)
{
    if(l->chance_malignidade > 50)
        return 1;
    return 0;
}

