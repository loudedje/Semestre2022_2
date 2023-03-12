#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item {
	char produto[50];
	int quantidade;
    struct item  *esquerdo; 
	struct item  *direito;
};
typedef struct item Item;

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
void Imprimir(Item *arv) {
  if (arv != NULL) {
	//printf("___________________________________________\n");
printf("%s %d\n", arv->produto , arv->quantidade); 
	//printf("____________________________________________\n");
	  //arv ->quantidade);
    Imprimir(arv->esquerdo);
    Imprimir(arv->direito);
  }
}Item *query(Item *arv, char produto[50]) {
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




int main() {
  Item *arv = NULL;
  int choose;
  char produto[50];
  int quantidade;

  do {
    printf("0- Sair\n");
    printf("1- Inserir\n");
    printf("2- Imprimir\n");
	printf("3-Buscar na arvore\n");
	printf("4-Deletar um produto\n");
    printf("Escolha uma opção: \n");
    scanf("%d", &choose);

    switch (choose) {
    case 1:
      printf("Digite o produto: ");
      scanf(" %s", produto);
      printf("Digite a quantidade: ");
      scanf("%d", &quantidade);
      arv = inserir(arv, produto, quantidade);
      break;
    case 2:
      Imprimir(arv);
      break;
	case 3:
		printf("Digite o produto: ");
		scanf("%s", produto);
		arv= query(arv, produto);
  			if (arv== NULL) {
   			 printf("Produto não encontrado.\n");
  }
			else {
   			 printf("Produto: %s Quantidade: %d\n", arv->produto, arv->quantidade);
  }      break;
		case 4:
		printf("Digite o produto: ");
		scanf("%s" , produto);
		arv =deletar(arv, produto);
    default:
      if (choose != 0) {
        printf("Opção inválida!\n");
      }
    }
  } while (choose != 0);

  return 0;
}