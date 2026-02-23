#include <stdio.h>

int main() {
    int a, b, l = 0;
    char s[21] = {};
    scanf("%d %d", &a, &b);
    if (!a) printf("0");
    else {
        while (a) {
            s[l++] = a % b + (a % b < 10 ? 48 : 55);
            a /= b;
        }
        for (int i = 0, j; i < l - i - 1; i++) j = s[i], s[i] = s[l - i - 1], s[l - i - 1] = j;
        printf("%s", s);
    }
}
