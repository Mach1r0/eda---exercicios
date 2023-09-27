#include <stdio.h>
 
int main(){
 int A, V, X, Y, infos[101], n = 0, i, maior;
 
 scanf("%i %i", &A, &V);
 
 while ( A != 0 && V != 0 ) {
  for (i=0; i <= A; i++) {
   infos[i] = 0;
  }
 
  for (i=0; i < V; i++) {
   scanf("%i %i", &X, &Y);
   infos[X]++;
   infos[Y]++;
  }
 
  maior = 0;
  for (i=1; i <= A; i++) {
   if (infos[i] >= maior) {
    maior = infos[i];
   }
  }
 
  n++;
  printf("Teste %i\n", n);
 
  for (i=0; i <= A; i++) {
   if (infos[i] == maior) {
    printf("%i ", i);
   }
  }
 
  printf("\n\n");
 
  scanf("%i %i", &A, &V);
 }
 
 return 0;
}
