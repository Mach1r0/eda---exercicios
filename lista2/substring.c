#include <string.h>

int strDist(char* str, char* sub) {

  if(strlen(str) < strlen(sub)) return 0;

  if(strncmp(str, sub, strlen(sub)) == 0) {
    if(strncmp(str + strlen(str) - strlen(sub), sub, strlen(sub)) == 0) {
      return strlen(str);
    } else {
      return strDist(strndup(str, strlen(str) - 1), sub);
    }
  }
  
  return strDist(str + 1, sub);
}

int main(){
    char str[101];
    char sub[101];

    scanf("%s", str);
    scanf("%s", sub);
    
    int result = strDist(str, sub);
    printf("%d\n", result);
}