#include<stdio.h>

int factoriel(int numero){
    
	int totalfactoriel = 1;
    for(int i = 1 ; i<= numero ; i++)
       
        
    totalfactoriel = totalfactoriel * i;
    
    
    return totalfactoriel;
}

int main (){
    int numero ,  total;
    total = 0;
    printf("Digite n : ");
    scanf("%d" , &numero);
    total = factoriel (numero);

    
    printf(" factorial de n: %d\n " , total );


    return 0;
}