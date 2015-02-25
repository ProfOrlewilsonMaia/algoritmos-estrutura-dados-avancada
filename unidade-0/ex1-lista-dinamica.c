#include <stdio.h>

// Estrutura do N�
struct lista {
   int info;       
   struct lista *prox;
};

typedef struct lista Lista;


// Fun��o de cria��o: retorna uma lista vazia
Lista* lst_cria(void){
   return NULL;
}

// Fun��o que insere um novo elemento no come�o da lista
Lista* lst_insere (Lista *l, int i){
   Lista *novo = (Lista*) malloc(sizeof(Lista));
   
   novo->info = i;
   novo->prox = l;       
   
   return novo;
}


// Fun��o imprime: imprime valores dos elementos
void lst_imprime(Lista *l){
   
   Lista *p;  // Vari�vel auxiliar para percorrer a lista
   
   for (p = l; p != NULL; p = p->prox){
      printf("%d", p->info);    
      
      if (p->prox != NULL){
         printf("->");    
      }
   }
}

// Fun��o principal
int main(void){
  Lista *l;        // declara uma lista n�o inicializada
  
  l = lst_cria();  // cria e inicializa lista como vazia
  l = lst_insere(l,23); // insere na lista o elemento 23
  l = lst_insere(l,45); // insere na lista o elemento 45
  l = lst_insere(l,32); // insere na lista o elemento 32
  
  lst_imprime(l);
    
  getch();
  return 0;  
}
