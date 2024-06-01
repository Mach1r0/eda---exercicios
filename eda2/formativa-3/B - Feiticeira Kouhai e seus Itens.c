#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ITEMS 220
typedef unsigned long long ULL;
typedef long long LL;
typedef struct bag {
    LL data;
    LL code;
    struct bag *next;
} bag;
typedef struct hash {
    bag *data;
    ULL key;
} hash;
hash* hashTable;
ULL RANDOM; 
ULL splitmix64(ULL key) {
    key += 0x9e3779b97f4a7c15;
    key = (key ^ (key >> 30)) * 0xbf58476d1ce4e5b9;
    key = (key ^ (key >> 27)) * 0x94d049bb133111eb;
    return key ^ (key >> 31);
}
ULL custom_hash(ULL key) {
  return key % MAX_ITEMS;
}
hash* initHashTable(LL size) {
    hashTable = (hash*) calloc(size, sizeof(hash));
    if (hashTable == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return hashTable;
}
ULL computeHashIndex(ULL key, LL size) {
    return llabs(custom_hash(key) % size);
}

bag* insertIntoHashTable(ULL key, LL data) {
    ULL index = computeHashIndex(key, MAX_ITEMS);
    bag* newBag = (bag*) malloc(sizeof(bag));
    newBag->code = key;
    newBag->data = data;
    newBag->next = hashTable[index].data;
    hashTable[index].data = newBag;
    hashTable[index].key = key;
    return newBag;
}

void removeFromHashTable(ULL key, LL data) {
  ULL index = computeHashIndex(key, MAX_ITEMS);
  bag* current = hashTable[index].data;
  bag* prev = NULL;
  while (current != NULL && current->code != key) {
    prev = current;
    current = current->next;
  }
  if (current != NULL) {
    current->data -= data;
    if (current->data <= 0) {
      if (prev == NULL) {
        hashTable[index].data = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
    }
  }
}

LL countTotalItems() {
    LL total = 0;
    for (LL i = 0; i < MAX_ITEMS; i++) {
        bag* current = hashTable[i].data;
        while (current != NULL) {
            total += current->data;
            current = current->next;
        }
    }
    return total;
}

void solve() {
  LL n;
  scanf("%lld", &n);
  initHashTable(MAX_ITEMS);
  RANDOM = (ULL)time(NULL); 
  for (LL i = 0; i < n; i++) {
    LL data;
    ULL code;
    scanf("%llu %lld", &code, &data);
    if (data > 0) {
      insertIntoHashTable(code, data);
    } else {
      removeFromHashTable(code, -data);
    }
  }
  LL items = countTotalItems();
  printf("%lld\n", items);
  for (LL i = 0; i < MAX_ITEMS; i++) {
    bag* current = hashTable[i].data;
    while (current != NULL) {
      bag* temp = current;
      current = current->next;
      free(temp);
    }
  }
  free(hashTable);
}

int main() {
    solve();
    return 0;
}