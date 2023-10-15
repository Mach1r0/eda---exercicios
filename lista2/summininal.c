#include <stdio.h>
#include <stdlib.h>

int ultimo_valor(int *vet, int index, int lim, int soma, int cont) {
  if (index == cont) return;
  soma = vet[index] + soma;
  if (soma > lim) {
    ultimo_valor(vet, index+1, lim, 0, cont);
    printf("%d\n", vet[index]);
  }
  else {
  }
}

int main() {
  int num, vet[150000], cont = 0;
  while (scanf("%d", &num) && num != 0) vet[cont++] = num;
  scanf("%d", &num);
  ultimo_valor(vet, 0, num, 0, cont);
}