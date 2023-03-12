#include<stdio.h>
#include<stdlib.h>


typedef no{
    int valor;
    struct no *proximo;
}No;
typedef Fila{
    No *ini;
    No *fim;
}Fila


void inserir(int valor, Item f){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        return 
    }
    else{
        novo ->valor = valor;
        novo->prox =NULL;
        if(f->ini == NULL){
            f->ini = novo;
        }
        else{
            f->ini-prox = novo;
        }
        f->fim =novo; 
    }
}

void Inserir(Fila *f , int valor){
    No *ptr = (No*)malloc(sizeof(No));
    if(ptr == NULL){
        printf("Erro de allocar!");
        return;
    }
    else{
        ptr->valor = valor ;
        ptr->prox = NULL;
        if(f->ini == NULL){
            f->ini = ptr;
        }
        else{
            f->fim->prox =ptr;
        }
        f->fim = ptr;
        }
     } 
    
}






typedef struct No{
    int dado;
    No *proximo;

}No

typedef Struct Pilha {
    No*topo;
}Pilha;

void inicializar(pilha *p){
    p->topo = NULL;
}

void empilha(int dado, pilha *p){
    No *ptr = (No*) malloc(sizeof)
    if(ptr ==NULL){
        return;
    }
    else{
        ptr->dado =dado;
        ptr->prox = p->topo;
        p->topo = prox;
    }
}

int desempilhar(pilha *p){
    no *ptr = p->topo;
    int dado;
    if(ptr == NULL){
        return 
    }
    else{
        p->topo = ptr->prox;
         ptr->prox = NULL;
        dado =ptr->dado;
        free(ptr);
        return dado;

    }
}