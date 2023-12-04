#include<stdio.h>
#include<stdlib.h>

void count_and_print(char *v, int n){
    int count = 1;
    int remaining = 0;
    for (int i = 1; i < n; i++){
        if (v[i] == v[i-1]){
            count++;
        } else {
            printf("%d %c %d\n", count, v[i-1], n - i);
            count = 1;
        }
    }
    printf("%d %c %d\n", count, v[n-1], 0);
}  

int main(void){
    char l [100000];
    int n = 0;
    while (scanf("%c", &l[n]) != EOF && l[n] != '\n') {
        n++;
    }
    count_and_print(l, n);
    return 0;
}