#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize);

int main() {
  char *strs[200] = {"flower","flower","flower","flower"};
  int i = 0;
  while (strs[i] != NULL) {
    printf("%s\n", strs[i]);
    i++;
  }
  char * print = longestCommonPrefix(strs, i);
  printf("%s", print);
  return 0;
}

char *longestCommonPrefix(char **strs, int strsSize) {
   if (strsSize == 0) {return "";}
   else if (strsSize == 1) {return strs[0];} 
   if (strlen(strs[0]) < 1)
   {
    return "";
   }
  int symbol = strlen(strs[0]);
  char result[symbol];
  int flag;
  int i , j;
  for (i= 0; i < symbol; i++) {
    flag = 1;
    for (j = 1; j < strsSize; j++) {
      if (strs[0][i] != strs[j][i])
      { flag = 0;
        break; 
      } 
    }
    if (flag == 1)
    {
     result[i] = strs[0][i];
    } else {
     break; 
    }
  }
   result[i] = '\0';
  char *result_ptr = malloc(symbol * sizeof(char));
  result_ptr = result;
  return result_ptr;
}