#include <stdio.h>

int main() {
    int c[20], A = 0, B = 0;
    char a[9], b[8];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &c[i + 10]);
        c[c[i + 10]] = i;
    }
    scanf("%s %s", a, b);
    for (int i = 0; a[i]; i++) A = A * 10 + c[a[i] - 48];
    for (int i = 0; b[i]; i++) B = B * 10 + c[b[i] - 48];
    A += B;
    B = 0;
    while (A) {
        a[B++] = A % 10 + 48;
        A /= 10;
    }
    for (int i = 0; i < B / 2; i++) {
        char d = a[i];
        a[i] = a[B - i - 1];
        a[B - i - 1] = d;
    }
    a[B] = 0;
    for (int i = 0; a[i]; i++) a[i] = c[a[i] - 38] + 48;
    printf("%s", a);
}
