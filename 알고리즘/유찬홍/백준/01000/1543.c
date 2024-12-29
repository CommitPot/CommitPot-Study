#include <stdio.h>
#include <string.h>

int main() {
    char arr[2501], arr1[51];
    scanf("%[^\n]s", arr);
    scanf(" %[^\n]s", arr1);
    int len = strlen(arr), len1 = strlen(arr1), count = 0;
    char arr2[52];
    for (int i = 0; i < len; i++) {
        int k = 0;
        for (int j = i; j < i + len1; j++, k++) {
            arr2[k] = arr[j];
        }
        arr2[k] = 0;
        if (!strcmp(arr1, arr2)) {
            count++;
            i += len1 - 1;
        }
    }
    printf("%d", count);
    return 0;
}
