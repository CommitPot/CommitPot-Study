#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr[8], arr1[8];
    scanf("%s %s", arr, arr1);
    int min, max, len = strlen(arr);
    for (int i = 0; i < len; i++) {
        if (arr[i] == '6') arr[i] = '5';
        if (arr1[i] == '6') arr1[i] = '5';
    }
    min = atoi(arr) + atoi(arr1);
    for (int i = 0; i < len; i++) {
        if (arr[i] == '5') arr[i] = '6';
        if (arr1[i] == '5') arr1[i] = '6';
    }
    max = atoi(arr) + atoi(arr1);
    printf("%d %d", min, max);
    return 0;
}