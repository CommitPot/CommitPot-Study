#include <stdio.h>
#include <string.h>


int main() {
    char arr[21];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (arr[i] != arr[j]) {
            printf("false");
            return 0;
        }
    }
    printf("true");
}