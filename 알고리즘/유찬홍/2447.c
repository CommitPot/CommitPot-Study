#include <stdio.h>

char a[6562][6562];

void f(int n, int x, int y, char w) {
    if (n == 1) {
        a[x][y] = w;
        return;
    }
    n /= 3;
    f(n, x, y, w);
    f(n, x, y + n, w);
    f(n, x, y + n * 2, w);
    f(n, x + n, y, w);
    f(n, x + n, y + n, ' ');
    f(n, x + n, y + n * 2, w);
    f(n, x + n * 2, y, w);
    f(n, x + n * 2, y + n, w);
    f(n, x + n * 2, y + n * 2, w);
}

int main() {
    int n;
    scanf("%d", &n);
    f(n, 0, 0, '*');
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
}
