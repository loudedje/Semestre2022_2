/*
 Este é um esqueleto que deve ser utilizado como base para implementação do trabalho;
	- As funções não têm os parâmetros definidos; se necessário, estes devem ser incluídos; Os tipos de retorno podem ser alterados, se necessário;
 	- Devem ser respeitados os nomes atribuídos às funções e estruturas, porém, novas estruturas e funções podem ser criadas, caso julgue necessário;
	- Faça os includes necessários;
	- A organização das funções fica a critério do programador;
	- A indentação correta faz parte da nota;
	- Não são permitidas variáveis globais;
	- Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

// Struct que representa um item de uma lista de compras armazenada em uma arvore binaria de busca
struct item {
	char produto[50];
	int quantidade;
    struct item  *esquerdo; 
	struct item  *direito;
};

typedef struct item Item;

struct duplicado{
    char produto[50];
    struct duplicado *proximo;
};
typedef struct duplicado Duplicado;


// cria uma arvore vazia
Item *criarAvore() 
{ 
  return NULL;
}

// verificar se a arvore está vazia
int arvoreVazia(Item *arv) {
  if (arv == NULL) {
    return 1;
  }
  return 0;
}

Item *liberaArvore(Item *arv) {
  if (arvoreVazia(arv) != 0) {
    liberaArvore(arv->esquerdo);
    liberaArvore(arv->direito);
  }
  return NULL;
}
//esta funcão tem como objectivo de comparar os produtos.

int comparar_produto(char *produto1, char *produto2);

int comparar_produto(char *produto1, char *produto2) {
  if (strcmp(produto1, produto2) == 0) {
    return 0;
  } else if (strcmp(produto1, produto2) < 0) {
    return -1;
  } else {
    return 1;
  }
}

//esta função tem como objectivo de não aceita dois produtos do mesmo nome
Item* recherche( Item *arv, char produto [50]){
    if(arv){
        if(strcmp(produto, arv->produto)==0){
            
           // printf("Já está cadastrado!");
            return arv;
        }
            
        else{
             if(strcmp(arv->produto, produto) != 0){
            return recherche(arv ->esquerdo, produto);
            
        }
        else{
            return recherche(arv ->direito, produto);
        }
        
    }
    }
    return NULL;
}

// Apresenta o primeiro menu da aplicação e retorna a opção selecionada
int menu1()
{
     int op = 0;
        printf("\n\n-------SEJA BEM-VINDO-------\n\n");
	      printf("*******MENU PRINCIPAL*******\n ");
	      printf("-----------------------------------\n");
		  printf("1- ACESSO COM A LISTA A\n");
		  printf("2- ACESSO COM A LISTA B\n");
		  printf("3- ITEM DUPLICADOS\n");
      printf("%d - Sair do programa\n",EXIT);
      printf("\nDigite a opcao: ");
      scanf("%d",&op);
      return op;
}


// Apresenta o segundo menu da aplicação e retorna a opção selecionada
int menu2()
{
  int op = 0;
  printf("******************************************\n");
  printf("Submenu - Gerenciar lista de compras\n");
	printf("1-Inserir um produto na lista\n"); 
	printf("2-Buscar  um produto na lista\n");
	printf("3-Atualizar um produto na lista\n");
	printf("4-Listar um produto na lista\n");
	printf("5-Deletar um produto na lista\n");
	printf("%d Retornar no menu principal",EXIT);
     printf("\nDigite a opcao: ");
     scanf("%d",&op); 
     return op;
	
    // complete com as demais opcoes...

}


// Permite o cadastro de um item (caso o produto ainda não exista) em uma lista de compras
Item* inserir(Item *arv, char produto[50], int quantidade) {
  if (arv == NULL) {
    Item *novo = (Item *)malloc(sizeof(Item));
    strcpy(novo->produto, produto);
    novo->quantidade = quantidade;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
  } else {
        if(comparar_produto(produto , arv->produto)){
        arv->esquerdo = inserir(arv->esquerdo, produto, quantidade);
        }
       else {
      arv->direito = inserir(arv->direito, produto, quantidade);
    }
    return arv;
  }
}

Item* Insert(Item*arv){
    char produto[50];
    int quantidade;
    printf("Entrar o nome do produto: ");
    scanf("%s" , produto);
    if (recherche(arv, produto)== NULL){
        //printf("Produto nao cadastrado\n");
        printf("Entrar a quantidade  de produto: ");
        scanf("%d", &quantidade);
        arv = inserir(arv, produto, quantidade);
    }
    else {
        printf("Está cadastrado\n");
     }
    
}

void Imprimir(Duplicado* primeiro) {
  if (primeiro != NULL) {
    printf("%s\n", primeiro->produto);
    }
}

// Permite consultar se um item está em uma lista de compras
Item *query(Item *arv, char produto[50]) {
  if (arv == NULL) {
    return NULL; 
  }
  if (strcmp(produto, arv->produto) < 0) {
    return query(arv->esquerdo, produto);
  }
  if (strcmp(produto, arv->produto) > 0) {
    return query(arv->direito, produto);
  }
  return arv;
}




// Listar todos os itens da lista de compras em ordem alfabética;
void inOrder(Item *arv) {
  if (arv == NULL) 
  return;
  
  inOrder(arv->esquerdo);
  printf("PRODUTOS NA LISTA\n");
  printf("----------------------------------\n");
  printf("Produto: %s                    Quantidade: %d\n", arv->produto, arv->quantidade);
  printf("---------------------------------------\n");
  inOrder(arv->direito);
}


// Permite excluir um item de uma lista de compras
Item *deletar(Item *arv, char *produto) {
  if (arv == NULL) {
    return NULL;
  } else {
    int result = comparar_produto(produto, arv->produto);
    if (result == 0) {
      if (arv->esquerdo == NULL) {
        Item *temp = arv->direito;
        free(arv);
        printf("Elemento foi removido com sucesso \n");
        return temp;
      } else if (arv->direito == NULL) {
        Item *temp = arv->esquerdo;
        free(arv);
        printf("Elemento foi removido com sucesso \n");
        return temp;
      } else {
        Item *temp = arv->direito;
        while (temp->esquerdo != NULL) {
          temp = temp->esquerdo;
        }
        strcpy(arv->produto, temp->produto);
        arv->quantidade = temp->quantidade;
        arv->direito = deletar(arv->direito, temp->produto);
        return arv;
      }
    } else if (result < 0) {
      arv->esquerdo = deletar(arv->esquerdo, produto);
    } else {
      arv->direito = deletar(arv->direito, produto);
    }
    return arv;
  }
}
//essa função está junto com a função Insert
/*Item* Inserir(Item*arv){
    char produto[50];
    int quantidade;
    printf("Entrar o nome do produto: ");
    scanf("%s" , produto);
    printf("Entrar a quantidade  de produto");

}*/
// Permite a atualização da quantidade de um produto (caso exista) na lista de compras 
void updateQuantidade(Item *raiz, char *produto, int novaQuantidade) {
    Item *resultado = query(raiz, produto);
    if (resultado == NULL) {
        printf("Produto não encontrado.\n");
    } else {
        resultado->quantidade = novaQuantidade;
        printf("Quantidade atualizada para %d.\n", novaQuantidade);
    }
}




Duplicado* inserirNoFim(Duplicado *primeiro, char produto[50]){
    Duplicado *aux;
    Duplicado *novo = malloc(sizeof(Duplicado));
    if(novo){
        strcpy(novo->produto,produto);
        novo->proximo = NULL;
        
        if(primeiro == NULL){
            primeiro = novo;
            return primeiro;
        }
        else{
            aux = primeiro;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = novo;
            return primeiro;
        }
    }
    else{
        printf("ERRO DE ALLOCAR\n");
    }
}
Duplicado* inter(Duplicado *primeiro,Item *raizA,Item *raizB){
    Item *busca;
    char produto[50];
    if(raizA == NULL || raizB == NULL ){
        return NULL;
    }
    else{
        strcpy(produto,raizA->produto);
        busca = recherche(raizB,produto);
        if(busca != NULL){
            primeiro = inserirNoFim(primeiro,produto);
        }
        inter(primeiro,raizA->esquerdo,raizB);
        inter(primeiro,raizA->direito,raizB);
        return primeiro;
    }
} 
void intersect(Item *raizA,Item *raizB)
{
    Duplicado *primeiro = NULL;
    printf("interseccao\n");
    primeiro = inter(primeiro,raizA,raizB);
    Imprimir(primeiro);
    
}
// Programa principal
int main()
{
	int quantidade;
	int novaquantidade;
	char produto[50];
     int opcao1;
     int opcao2;
     
    Item *raizA = NULL;
    Item *raizB = NULL;
    Item *resultado;
    
    opcao1 = 0;
    while (opcao1 != EXIT)
    {
          opcao1 = menu1();
               
          switch(opcao1)
          {
               case 1 : // gerenciar lista de compras A
                    opcao2 = 0;
                    while(opcao2 != EXIT){
                         printf("\n\n** Lista de Compras A **\n\n");
                         opcao2 = menu2();
                         switch(opcao2){ // operacoes sobre a arvore A
                              case 1 : 
                                   raizA = Insert(raizA);
                                   break;
                              case 2 : 		
                              	
                              printf("Digite o produto: ");
								  scanf("%s", produto);
                              resultado= query(raizA, produto);
                               if (resultado == NULL) {
                               printf("Produto não encontrado.\n");
                              } 
                              else {
                                   printf("Produto: %s Quantidade: %d\n", raizA->produto, raizA->quantidade);
                                   }
                                   break;
                              case 3 : 
                              printf("Nome do Produto a atualizar: \n");
                              scanf("%s" , produto);
                              printf("Digite  a nova quantidade: \n");
                              scanf("%d", &novaquantidade);
                              updateQuantidade(raizA,produto, novaquantidade);
                              case 4 :
                                   inOrder(raizA);
                                   break;
                              case 5 : 				
                              printf("Digite o produto ser excluido na lista: ");
                              scanf("%s", produto);
                            	raizA = deletar(raizA, produto);
                              break;          
                                
                    }
						}
               case 2 :
                opcao2 = 0;
                    while(opcao2 != EXIT){
                         printf("\n\n** Lista de Compras B **\n\n");
                         opcao2 = menu2();
                         switch(opcao2){ 
                              case 1 : 
                                   raizB = Insert(raizB);
                                   break;
                              case 2 : 		
                              	
                              printf("Digite o produto: ");
								  scanf("%s", produto);
                              resultado= query(raizB, produto);
                               if (resultado == NULL) {
                               printf("Produto não encontrado.\n");
                              } 
                              else {
                                   printf("Produto: %s Quantidade: %d\n", raizB->produto, raizB->quantidade);
                                   }
                                   break;
                              case 3 : 
                              printf("Digite o produto: ");
                              scanf("%s" , produto);
                              printf("Digite  a nova quantidade: ");
                              scanf("%d", &novaquantidade);
                              updateQuantidade(raizB,produto, novaquantidade);
                              case 4 :
                                   inOrder(raizB);
                                   break;
                              case 5 : 				
                              printf("Digite o produto ser excluido na lista: \n");
                              scanf("%s", produto);
                            	raizB = deletar(raizB, produto);
                              break;          
                                
                    }
						}
                
               case 3 : // Visualizar itens duplicados
                    intersect(raizA, raizB);

          }
    }
    return 0;
}
