#include <stdio.h>
#include <string.h>

int main() {
    char arr[51];
    scanf("%s", arr);
    int sum = 10, len = strlen(arr);
    for (int i = 1; i < len; i++) sum += arr[i - 1] == arr[i] ? 5 : 10;
    printf("%d", sum);
    return 0;
}