#include <stdio.h>

// Estrutura do N�
struct No{
     int dado;
     struct No *prox;
};

typedef struct No TipoNo;

//Criando o tipo fila
struct Fila {      
	TipoNo *inicio;
	TipoNo *final;
};

typedef struct Fila TipoFila;

//Declarando os prot�tipos das fun��es
void cria_fila (TipoFila *F);                  
int fila_vazia (TipoFila *F);                   
int primeiro_fila (TipoFila *F, int *dado);    
int inserir_fila (TipoFila *F, int);
int remover_fila (TipoFila *F, int *valor);
void imprime_fila(TipoFila *F);

// Fun��o que cria uma fila vazia
void cria_fila (TipoFila *F)
{
   F->inicio = F->final = NULL;
}

// Fun��o que verifica se a fila est� vazia
int fila_vazia (TipoFila *F)
{
   if(F->inicio == NULL && F->final == NULL) return 1;
   else return 0;
}


// Inser��o de um novo elemento na fila
int inserir_fila (TipoFila *F, int valor){
   TipoNo *novo;

   novo = (TipoNo*) malloc(sizeof(TipoNo));
   
   //Atribui��o do valor e apontando o pr�ximo para NULL
   novo->dado = valor;      
   novo->prox = NULL;       

   // Se a fila estiver vazia, o novo n� sera o primeiro 
   // da fila
   if (fila_vazia(F)){ F->inicio = novo; }
   else{ (F->final)->prox = novo; }

   // Sen�o, o ponteiro para o final da fila apontar� 
   // para o novo n�
   F->final = novo;             
 
   return 1;
}
 
// Fun��o de remo��o
int remover_fila (TipoFila *F, int *valor)
{
   TipoNo *aux;
   
   // Retorna o conte�do do primeiro da fila
   primeiro_fila(F,valor);        
   
   // Se existir somente um n� na fila, apontamos 
   // o final da fila para NULL
   if (F->inicio == F->final){
      F->final = NULL;
   }
   
   // Atribu�mos o n� retornado da fila ao n� auxiliar 
   aux = F->inicio;               
   
   // O in�cio da fila apontar� para o pr�ximo n� 
   // do que estamos removendo
   F->inicio = (F->inicio)->prox; 
   free(aux);                   
   return 1;
}

//Fun��o que obt�m o primeiro elemento da fila
int primeiro_fila (TipoFila *F, int *dado){

   if (fila_vazia(F)) 
      return 0;
   
   *dado = (F->inicio)->dado;
   
   return 1;
}

// Imprime valores da fila
void imprime_fila(TipoFila *F){
   
   TipoNo *temp;  // Vari�vel auxiliar para percorrer a fila
   
   for (temp = F->inicio; temp != NULL; temp = temp->prox){
      printf("%d", temp->dado);    
      if (temp->prox != NULL){
         printf("<-");    
      }
   }
   printf("\n");
}

int main() {
  TipoFila doc;                                  
  int a;
  
  cria_fila(&doc);   
  inserir_fila (&doc ,10);
  inserir_fila (&doc ,2);
  inserir_fila (&doc ,3);
  inserir_fila (&doc ,4);
  inserir_fila (&doc ,5);  
  inserir_fila (&doc ,5);  
  
  // Imprime a Fila
  printf("Imprimindo elementos da Fila \n");  
  imprime_fila(&doc);
  
  // Remove da Fila
  printf("\nRemovendo elemento da Fila \n");  
  while(!fila_vazia(&doc)){
    remover_fila(&doc,&a);      
    printf("Removido: %d\n", a);  
  }
  getch();
}



