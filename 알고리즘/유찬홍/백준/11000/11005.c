#include <stdio.h>

int main() {
    char arr[101];
    int n, b, c = 0;
    scanf("%d %d", &n, &b);
    while (n > 0) {
        int a = n % b;
        if (a < 10) arr[c++] = (char) (48 + a);
        else arr[c++] = (char) (a + 55);
        n /= b;
    }
    for (int i = c - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }
}