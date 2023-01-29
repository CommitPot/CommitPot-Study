#include <stdio.h>
#include <string.h>

int main() {
   char S[1000001];

   char res;

   int arr[26] = {0,};

   int size = 0, max = 0;

   scanf("%s", S);

   size = strlen(S);

   for (int i = 0; i < size; i++) {
       if (S[i] >= 'a') { arr[S[i] - 'a']++; }
       else { arr[S[i] - 'A']++; }
   }

   for (int i = 0; i < 26; i++) {
       if (arr[i] == max) {
           res = '?';
       } else if (arr[i] > max) {
           max = arr[i];
           res = 'A' + i;
       }
   }

   printf("%c", res);

} 
