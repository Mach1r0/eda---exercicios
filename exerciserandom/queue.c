#include<stdio.h>
#include<stdlib.h>
#define MAX 500;

typedef struct queue{
    int data[MAX];
    int *first;
    int *last;
    int total;
} queue;

void createqueue(queue* le){
    first = last = 0;
    total = 0;
    return queue;
}

int pop(queue *le, int x){
    return le[last++] = x;
    total++;
}

void push(queue* le){
    return le[first++];
    total--;
}

bool empty(queue *le){
    if (le[first] == 0){
        return true
    }
    return false;
}

bool full(queue *le){
    if (le->last == total){
        return true;
    }
    return false;
}

int total(queue* le){
    return total;
}