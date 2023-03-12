#include<stdio.h>

int main(){ 
    float notas [6] = {0};
    float total = 0;
    float media = 0;

    printf("Entrar os valores:\n " );
    for( int i=0 ; i<6 ; i++)
        scanf("%f", &notas[i]);
    for (int i = 0 ; i<6 ; i++)
    total =total + notas[i];

    media = total / 6;
    printf(" A media das notas é: %f\n" , media);

    return 0;

}