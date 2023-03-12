#include<stdio.h>
#include<stdlib.h>

//tamanho 15
// M = 2*15 = 31 mais proximo de 31;

#define TAM 31

void IncializarTabela(int t[]){
    for (int i =0; i < TAM; i++)
         t[i] = 0;
}
//funcão de espalhamento com formula  chave % M

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor); 
    while(t[id] != 0){
        id = funcaoHash(id + 1);
    }
}

int buscar( int t[], int chave){
    int id = funcaoHash (chave);
    while(t[id] != 0){
        if (t[id] == chave){
            return t[id];
			}
        else
            id = funcaoHash(id + 1);
	}
        return 0;
}
void imprimir(int t[]){
    for (int i = 0; i<TAM; i++){
        printf("%d = %d\n" , i , t[i]);
    }

}
int main(){
    int tabela[TAM]; 
    int  opcao;
    int retorno;
	int valor;
	
	IncializarTabela(tabela);
	
    do{
        printf("0 - Sair \n 1-inserir \n 2- buscar \n 3- imprimir \n");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            printf("qual valor deseja inserir: ");
            scanf("%d" , &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\n Qual valor deseja buscar? ");
            scanf("%d", &valor);
            retorno = buscar ( tabela , valor);
            if (retorno != 0){
                printf("valor encontrado:  %d\n" , retorno);
				}
            else
                printf("Não encontrado\n ");
            break;
        case 3: 
            imprimir(tabela);
         break;
        default:
        printf("Entrar um numero valido\n");
		}
    }while (opcao !=0);
    return 0;
}