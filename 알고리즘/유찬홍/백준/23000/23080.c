#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[1001];
    scanf("%d %s", &n, arr);
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        if (i % n == 0) printf("%c", arr[i]);
    }
    return 0;
}