#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARS 256 

typedef struct {
    char ascii;
    unsigned short frequencia;
} dados;

typedef struct node {
    char key;
    int count; 
    struct node* next;
} node_t;

typedef struct hashtable {
    node_t** table;
    int size; 
} hashtable_t;

unsigned int hash(char key) {
    return (unsigned int)key % MAX_CHARS;
}

node_t* create_node(char key, int count) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    assert(new_node != NULL);

    new_node->key = key;
    new_node->count = count;
    new_node->next = NULL;

    return new_node;
}

void insert_hashtable(hashtable_t* hashtable, char key, int count) {
    unsigned int index = hash(key);

    node_t* new_node = create_node(key, count);

    node_t* curr = hashtable->table[index];
    new_node->next = curr;
    hashtable->table[index] = new_node;
}

node_t* search_hashtable(hashtable_t* hashtable, char key) {
    unsigned int index = hash(key);

    node_t* curr = hashtable->table[index];
    while (curr != NULL && curr->key != key) {
        curr = curr->next;
    }

    return curr;
}

hashtable_t* init_hashtable() {
    hashtable_t* hashtable = (hashtable_t*)malloc(sizeof(hashtable_t));
    assert(hashtable != NULL);

    hashtable->size = MAX_CHARS;
    hashtable->table = (node_t**)malloc(hashtable->size * sizeof(node_t*));
    assert(hashtable->table != NULL);

    for (int i = 0; i < hashtable->size; i++) {
        hashtable->table[i] = NULL;
    }

    return hashtable;
}

void free_hashtable(hashtable_t* hashtable) {
    if (hashtable != NULL) {
        for (int i = 0; i < hashtable->size; i++) {
            node_t* curr = hashtable->table[i];
            while (curr != NULL) {
                node_t* next = curr->next;
                free(curr);
                curr = next;
            }
        }

        free(hashtable->table);
        free(hashtable);
    }
}

void quickSortInterno(dados *caractere, int inicio, int fim)
{
    dados pivo;
    dados temp;
    int i, j;

    if (fim - inicio > 0)
    {
        if (inicio < fim)
        {
            i = inicio;
            j = fim;
            pivo = caractere[(i + j) / 2];

            do
            {
                while (caractere[i].ascii < pivo.ascii) 
                    i++;
                while (caractere[j].ascii > pivo.ascii) 
                    j--;

                if (i <= j)
                {
                    temp = caractere[i];
                    caractere[i] = caractere[j];
                    caractere[j] = temp;
                    i++; j--;
                }

            } while (i <= j);

            quickSortInterno(caractere, inicio, j);
            quickSortInterno(caractere, i, fim);
        }
    }
}
void quickSort(dados *caractere, int tam) {
    quickSortInterno(caractere, 0, tam - 1);
}

void insertionSort(dados *caractere, unsigned short tam) {
    short i = 1, j;
    dados pivo;

    while (i < tam) {
        j = i - 1;
        pivo = caractere[i];

        while (j >= 0 && caractere[j].frequencia > pivo.frequencia) {
            caractere[j + 1] = caractere[j];
            j--;
        }

        caractere[j + 1] = pivo;
        i++;
    }
}

int main() {
    char str[1001];

    while (fgets(str, sizeof(str), stdin) != NULL) {
        hashtable_t* hashtable = init_hashtable();
        dados caractere[1001];
        unsigned short k = 0;

        str[strlen(str) - 1] = '\0';

        for (int i = 0; str[i] != '\0'; i++) {
            node_t* node = search_hashtable(hashtable, str[i]);
            if (node == NULL) {
                insert_hashtable(hashtable, str[i], 1);
            } else {
                node->count++;
            }
        }

        for (int i = 32; i < 128; i++) {
            node_t* node = search_hashtable(hashtable, (char)i);
            if (node != NULL) {
                caractere[k].ascii = node->key;
                caractere[k].frequencia = node->count;
                k++;
            }
        }

        quickSort(caractere, k);
        insertionSort(caractere, k);

        for (int i = 0; i < k; i++) {
            printf("%hhd %hu\n", caractere[i].ascii, caractere[i].frequencia);
        }

        free_hashtable(hashtable);

        printf("\n");
    }

    return 0;
}
