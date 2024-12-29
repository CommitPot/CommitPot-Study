#include <stdio.h>
#include <string.h>

int main() {
    char arr[101];
    scanf("%[^\n]s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        if (arr[i] > 64 && arr[i] < 91) {
            if (arr[i] + 13 < 91) arr[i] += 13;
            else arr[i] -= 13;
        } else if (arr[i] > 96 && arr[i] < 123) {
            if (arr[i] + 13 < 123) arr[i] += 13;
            else arr[i] -= 13;
        }
    }
    printf("%s", arr);
    return 0;
}