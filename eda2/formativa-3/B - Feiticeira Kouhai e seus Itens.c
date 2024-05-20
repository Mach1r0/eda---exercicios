#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ITEMS 220

typedef unsigned long long ULL;
typedef long long LL;

typedef struct bag {
  LL data;
  ULL code;
  struct bag *next;
} bag;

typedef struct hash {
  bag *data;
  ULL key;
} hash;

hash* hashTable;
ULL RANDOM;

// MurmurHash3 for potentially faster hashing (replace with your preferred function)
ULL murmurHash3_x86_32(ULL key) {
  ULL c1 = 0xcc9e2d51;
  ULL c2 = 0x1b873593;
  ULL h1 = key;

  h1 ^= c1;
  h1 = (h1 * 0x85ebca6b) >> 15;
  h1 ^= c2;

  h1 *= 5;
  h1 ^= (h1 >> 13);
  h1 *= 5;
  h1 ^= (h1 >> 12);
  h1 ^= key;

  return h1;
}

// Custom hash function using MurmurHash3 with a random seed
ULL custom_hash(ULL key) {
  return murmurHash3_x86_32(key + RANDOM);
}

hash* initHashTable(LL size) {
  hashTable = (hash*)malloc(sizeof(hash) * size);
  if (hashTable == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  for (LL i = 0; i < size; i++) {
    hashTable[i].data = NULL;
    hashTable[i].key = 0;
  }
  return hashTable;
}

ULL computeHashIndex(ULL key, LL size) {
  return llabs(custom_hash(key) % size);
}

bag* insertIntoHashTable(ULL key, LL data) {
  ULL index = computeHashIndex(key, MAX_ITEMS);
  bag* new_bag = (bag*)malloc(sizeof(bag));
  if (new_bag == NULL) {
    return NULL;
  }
  new_bag->data = data;
  new_bag->code = key;
  new_bag->next = NULL;

  if (hashTable[index].data != NULL) {
    bag *current = hashTable[index].data;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_bag;
  } else {
    hashTable[index].data = new_bag;
    hashTable[index].key = key;
  }
  return new_bag;
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
      if (prev != NULL) {
        prev->next = current->next;
      } else {
        hashTable[index].data = current->next;
      }
      free(current);
    }
  }
}

// Consider load factor management or pre-sizing if needed
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
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    solve();

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}
