#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 218 
#define MIN_ID -229    
#define MAX_ID 229   
#define MIN_QUANTITY -212 
#define MAX_QUANTITY 212 
typedef struct Item {
    long long int id;   
    long long int quantity; 
    struct Item* next;   
} Item;

typedef struct HashTable {
    Item* items[MAX_ITEMS];
    long long int capacity;
} HashTable;

long long int hashFunction(long long int id) {
    return ((unsigned long long)id * 2654435761) % MAX_ITEMS;
}

void insertItem(HashTable* table, long long int id, long long int quantity) {
    long long int index = hashFunction(id);
    
    Item* newItem = malloc(sizeof(Item));
    if (newItem == NULL) {
        exit(EXIT_FAILURE);
    }
    newItem->id = id;
    newItem->quantity = quantity;
    newItem->next = table->items[index];
    table->items[index] = newItem;
    table->capacity++;
}

void removeItem(HashTable* table, long long int id, long long int quantity) {
    long long int index = hashFunction(id);
    Item* current = table->items[index];
    Item* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        current->quantity -= quantity;

        if (current->quantity <= 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                table->items[index] = current->next;
            }
            free(current);
            table->capacity--;
        }
    }
}

long long int countItems(HashTable* table) {
    long long int total = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        Item* current = table->items[i];
        while (current != NULL) {
            total += current->quantity;
            current = current->next;
        }
    }
    return total;
}

int main() {
    HashTable table;
    for (int i = 0; i < MAX_ITEMS; i++) {
        table.items[i] = NULL;
    }
    table.capacity = 0;

    int numItems;
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        long long int id, quantity;
        scanf("%lld %lld", &id, &quantity);

        if (quantity > 0) {
            insertItem(&table, id, quantity);
        } else {
            removeItem(&table, id, -quantity);
        }
    }

    long long int remainingItems = countItems(&table);
    printf("%lld\n", remainingItems);

    for (int i = 0; i < MAX_ITEMS; i++) {
        Item* current = table.items[i];
        while (current != NULL) {
            Item* toFree = current;
            current = current->next;
            free(toFree);
        }
    }

    return 0;
}
