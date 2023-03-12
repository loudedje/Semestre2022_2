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

// cria uma arvore vazia
Item *criarAvore() { return NULL; }
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
Item* recherche( Item *arv, char produto [50]){
    if(arv){
        if(strcmp(produto, arv->produto)==0){
            
            printf("Já está cadastrado!");
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
	    printf("\nMenu principal\n");
		  printf("1- Acesso com a Lista A\n");
		  printf("2-Acesso com a listar B\n");
		  printf("3-Item duplicados\n");
	    printf("%d - Sair do programa\n",EXIT);
	    printf("\nDigite a opcao: ");
	      scanf("%d",&op);
	      return op;
}

// Apresenta o segundo menu da aplicação e retorna a opção selecionada
int menu2()
{
  int op = 0;
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

// Permite o cadastro de um item (caso o produto ainda não exista) em uma lista de compas

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
        printf("nâo seja burro\n");
     }
    
}
/*Item* Insert(Item*arv){
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
        printf("já esta cadastrado.\n");
        
    
    }
    
}*/

void Imprimir(Item *arv) {
  if (arv != NULL) {
    printf("%s\n", arv->produto);
    Imprimir(arv->esquerdo);
    Imprimir(arv->direito);
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


// Permite a atualização da quantidade de um produto (caso exista) na lista de compras
void update()
{
     printf("atualizando");
     return;
}


// Listar todos os itens da lista de compras em ordem alfabética;
void inOrder(Item *arv) {
  if (arv == NULL) return;
  inOrder(arv->esquerdo);
  printf("Produto: %s Quantidade: %d\n", arv->produto, arv->quantidade);
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
Item* Insert(Item*arv){
    char produto[50];
    int quantidade;
    printf("Entrar o nome do produto: ");
    scanf("%s" , produto);
    printf("Entrar a quantidade  de produto");

}

void intersect()
{
     printf("interseccao");
}

// Programa principal
int main()
{
    int opcao1;
    int opcao2;
    Item *raizA = NULL;
    Item *raizB = NULL;

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
                                   raizA= inserir(raizA);
                                   break;
                              case 2 : 
                                   query();
                                   break;
                              case 3 : 
                                   update();
                                   break;
                              case 4 : 
                                   list();
                                   break;
                              case 5 : 
                                   delete();
                         }    
                    }
                    break;
               case 2 : // gerenciar lista de compras B
                    // idem ao caso 1, mas para a arvore B
               case 3 : // Visualizar itens duplicados
                    intersect();

          }
    }
    return 0;
}

