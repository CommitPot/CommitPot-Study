#include <stdio.h>
#include <string.h>

int main() {
    char arr[1000], arr1[1000], tmp[1000];
    scanf("%s %s", arr, arr1);
    while (strcmp(arr, arr1)) {
        int len1 = strlen(arr1);
        if (arr1[len1 - 1] == 'A') {
            arr1[len1 - 1] = (char) 0;
        } else if (arr1[len1 - 1] == 'B') {
            arr1[len1 - 1] = (char) 0;
            strcpy(tmp, arr1);
            for (int i = len1 - 2, j = 0; i >= 0; i--, j++) {
                arr1[j] = tmp[i];
            }
        } else {
            printf("0");
            return 0;
        }
    }
    printf("1");
}
