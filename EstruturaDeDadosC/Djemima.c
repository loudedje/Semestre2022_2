#include<stdio.h>

int main(){
    float x, p;

    printf("Entrez la valeur de x: ");
    scanf("%f" , &x);
    p = x - 100 - (x-150) /4;
    printf("Le resultat est: " , p);

    return 0;
}
/////Aqui///