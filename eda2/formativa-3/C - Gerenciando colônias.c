#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
typedef long long ll; 
#define MAX 0x1007D0
#include <limits.h>

typedef struct linkedlist{
    ll node; 
    char *word; 
    struct linkedlist* prox; 
} linkedlist; 

typedef struct hash{
    linkedlist *data; 
    int key; 
} hash;

uint64_t slash_hash(const char *s)
{
    union { uint64_t h; uint8_t u[8]; } uu;
    int i=0; uu.h=strlen(s);
    while (*s) { uu.u[i%8] += *s + i + (*s >> ((uu.h/(i+1)) % 5)); s++; i++; }
    return uu.h; //64-bit
}

uint64_t combine(uint64_t a, uint64_t b) {
    uint64_t result = a + b;
    result ^= b + 0x9e3779b9 + (result << 6) + (result >> 2);
    return result;
}

uint64_t hashing(ll node, char *str){
    uint64_t hash_value = slash_hash(str);
    hash_value = combine(hash_value, node);
    return hash_value % MAX;
}

hash * inithashing(int size){
    hash* newhash = (hash*) malloc(size * sizeof(hash));
    for (int i = 0; i < size; i++){
        newhash[i].key = 0; 
        newhash[i].data = NULL; 
    }
    return newhash; 
}

void insertHashing(hash *h, ll colony, char *word){
    linkedlist *newnode = (linkedlist*) malloc(sizeof(linkedlist)); 
    newnode->node = colony;
    newnode->word = strdup(word); 
    newnode->prox = NULL; 

    int index = hashing(colony, word);
    newnode->prox = h[index].data;
    h[index].data = newnode;
}

linkedlist* searchintoHash(hash *h, char *str, ll node){
    int current = hashing(node, str); 
    linkedlist *currentNode = h[current].data;
    while (currentNode != NULL){
        if (currentNode->node == node && strcmp(currentNode->word, str) == 0){
            return currentNode;
        }
        currentNode = currentNode->prox;
    }
    return NULL; 
}

void solve(){
    hash *h = inithashing(MAX); 
    ll n; 
    char word[200];
    while (scanf("%lld %s", &n, word) != EOF){
        linkedlist *node = searchintoHash(h, word, n);
        if (node != NULL){
            printf("%lld\n", n);
        } else {
            insertHashing(h, n, word);
        }
    }    
}

int main(){
    solve(); 
    return 0; 
}
