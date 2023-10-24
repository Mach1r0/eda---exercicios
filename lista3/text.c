#include<stdio.h>
#include<stdlib.h>

typedef struct no {
int dado;
struct no *esq, *dir;
} no;

void pre_ordem (no *raiz){
p_pilha p; /* pilha de p_no */
p = criar_pilha();
empilhar(p, raiz);
while(!pilha_vazia(p)) {
raiz = desempilhar(p);
if (raiz != NULL) {
empilhar(p, raiz->dir);
empilhar(p, raiz->esq);
 printf("%d ", raiz->dado); /* visita raiz */
 }
 }
 destruir_pilha(p);
}