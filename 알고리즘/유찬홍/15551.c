#include <stdio.h>

int main() {
    int n;
    char a[101] = "Aa", b[101] = "BB";
    scanf("%d", &n);
    for (int i = 2; i < n; i++) a[i] = b[i] = '1';
    printf("%s\n%s", a, b);
}
