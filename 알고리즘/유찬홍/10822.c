#include <stdio.h>
#include <string.h>

int main() {
    char arr[101];
    scanf("%s", arr);
    int sum = 0, j = 0, len = strlen(arr);
    for (int i = 0; i < len; i++) {
        if (arr[i] != ',' || i + 1 == len) {
            j = j * 10 + arr[i] - 48;
        } else {
            sum += j;
            j = 0;
        }
    }
    printf("%d", sum + j);
}
