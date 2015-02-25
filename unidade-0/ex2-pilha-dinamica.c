#include <stdio.h>
#include <conio.h>

// Estrutura do Nó
struct No {
	int valor;
	struct No *prox; 
 };

typedef struct No TipoNo;

struct Pilha {
	TipoNo *topo;
	int tamanho; 
 };

typedef struct Pilha TipoPilha;

// Função que inicia a pilha
void IniciaPilha(TipoPilha *pilha)
{
  pilha->topo = NULL;
  pilha->tamanho = 0;
}

// Função que verifica se a pilha está vazia
int Vazia(TipoPilha *pilha)
{
    return (pilha->topo == NULL);
}

// Função que insere na pilha
void Push(int x, TipoPilha *pilha)
{
  TipoNo *aux;
  aux = (TipoNo *) malloc(sizeof(TipoNo));
  aux->valor = x;
  aux->prox = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho++;
}

// Função que remove da pilha
int Pop(TipoPilha *pilha){
  TipoNo *q; 
  int v;
  
  if (Vazia(pilha)) {
     printf("Lista vazia\n"); 
     return 0;
   }
   
   q = pilha->topo;
   pilha->topo = q->prox;
   v = q->valor;
   free(q);
   pilha->tamanho--;
   return v;
}

int main() {
  int i, numero, max=5;
  TipoPilha *pilha;
  pilha = (TipoPilha *) malloc (sizeof(TipoPilha));
  
  IniciaPilha(pilha);
  for (i=0;i<max;i++) {
    printf("Leitura do valor (%d) :",i);
    scanf("%d",&numero);
    Push(numero, pilha);
    printf("Empilhou: %d \n", numero); 
  }
  
  for(i=0;i<max;i++) {
     numero = Pop (pilha);
     printf ("Desempilhou: %d \n", numero);
  }
  getch();
}
