#include<stdlib.h>
#include <stdio.h>
#include<string.h> 

#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

// Struct que representa um item de uma lista de compras armazenada em uma arvore binaria de busca
typedef struct item{
     char produto[50];
     int quantidade;
     struct item *esquerdo;
     struct item *direito;
}Item;




// Apresenta o primeiro menu da aplicação e retorna a opção selecionada
int menu1()
{
     int op = 0;
     while (op !=EXIT)
     {    printf("----------------------------------\n");
          printf("\nMenu principal\n");
          printf("-----------------------------------\n");
          printf("Digite a opção desejada:"
          "\n [1] Cadastrar uma Compra: "
          "\n [2]  Buscar uma compra:  "
          "\n [3] Actualizar uma compra:  "
          "\n [4] Listar as Compras: "
          "\n [5] Interserir uma compra: ");
     printf("%d - Sair do programa",EXIT);
     printf("\nDigite a opcao: ");
     scanf("%d",&op);
     printf("-----------------------------------");
     }
     return op;
}
// Apresenta o segundo menu da aplicação e retorna a opção selecionada
int menu2()
{
    int op = 0;
    printf("Submenu - Gerenciar lista de compras\n");
    printf("");
    // complete com as demais opcoes...

    printf("%d Retornar para o menu principal",EXIT);
    printf("\nDigite a opcao: ");
    scanf("%d",&op); 
    return op;
}
printf("*********************************************************************");
// Permite o cadastro de um item (caso o produto ainda não exista) em uma lista de compas
Item* inserir(Item *arv, int quantidade, char produto) {
    if(arv == NULL) {
        Item *novo = (Item*)malloc(sizeof(Item));
        strcpy(novo->produto, produto);
        novo->quantidade = quantidade;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        return novo;
    } else {
        if( quantidade < arv-> quantidade && strcmp produto < arv->produto)
            arv->esquerdo = inserir(arv->esquerdo, quantidade && arv->esquerdo,produto);
        if( quantidade > arv -> quantidade && produto > arv-> produto);
            arv->direito = inserir(arv->direito, quantidade);
        return arv;
    }
}
printf("*********************************************************");


// Permite consultar se um item está em uma lista de compras
Item* query( Item *arv, int quantidade, char produto){
     if(arv){
          if(quantidade == arv->quantidade && produto == arv ->produto)
               return raiz;
          else if(quantidade < arv ->quantidade && produto < arv->quantidade)
           return inserir(arv ->esquerdo , quantidade, produto);
          else
               return inserir(raiz->direito, quantidade, produto);
          printf(" Foi  pesquisando com succeso ");
     
     }
     return arv;

}
printf("*****************************************************************");

// Permite a atualização da quantidade de um produto (caso exista) na lista de compras
Item* Update(Item *arv, int quantidade, char produto, int new_quanti, char new_pro)
{
     if(arv == NULL)
     return;
     if (arv ->quantidade = quantidade && arv ->produto == produto){
          arv -> quantidade = new_quanti && arv->produto = new_pro;
          return;
     }
     if( arv -> quantidade < quantidade)
          Update(arv->esquerdo, quantidade, new_quanti && arv->esquerdo, produto, new_pro);
          
     else
          Update(arv ->direito , quantidade,  new_quanti && arv ->direito, produto , new_pro);
printf("Actualização realizado com successo\n");
}


// Listar todos os itens da lista de compras em ordem alfabética;
void listar( Item *raiz){
     if(raiz ==NULL){
          listar(raiz->esquerdo);
          printf("%s , %d\n" , raiz->produto, raiz->quantidade);
          listar(raiz->direito);
     }
}
     printf("listando");
// Permite excluir um item de uma lista de compras
Item *deletar (Item *arv, int quantidade, char produto){
     if (arv == NULL){
          printf("Está vaziou\n Obrigada");
     
         return NULL;
     }
     else{
          if (arv ->quantidade == quantidade && arv ->produto == produto){
               free(arv);
               printf("Elemento foi removido com successo \n")
               return NULL;
          }
          else {
               if(quantidade < arv ->quantidade && produto < arv ->produto);
               
               arv ->esquerdo = deletar (arv ->esquerdo, quantidade && raiz->esquerdo , produto);
               else
                    arv->direito = deletar(arv ->direito, quantidade && arv ->direito, produto); 

          }
     }
     
}
Item* Inserir(Item *arv, int quantidade, char produto[50])
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
        arv->esquerdo = Inserir(arv->esquerdo, quantidade, produto);
    else
        arv->direito = Inserir(arv->direito, quantidade, produto);
    return arv;
}



// Programa principal
int main()
{
	
    int op, valor;
    char Pro[50];
    //int opcao2;

     Item *raizA = NULL;
     Item *raizB = NULL;
	
	
    
   

    /*opcao1 = 0;
    while (opcao1 != EXIT)
    {
          opcao1 = menu1();
               
          switch(opcao1)
          {
               case 1 : // gerenciar lista de compras A
                    opcao2 = 0;
                    while(opcao2 != EXIT){
                         printf("\n\n** Lista de Compras A **\n\n");*/
                        op= menu2();
                         switch(op){ // operacoes sobre a arvore A
                              case 1 : 
                                   printf("Digite um valor:\n");
                                   scanf("%d" , valor);
                                   printf("Digite um  produto:\n");
                                   scanf("%c",&Pro);    
                                   raizA= inserir(raizA, quantidade);
                                   raizB= inserir(raizB, produto);  
                                   break;
                              /*case 2 : 
                                   query();
                                   break;
                              case 3 : 
                                   update();
                                   break;
                              case 4 : 
                                   list();
                                   break;
                              case 5 : 
                                   delete();*/
                         }    
                    
                  /*  break;
               case 2 : // gerenciar lista de compras B
                    // idem ao caso 1, mas para a arvore B
               case 3 : // Visualizar itens duplicados
                    intersect();*/

       

return 0;
}
