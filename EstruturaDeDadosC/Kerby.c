/*
 Este é um esqueleto que deve ser utilzado como base para implementação da Lista de tarefas;
	- As funções não têm os parâmetros definidos; se necessário, estes devem ser incluídos;
 	- Devem ser respeitados os nomes atribuidos aos métodos e estruturas, porém, novas estruturas e funções podem ser criadas, caso julgue necessário;
	- Faça os includes necessários;
	- A organização das funções fica a critério do programador;
	- Códigos não indentados sofrerão duras penalidades;
	- Não serão toleradas variaveis globais;
	- Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
typedef struct {
	int day;
	int month;
} Date;
// Estrutura que contém os campos dos registros das tarefas
struct REC {
       char nome[50];
       int prioridade;
       Date entrega; 
	  struct REC *next; // implemente como lista, como árvore BST, AVL...
	  struct REC *prev;
};

// Tipo criado para instanciar variaveis do tipo acima
typedef struct REC Task;
// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
    int op=0;
    while (op!=EXIT)
    {
         printf("***************************\n");
          printf("Digite a Opção desejada: "
          "\n [1] Cadastra tarefa na lista: "
          "\n [2] Delete tarefa na lista: "
          "\n [3] Editar uma tarefa na lista; "
          "\n [4] Consultar uma tarefa na lista: "
          "\n [5] Lista das tarefas: \n"
          );
          printf("[%d] Finaliza",EXIT);
          printf("\n: ");
          scanf("%d",&op);
          printf("***************************\n");
          break;
    }
    return op;
}

// Permite o cadastro de uma tarefa
Task *insTask(Task *tarefa)
{
    Task *aux, *new;
    new = (Task *)malloc(sizeof(Task));

    printf("Por favor digite o nome da tarefa\n");
    scanf("%s", new->nome);
    printf("Por favor digite a prioridade da tarefa\n");
    scanf("%d", &new->prioridade);
    printf("Por favor digite a data de entrega da tarefa\n");
    scanf("%d/%d", &new->entrega.day, &new->entrega.month);

    //fim da leitura dos dados
    if (tarefa == NULL)
    {
        tarefa = new;
        printf("-------------------------------------------------\n");
        printf("A sua nova entraga foi inserido com sucesso!\n");
        printf("-------------------------------------------------\n");
        return tarefa;
         //pois ele vai ser o primeiro elemento da lista.
    }
     
    {
        //lógica para adionar mais elementos.
        aux = tarefa;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        //chegou aqui, o aux tem o último elemento;
        aux->next = new;
        aux->next->next = NULL;
    }


    printf("-------------------------------------------------\n");
    printf("A sua nova entrega foi inserido com sucesso!\n");
    printf("-------------------------------------------------\n");


    return tarefa;
}

// Permite excluir uma tarefa
Task *delTask(Task *task, char *nome)
{
    Task *aux, *anterior = NULL;
    int cont;

    if (task == NULL)
    {
        printf("Infelizmente não temos tarefa!\n");
        return task;
    }

    for (aux = task; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->nome, nome) == 0)
        {
            
            if (task == aux)
            {
                task = aux->next;
            }
            else
            {
                anterior->next = aux->next;
            }
            free(aux);
            cont = 1;
             printf("-------------------------------------------------\n");
             printf("A sua nova tarefa foi excluido com sucesso!\n");
             printf("-------------------------------------------------\n");
        }
        else{
             printf("-------------------------------------------------\n");
             printf("Não encontramos essa tarefa!\n");
             printf("-------------------------------------------------\n");
        }
        anterior = aux;
    }
    if (!cont)
    {
        printf("Infelizmente não temos tarefa!\n");
    }
   
    return task;
}

// Lista o conteudo da agenda (todos os campos)
void listTasks(Task *task)
{   
  Task *aux;
  if(task == NULL){
    printf("Infelizmente não temos tarefa!\n");
    return; 
  } else{
       printf("-------------------------------------------------\n");
       printf("A tarefa cadastrados!!!\n");
       printf("-------------------------------------------------\n");
       aux = task;
      while(aux !=NULL){
          printf("-> %s, %d, %d/%d \n", aux->nome, aux->prioridade, aux->entrega.day, aux->entrega.month);
          aux = aux->next;
    }
  }
    
}

// Permite consultar uma tarefa da lista pelo nome
void *queryTask(Task *tarefa, char nome[50])
{  
    Task *aux;
    int cont;

    if (tarefa == NULL)
    {
        printf("Infelizmente não temos esse nome de tarefa!\n");
        return tarefa;
    }
    
    for (aux = tarefa; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->nome, nome) == 0)
        {
            printf("-------------------------------------------------\n");
            printf("Os dados do %s sâo!!!\n", nome);
            printf("-------------------------------------------------\n");

                printf("%s, %d, %d/%d\n", aux->nome, aux->prioridade, aux->entrega.day, aux->entrega.month);
            cont = 1;
        }else{
            printf("Infelizmente não temos esse nome de tarefa!\n");
        }
    }
    if (!cont)
    {
        printf("Infelizmente não temos esse nome de tarefa!\n");
    }
    
}

void setData(Date *dt, int d, int m)
{
     dt->day = d;
     dt->month = m;
}



// Permite a atualização dos dados de um contato da agenda
Task *upTask(Task *tarefa, char nome[50])
{
     Task *aux;
     int cont;
     int opcao;
     char *name;
     int *prioridade;
     int d, m;
     if (tarefa == NULL)
     {
          printf("Infelizmente não temos tarefa!\n");
     }

     for (aux = tarefa; aux != NULL; aux = aux->next)
     {
          if (strcmp(aux->nome, nome) == 0)
          {
               printf("--------------------------------\n");
               printf("Dgite 1 para alterar o nome da entrega ..!\n");
               printf("Dgite 2 para alterar a prioridade..!\n");
               printf("Dgite 3 para alterar a data de entrega..!\n");
               printf("--------------------------------\n");
               printf("\n");

               printf("Escholhe uma opçao...!\n");
               scanf("%d", &opcao);

               if (opcao == 1)
               {
                    nome = aux->nome;
                    printf("Digite o nome da tarefas: \n");
                    scanf("%s", nome);
                    printf("Nome alterado com sucesso..!\n");
                    printf("\n");
               }

               if (opcao == 2)
               {
                    prioridade = &aux->prioridade;
                    printf("Digite a prioridade: \n");
                    scanf("%d", prioridade);
                    printf("Prioridade alterado com sucesso..!\n");
                    printf("\n");
               }

               if (opcao == 3)
               {
                    printf("Digite a data de entrega: \n");
                    scanf("%d/%d", &d, &m);
                    setData(&aux->entrega, d, m );
                    printf("Data de entrega alterado com sucesso..!\n");
               }

               printf("Nome: %s\nPrioridade: %d\nData de entrega: %d/%d\n", aux->nome,  aux->prioridade, aux->entrega.day, aux->entrega.month);
               cont = 1;
               printf("\n");
          }else{
            printf("Infelizmente não temos esse nome de tarefa!\n");
        }
     }

     if (!cont)
     {
          printf("Infelizmente não temos tarefas!\n");
     }

     return tarefa;
}





// Programa principal
int main()
{
    Task *first = NULL;
    char nome[50];
    int op=0;
    Task t;

    while (op!=EXIT)
    {
          op=menu();
          switch(op)
          {
              case 1 : //insTask();
                   first = insTask(first);
                   printf("\n");
                   break;
              case 2 : //delTask();
                  printf("Por favor digite o nome da tarefa que você quer excluir\n");
                  scanf("%s", nome);
                  first = delTask(first, nome);
                  printf("\n");
                  break;
              case 3 : //upTask();
                    printf("Digite o nome da tarefa que voce quer editar\n");
                    scanf("%s", nome);
                    first = upTask(first, nome);
                    break;
              case 4 : //queryTask();
                   printf("Por favor digite o nome que você quer consultar\n");
                   scanf("%s", nome);
                   queryTask(first, nome);
                   printf("\n");
                   break;
              case 5 : //listTasks();
                   listTasks(first);
                   printf("\n");
                   break;

              
              
          }
    }
    return 0;
}