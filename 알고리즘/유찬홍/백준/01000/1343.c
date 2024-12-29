#include <stdio.h>
#include <string.h>

int main() {
    char arr[51];
    int count = 0;
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i <= len; i++) {
        if (arr[i] == 'X') count++;
        else if (arr[i] != 'X' || arr[i] == NULL) {
            count %= 4;
            if (count == 1 || count == 3) {
                printf("-1");
                return 0;
            } else if (count == 0) continue;
            else {
                arr[i - 1] = arr[i - 2] = 'B';
                count = 0;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (arr[i] == 'X') arr[i] = 'A';
    }
    printf("%s", arr);
    return 0;
}