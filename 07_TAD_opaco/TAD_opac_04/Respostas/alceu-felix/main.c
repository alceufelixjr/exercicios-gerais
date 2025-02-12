#include "aluno.h"

#define TAM_ALUNOS 2
#define INCREMENTA_ALUNO 2

typedef struct
{
    tAluno **alunos;
    int qtdAlunosAloc;
    int qtdAlunos;
}Turma;

int main(){

    int qtdAlunos;
    
    Turma *t = (Turma *) malloc (sizeof(Turma));
    t->alunos = (tAluno **) malloc (sizeof(tAluno *));
    t->qtdAlunosAloc = TAM_ALUNOS;
    t->qtdAlunos = 0;

    scanf("%d\n",&qtdAlunos);
    for(t->qtdAlunos; t->qtdAlunos < qtdAlunos; t->qtdAlunos++)
    {
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        
        if(t->qtdAlunosAloc == t->qtdAlunos)
        {
            t->qtdAlunosAloc += INCREMENTA_ALUNO;
            t->alunos = (tAluno **) realloc (t->alunos,sizeof(tAluno *)*t->qtdAlunosAloc);
        }
        t->alunos[t->qtdAlunos] = aluno;
        t->qtdAlunos++;
    }

    for(int i = 0; i < t->qtdAlunos; i++)
    {
        ApagaAluno(t->alunos[i]);
    }
    free(t->alunos);
    free(t);

    return 0;
}