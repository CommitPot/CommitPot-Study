#include <stdio.h>

int main() {
    int n, a, b;
    char s[1000001];
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %s", &a, &b, s);
        for (int i = 0; s[i]; i++) {
            s[i] = (a * (s[i] - 65) + b) % 26 + 65;
        }
        printf("%s\n", s);
    }
}
