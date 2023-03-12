#include<stdio.h>

int main(){
    const int bimestresAnnuais = 4;
    const int numeroAlunos = 4;

    float notasAlunos[numeroAlunos][bimestresAnnuais] = {0};
    float mediaAlunos[numeroAlunos] ={0};
    float media = 0;

    printf(" Insira as 4 notas do aluno 1: \n");

    for(int aluno  = 0 ; aluno<numeroAlunos ; aluno++){
        for( int notas = 0; notas < bimestresAnnuais ; notas++){
            scanf("%f" , &notasAlunos [aluno][notas]);
            media +=notasAlunos [aluno][notas];
        }
        mediaAlunos[aluno] = media / bimestresAnnuais;
        media = 0;
        printf("Insira as notas do aluno %i :\n" , aluno +2);

    }
    for ( int aluno = 0; aluno < numeroAlunos; aluno++){
        printf("A media do aluno %d é %.2f\n" , aluno+1, mediaAlunos[aluno]);
        return 0;
    }
}