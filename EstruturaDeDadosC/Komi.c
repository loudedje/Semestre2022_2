#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

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
    char nome[50];
    struct duplicado *proximo;
};
typedef struct duplicado Duplicado;


// Posiçaõ de uma lettra na ordem alfabética
int search (char carac){
  int i;
  char alfabetos[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  for (i = 0; alfabetos[i] != '0'; i++)
    if (alfabetos[i] == carac)
      return i + 1;
}

//Compação para ordenação alfabética
char* comparado (char fruto1[50], char fruto2[50]){
    for (int i = 0; i < 50; i++){
        if(fruto1[i] == '\0'){
            return fruto1;
        }
        else if(fruto2[i] == '\0') {
            return fruto2;
        }
        if ((search (fruto1[i])) > (search (fruto2[i]))){
            return fruto2;
        }
        else if ((search (fruto1[i])) < (search (fruto2[i]))){
            return fruto1;
	    }
    }
}
//Pesquisar se um produto esta na lista de compra 
Item* PesquisarProduto(Item *raiz,char nome[50]){
    if (raiz){
        if(strcmp(nome,raiz->produto ) ==0){
        return raiz;
    }
    else if(comparado(raiz->produto,nome)!= raiz->produto){
        return PesquisarProduto(raiz->esquerdo,nome);
    }
    else{
        return PesquisarProduto(raiz->direito,nome);
        }
    }
    return NULL;
}


//Insercão de produto na lista de compra 
//versao 2 
Item* inserirElemento(Item *raiz,char nome[50],int qte){
        if(raiz == NULL){
        Item *novo = malloc(sizeof(Item));
        strcpy(novo->produto,nome);
        novo->quantidade = qte;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        return novo;
        }
        else{
            if(comparado(raiz->produto,nome)!= raiz->produto){
                raiz->esquerdo = inserirElemento(raiz->esquerdo, nome, qte);
            }
            else{
                (raiz->direito = inserirElemento(raiz->direito, nome,qte));
            }
            return raiz;
        }
}

//Atualizar a quantidade de um produto
void AtualizarQte(Item *raiz,char nome[50]){
    Item *busca;
    int novaqte = 0;
    busca = PesquisarProduto(raiz,nome);
    if(busca != NULL){
        printf("\tProduto : %s\n\tQte : %d\n\n",busca->produto,busca->quantidade);
        printf("Nova quantidade do produto: ");
        scanf("%d",&novaqte);
        busca->quantidade = novaqte;
        printf("\n\t*-*- PRODUTO ATUALIZADO COM SUCESSO  *-*- \n");
    }
    else{
        printf("\n\t*-*- PRODUTO NAO CADASTRADO  *-*- \n");  
    }
}

//Listar os produtos em ordem alfabética
void InOrden(Item *raiz){
    if(raiz == NULL){
        return;
    }
    else{
        InOrden(raiz->esquerdo);
        printf("%-15s %10d\n", raiz->produto,raiz->quantidade);
        InOrden(raiz->direito);
    }
}

// //Remover um produto da lista
//versao 2 
Item* RemoverProduto(Item *raiz, char nome[50]){
    if(raiz == NULL){
        printf("Produto nao encontrado\n");
        return NULL;
    }
    else{
        if(strcmp(raiz->produto,nome)== 0){
            int qte = raiz->quantidade;
            if(raiz->esquerdo == NULL && raiz->direito == NULL){
            free(raiz);
            return NULL;
            }
            else{
                if(raiz->esquerdo != NULL && raiz->direito != NULL){
                    Item *aux = raiz->esquerdo;
                    while(aux->direito!= NULL){
                        aux = aux->direito;
                    }
                    strcpy(raiz->produto,aux->produto);
                    raiz->quantidade = aux->quantidade;                    
                    strcpy(aux->produto,nome);
                    raiz->esquerdo = RemoverProduto(raiz->esquerdo,nome);
                    return raiz; 
                }
                else{
                    Item *aux;
                    if(raiz->esquerdo !=NULL){
                        aux = raiz->esquerdo;
                    }
                    else{
                        aux = raiz->direito;
                    }
                    free(raiz);
                    return aux;
                }
            }
        }
        else{
            if(comparado(raiz->produto,nome)!=raiz->produto){
                raiz->esquerdo = RemoverProduto(raiz->esquerdo, nome);
            }
            else{
                raiz->direito = RemoverProduto(raiz->direito,nome);
            }
            return raiz;
        }
    }
}


//Visitat a lista em PreOrdem
void PreOrden(Item *raiz){
    if(raiz == NULL){
        return;
    }
    else{
        printf("Para compra : %s\t , Qte = %d\n", raiz->produto,raiz->quantidade);
        PreOrden(raiz->esquerdo);
        PreOrden(raiz->direito);
    }
}

//Para inserir no fim da lista encadeada
Duplicado* inserirNoFim(Duplicado *primeiro, char nome[50]){
    Duplicado *aux;
    Duplicado *novo = malloc(sizeof(Duplicado));
    if(novo){
        strcpy(novo->nome,nome);
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
        printf("Error ao allocar memoria\n");
    }
}


//Para criar a lista encadeada dos produtos duplicados 
Duplicado* inter(Duplicado *primeiro,Item *raizA,Item *raizB){
    Item *busca;
    char nome[50];
    if(raizA == NULL || raizB == NULL ){
        return NULL;
    }
    else{
        strcpy(nome,raizA->produto);
        busca = PesquisarProduto(raizB,nome);
        if(busca != NULL){
            primeiro = inserirNoFim(primeiro,nome);
        }
        inter(primeiro,raizA->esquerdo,raizB);
        inter(primeiro,raizA->direito,raizB);
        return primeiro;
    }
} 

//Para imprimir a lista enccadeada
void ImprimeLista(Duplicado *primeiro){
    Duplicado *aux;
    int cont = 1;
        printf("-----====-----====-----====-----====-----====-----====\n\n");
    for(aux = primeiro;aux != NULL;aux = aux->proximo){
        printf("%d-\t%s\n",cont,aux->nome);
        cont +=1;
    }
}



// Apresenta o primeiro menu da aplicação e retorna a opção selecionada
int menu1()
{
    char valor[20];
    int i,op;
    int opt = 1;
    char nome[4][20] = {"1","2","3","10"};
    printf("\nMenu principal:\n\n");
    printf("\t [1] - Gerenciar Lista de Compra A\n");
    printf("\t [2] - Gerenciar Lista de Compra B\n");
    printf("\t [3] - Ver produtos diplicados nas duas listas\n");
    printf("\t [10]- Sair do programa\n");
    
    while(opt== 1){
        printf("\nDigite a opcao: ");
        scanf("%s",valor);
        for(i = 0;i<4;i++){
            if(strcmp(valor,nome[i])==0){
                opt = 2;
                break;
            }
        }
        if(opt != 2){
            printf("\n\t*-*- DIGITE UMA OPCAO VALIDA  *-*- \n");
        }
    }
    op = atoi(valor);
    return op;
}


// Apresenta o segundo menu da aplicação e retorna a opção selecionada
int menu2()
{
    char valor[20];
    int i,op;
    int opt = 1;
    char nome[6][20] = {"1","2","3","4","5","10"};
    printf("Submenu - Gerenciar lista de compras \n\n");
    printf("\t [1] - Inserir um produto na lista de compra\n");
    printf("\t [2] - Pesquisar um produto na lista de compra\n");
    printf("\t [3] - Atualizar a quantidade de um produto na lista de compra\n");
    printf("\t [4] - Listar os produtos da lista de compra\n");
    printf("\t [5] - Deletar um produto da lista de compra\n");
    printf("\t [10]-  Retornar para o menu principal\n");
    
    while(opt== 1){
        printf("\nDigite a opcao: ");
        scanf("%s",valor);
        for(i = 0;i<6;i++){
            if(strcmp(valor,nome[i])==0){
                opt = 2;
                break;
            }
        }
        if(opt != 2){
            printf("\n\t*-*-   DIGITE UMA OPCAO VALIDA    *-*-\n");
        }
    }
    op = atoi(valor);
    return op;
}

// Permite o cadastro de um item (caso o produto ainda não exista) em uma lista de compas
Item* insert(Item *raiz)
{
    char nome_produto[30];
    int quantidade;
    printf(" INSERCAO...\n\n");
    // printf("\tNome do produto : ");
    // fgets(nome_produto,30,stdin);
    // scanf("%s",nome_produto);
    if(PesquisarProduto(raiz,nome_produto) == NULL){
        printf("\tQuantidade do produto : ");
        scanf("%d",&quantidade);
        raiz = inserirElemento(raiz,nome_produto,quantidade);
        printf("%s inserido com sucesso\n",nome_produto);
        return raiz;
    }
    else{
            printf("\n\t*-*- PRODUTO JA CADASTRADO  *-*- \n");
        return raiz;
    }
}

    
// Permite consultar se um item está em uma lista de compras
void query(Item *raiz)
{
    Item *busca;
    char nome[50];
    printf(" BUSCANDO...\n\n");
    printf("\tNome do produto procurando: ");
    fgets(nome,50,stdin);
    // scanf("%s",nome);
    busca = PesquisarProduto(raiz,nome);
    if(busca!= NULL){
        printf("\n\t*-*- PRODUTO ENCONTRADO  *-*- \n");
        printf("\tProduto : %s\n\tQte : %d\n",busca->produto,busca->quantidade);
    }
    else{
        printf("\n\t*-*- PRODUTO NAO ENCONTRADO  *-*- \n");
    }
    return;
}


// Permite a atualização da quantidade de um produto (caso exista) na lista de compras
void update(Item *raiz)
{
    printf(" ATUALIZANDO...\n\n");
    char nome[50];
    printf("\tNome do produto a atualizar: ");
    fgets(nome,50,stdin);
    // scanf("%s",nome);
    AtualizarQte(raiz,nome);
    return;
}


// Listar todos os itens da lista de compras em ordem alfabética;
void list(Item *raiz)
{
    printf("LISTANDO OS PRODUTOS...\n");
    printf("------------------------------------\n");
    printf("Nome                Quanitdade\n");
    printf("------------------------------------\n");
    InOrden(raiz);
    return;
}


// Permite excluir um item de uma lista de compras
Item* delete(Item *raiz)
{
    char nome[50];
    printf("Nome do produto a excluir : ");
    fgets(nome,50,stdin);
    // scanf("%s",nome);
    raiz = RemoverProduto(raiz,nome);
    printf("\n\t*-*-   PRODUTO REMOVIDO COM SUCESSO    *-*-\n");
    return raiz;
}

void intersect(Item *raizA,Item *raizB)
{
    Duplicado *primeiro = NULL;
    printf("interseccao\n");
    primeiro = inter(primeiro,raizA,raizB);
    ImprimeLista(primeiro);
    
}



// Programa principal
int main()
{
    int opcao1;
    int opcao2;
    Item *raiz = NULL;
    Item *raizA = NULL;
    Item *raizB = NULL;
    Duplicado *primeiro = NULL;

    opcao1 = 0;
    while (opcao1 != EXIT)
    {
        opcao1 = menu1();
               
        switch(opcao1)
        {
            case 1 : // gerenciar lista de compras A
                opcao2 = 0;
                while(opcao2 != EXIT){
                    printf("\n\n***** Lista de Compras A *****\n\n");
                    opcao2 = menu2();
                    switch(opcao2){ // operacoes sobre a arvore A
                    case 1 : 
                        raizA = insert(raizA);
                        break;
                    case 2 : 
                        query(raizA);
                        break;
                    case 3 : 
                        update(raizA);
                        break;
                    case 4 : 
                        list(raizA);
                        break;
                    case 5 : 
                        raizA = delete(raizA);
                        break;
                    default:
                        printf("Digite um numero valido");
                        break;
                    }    
                }
                break;
            case 2 : // gerenciar lista de compras B
                    opcao2 = 0;
                while(opcao2 != EXIT){
                    printf("\n\n** Lista de Compras B **\n\n");
                    opcao2 = menu2();
                    switch(opcao2){ // operacoes sobre a arvore A
                    case 1 : 
                        raizB = insert(raizB);
                        break;
                    case 2 : 
                        printf("Procurando\n");
                        query(raizB);
                        break;
                    case 3 : 
                        printf("Atualizando\n");
                        update(raizB);
                        break;
                    case 4 : 
                        printf("Listando\n");
                        list(raizB);
                        break;
                    case 5 : 
                        printf("Deletando\n");
                        raizB = delete(raizB);
                        break;
                    default:
                        printf("Digite um numero valido");
                        break;
                    }    
                }
                break;
            case 3 : // Visualizar itens duplicados
                    intersect(raizA,raizB);
                    break;

          }
    }
    return 0;
}