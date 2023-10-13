#include <stdio.h>
#include <string.h>

int maxSubstring(char *str, char *sub, int str_len, int sub_len) {
    if (str_len < sub_len) {
        return 0;
    }

    if (strncmp(str, sub, sub_len) == 0) {
        int suffix_length = maxSubstring(str + sub_len, sub, str_len - sub_len, sub_len);
        return sub_len + suffix_length;
    } else {
        return maxSubstring(str + 1, sub, str_len - 1, sub_len);
    }
}

int main() {
    char str[101];
    char sub[101];
    
    if (scanf("%s", str) != 1 || scanf("%s", sub) != 1) {
        return 1;
    }

    int str_len = strlen(str);
    int sub_len = strlen(sub);
    
    int result = maxSubstring(str, sub, str_len, sub_len);
    
    printf("%d\n", result);
    
    return 0;
}
