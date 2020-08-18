
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>


/*variáveis globais*/ 
int i = 0;
int flag;
int contador;
int l;
unsigned long long int primo;
unsigned long long int entrada[100];  

/*cria a trava*/ 
pthread_mutex_t trava;

void calculo_primo(unsigned long long int primos){
 
 
  unsigned long long int div = 0;

 
  for (unsigned long long int k = 1; k <= primos; k++) {
    if (primos % k== 0) { 
     div++;
    }
  }
    
  if (div == 2){
  contador = contador+1;
   }
 
 l = l -1;
	
}

void* funcao_thread(void *arg) {
  int *N = (int*)(arg);
  pthread_mutex_lock(&trava);
  
  primo = entrada[(l-1)];
  calculo_primo(primo);
    
  pthread_mutex_unlock(&trava);
    
  return NULL;
}
  


/*funcao que realiza a leitura dos numeros a serem analisados*/
void ler_vetor (void){
 
  char fim;
  
  /* Aloca memoria para o vetor entrada*/
      	

  do {
      scanf("%llu%c", &entrada[i], &fim);
      i++;
    } while(fim != '\n');

    

	
}	

 
int main(int argc, char **argv) {
  
  /*lê o vetor de entrada*/
  ler_vetor();
  
  /*cria variável auxiliar para percorrer vetor entrada*/ 
  l = i; 
       
  
  /*cria limitador de threads*/
  while (l > 0){ 
   int n;
   if (l>4){
     n=4;
   }
   else{
     n =l;
   }
      
   pthread_t threads[n];
   int thread_id[n];     
 
    
     /* Identificadores de thread */
  for (int j=0; j<n; j++) {
    thread_id[j] = j;
  }

  /* Disparanto threads */
  for (int j=0; j<n; j++) {
    pthread_create(&(threads[j]), NULL, funcao_thread, (void*) (&thread_id[j]));
  }

  /* Esperando threads */
  for (int j=0; j<n; j++) {
    pthread_join(threads[j], NULL);
  }

      
  }
  /*informa quantidade de primos*/
  printf("%d\n", contador);
  return 0;

}
