#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT 10 

typedef struct item {
    char produto[50];
    int quantidade;
    struct item *esquerdo;
    struct item *direito;
};
typedef struct item Item;

int comparar_produto(char* produto1, char* produto2);

int comparar_produto(char* produto1, char* produto2) {
    if (strcmp(produto1, produto2) == 0) {
        return 0;
    } else if (strcmp(produto1, produto2) < 0) {
        return -1;
    } else {
        return 1;
    }
}

Item* inserir(Item *arv, int quantidade, char produto[50]){
    if(arv == NULL) {
        Item* novo = (Item*)malloc(sizeof(Item));
        strcpy(novo->produto, produto);
        novo->quantidade = quantidade;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        printf("Nome: %s\t quantidade: %d\n",novo->produto,novo->quantidade);
        return novo;
    }
    if(comparar_produto(arv->produto,produto)!= 0){
        if (comparar_produto(arv->produto,produto)<0) {
        arv->esquerdo = inserir(arv->esquerdo, quantidade, produto);
        }else{
            arv->direito = inserir(arv->direito, quantidade, produto);
        }
    }
    return arv;
}
Item* query(Item *arv, int quantidade, char produto[50]){
     if(arv){
          if(quantidade == arv->quantidade && strcmp(produto, arv->produto) == 0)
               return arv;
          else if(quantidade < arv->quantidade)
               return query(arv->esquerdo , quantidade, produto);
          else
               return query(arv->direito, quantidade, produto);
     }
     printf("Não foi encontrado o produto");
     return NULL;
}


Item* Update(Item *arv, int quantidade, char produto[50], int new_quanti, char new_pro[50])
{
    if(arv == NULL)
        return NULL;
    if (arv->quantidade == quantidade && strcmp(arv->produto, produto) == 0){
        arv->quantidade = new_quanti;
        strcpy(arv->produto, new_pro);
        return arv;
    }
    if( arv->quantidade < quantidade)
        return Update(arv->esquerdo, quantidade, produto, new_quanti, new_pro);
    else
        return Update(arv->direito , quantidade, produto, new_quanti, new_pro);
    printf("Actualização realizada com sucesso\n");
    return arv;
}
// Listar todos os itens da lista de compras em ordem alfabética;
Item* listar( Item *arv){
     if(arv ==NULL){
          listar(arv->esquerdo);
          printf("%s , %d\n" , arv->produto, arv->quantidade);
          listar(arv->direito);
    }
}
Item *deletar (Item *arv, int quantidade, char produto[50]){
     if (arv == NULL){
        printf("valor não escontrado\n");
        return NULL;
        
     }
     else{
          if (arv ->quantidade == quantidade && strcmp(arv->produto, produto)){
               free(arv);
               printf("Elemento foi removido com sucesso \n");
               free(arv);
               return NULL;
          }
          else {
               if(quantidade < arv ->quantidade && strcmp(arv->produto, produto)){
                    arv ->esquerdo = deletar (arv ->esquerdo, quantidade, produto);
               }
               else {
                    arv->direito = deletar(arv ->direito, quantidade, produto); 
               }
               return arv;
          }
     }
}
Item* Insericao(Item *arv, int quantidade, char produto[50])
{
    if(arv == NULL)
    {
        arv = (Item*)malloc(sizeof(Item));
        arv->quantidade = quantidade;
        strcpy(arv->produto, produto);
        arv->esquerdo = arv->direito = NULL;
        printf(" Foi Realizada com sucesso\n");
        return arv;
    }
    if(quantidade < arv->quantidade && strcmp(arv->produto, produto) < 0 )
        arv->esquerdo = Insericao(arv->esquerdo, quantidade, produto);
    else
        arv->direito = Insericao(arv->direito, quantidade, produto);
    return arv;
}

Item *Imprimir(Item *arv){
	if(arv){
		Imprimir(arv->esquerdo);
		Imprimir(arv->direito);	
		printf("%s", arv->produto);
		}
}

void Menu1(){
    char produto [50];
    int valor;
    int choix;
	char new_pro;
	int new_quanti;
	Item *arv = NULL;
    
	
    for(; ;){
		printf("\nListar dos primeiros Produtos\n");
    printf("*******************************\n");
    printf("Menu principal\n");
    printf("*********************************\n");
    printf("1-Inserir um produto\n 2-Buscar um produto\n 3-Atualizar um produto\n 4-Listar produto\n 5-Remover um produto\n 6- Imprimir os Produtos\n");
	printf("%d - Sair do programa\n", EXIT);
printf("******************************\n");
        scanf("%d" , &choix);
        if (choix == 1){
		
            printf("Nome do produto: ");
            scanf("%s", produto);
            printf("Quantidade: ");
            scanf("%d" , &valor);
            inserir( arv , valor, produto);
        }
			
        else if(choix ==2){
            printf("Digite o Nome do produto que você quer buscar");
            scanf("%s" , produto);
            query( arv, valor, produto);
        }
        else if( choix == 3){
            printf("Digite o nome do nome que você  quer atualizar");
			scanf("%s" , new_pro);
            Update(arv , valor, produto,new_pro, new_quanti);
        }
        else if( choix == 4){
            printf("Listar em Ordem");
            listar(arv);
        }
		else if( choix ==5 ){
			printf("Digite qual produto que você quer remover: ");
            scanf("%s" ,produto);
		}
		else if(choix == 6){
		printf("O produto é: \n  ", produto);
		Imprimir(arv);
		printf("\n");
		}
    }
} 
int main(){

    Menu1();
    return 0;
}