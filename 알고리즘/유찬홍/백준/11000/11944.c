#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int m, c = 0;
    char arr[5];
    scanf("%s %d", arr, &m);
    if (atoi(arr) * strlen(arr) > m) {
        for (int i = 0; i < m; i++) {
            printf("%c", arr[c++]);
            if (c == strlen(arr)) c = 0;
        }
    } else {
        for (int i = 0; i < atoi(arr) * strlen(arr); i++) {
            printf("%c", arr[c++]);
            if (c == strlen(arr)) c = 0;
        }
    }
    return 0;
}