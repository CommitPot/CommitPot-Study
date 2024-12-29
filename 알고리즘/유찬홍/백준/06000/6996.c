#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[101], arr1[101], arr2[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", arr, arr1);
        int len = strlen(arr), len1 = strlen(arr1), count = 0;
        strcpy(arr2, arr1);
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len1; k++) {
                if (arr[j] == arr1[k]){
                    arr1[k] = '0';
                    break;
                }
            }
        }
        for (int j = 0; j < len1; j++) {
            if (arr1[j] == '0') count++;
        }
        if (count == len1 && len == len1) printf("%s & %s are anagrams.\n", arr, arr2);
        else printf("%s & %s are NOT anagrams.\n", arr, arr2);
    }
}