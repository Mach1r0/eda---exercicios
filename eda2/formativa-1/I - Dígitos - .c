#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* add1(char* s){
    int len = strlen(s);
    char* res = (char*)malloc(len + 2);
    strcpy(res, s);
    int carry = 1;
    for(int i = len - 1; i >= 0; i--){
        int nv = (res[i] - '0') + carry;
        carry = 0;
        if(nv >= 10) carry = 1, nv -= 10;
        res[i] = '0' + nv;
    }
    if(carry){
        memmove(res + 1, res, len + 1);
        res[0] = '1';
    }
    return res;
}

int main(){
    char X[1001];
    int d;
    scanf("%d", &d);
    for(int i = 0; i < d; i++){
        char c;
        scanf(" %c", &c);
        X[i] = c;
    }
    X[d] = '\0';
    for(int t = 1; t <= d; t++){
        char A[1001];
        strncpy(A, X, t);
        A[t] = '\0';
        int curPos = 0;
        int ok = 1;
        char* num = (char*)malloc(strlen(A) + 1);
        strcpy(num, A);
        while(curPos < d){
            if(curPos + strlen(num) - 1 >= d){
                ok = 0;
                break;
            }
            for(int i = curPos; i < curPos + strlen(num); i++){
                if(X[i] != num[i - curPos]){
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
            curPos += strlen(num);
            char* temp = add1(num);
            free(num);
            num = temp;
        }
        free(num);
        if(ok){
            printf("%s\n", A);
            return 0;
        }
    }
    return 0;
}