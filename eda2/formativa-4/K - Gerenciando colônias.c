#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashNode {
    int colony;
    char food[50];
    struct HashNode* next;
} HashNode;

#define TABLE_SIZE 1048576

unsigned int hash(int colony, const char* food) {
    unsigned int hashValue = colony;
    while (*food) {
        hashValue = (hashValue * 31) + *food;
        food++;
    }
    return hashValue % TABLE_SIZE;
}

HashNode* createHashNode(int colony, const char* food) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->colony = colony;
    strcpy(newNode->food, food);
    newNode->next = NULL;
    return newNode;
}

int checkAndInsert(HashNode** table, int colony, const char* food) {
    unsigned int index = hash(colony, food);
    HashNode* current = table[index];
    
    while (current != NULL) {
        if (current->colony == colony && strcmp(current->food, food) == 0) {
            return 1; 
        }
        current = current->next;
    }

    HashNode* newNode = createHashNode(colony, food);
    newNode->next = table[index];
    table[index] = newNode;
    return 0;
}

void freeTable(HashNode** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = table[i];
        while (current != NULL) {
            HashNode* toFree = current;
            current = current->next;
            free(toFree);
        }
    }
}

int main() {
    HashNode* table[TABLE_SIZE] = {NULL}; 
    int colony;
    char food[50];

    while (scanf("%d %s", &colony, food) != EOF) {
        if (checkAndInsert(table, colony, food)) {
            printf("%d\n", colony);
        }
    }

    freeTable(table);

    return 0;
}
