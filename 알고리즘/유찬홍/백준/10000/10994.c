#include <stdio.h>

char a[401][401];

void f(int x, int y) {
    if (!y) return;
    int z = (y - 1) * 4 + 1;
    for (int i = x; i < x + z; i++) {
        if (i == x || i == x + z - 1) for (int j = x; j < x + z; j++) a[i][j] = '*';
        else a[i][x] = a[i][x + z - 1] = '*';
    }
    f(x + 2, y - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    f(0, n);
    for (int i = 0; i < (n - 1) * 4 + 1; i++) {
        for (int j = 0; j < (n - 1) * 4 + 1; j++) {
            printf("%c", a[i][j] == '*' ? '*' : ' ');
        }
        printf("\n");
    }
}
