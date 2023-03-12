#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
    int id;
    char nome[31];
    double salario;
    struct funcionario *proximo;
}; 
typedef struct funcionario Funcionario;


//pascalCase Struct (classe)
//camelCase -> variavel e função(metodo)
//snale_Case->constante


Funcionario *insereNodoInicio(Funcionario *primeiro, int id, char nome[], double salario) {  
        Funcionario *novo;
                  
        
      
    // Complete aqui

    // Esta funcao deve retornar o primeiro da lista
}

Funcionario *insereNodoFim(Funcionario *primeiro, int id, char nome[], double salario) {
    // Complete aqui

    // Esta funcao deve retornar o primeiro da lista
}

Funcionario *deletaNodo(Funcionario *primeiro, int idDelete) {
    // Complete aqui

    // Esta funcao deve retornar o primeiro da lista
}

void imprimeLista(Funcionario *primeiro) {
    // Complete aqui
}

void imprimeAoContrario(Funcionario *aux) {
    // Complete aqui

    // Esta funcao deve ser recursiva
}

int contaNodos(Funcionario *primeiro) {
    // Complete aqui
}

void destroiLista(Funcionario *primeiro) {
    // Complete aqui
}

int main() {
    Funcionario *primeiro = NULL;

    primeiro = insereNodoInicio(primeiro, 54, "Bety", 5000);
    primeiro = insereNodoFim(primeiro, 59, "Bill", 1500);
    // Inserir mais nodos...

    imprimeLista(primeiro);

    imprimeAoContrario(primeiro);

    primeiro = deletaNodo(primeiro, 54);

    imprimeLista(primeiro);

    destroiLista(primeiro);

    return 0;
}
