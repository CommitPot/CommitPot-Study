#include <stdio.h>
#include <math.h>

char m[3125][3126];

void f(int x, int y, int l, char a) {
    if (l == 0) {
        m[x][y] = a;
        return;
    }
    x *= 5;
    y *= 5;
    l--;
    f(x, y, l, ' ');
    f(x, y + 1, l, ' ');
    f(x, y + 2, l, a);
    f(x, y + 3, l, ' ');
    f(x, y + 4, l, ' ');
    f(x + 1, y, l, ' ');
    f(x + 1, y + 1, l, ' ');
    f(x + 1, y + 2, l, a);
    f(x + 1, y + 3, l, ' ');
    f(x + 1, y + 4, l, ' ');
    f(x + 2, y, l, a);
    f(x + 2, y + 1, l, a);
    f(x + 2, y + 2, l, a);
    f(x + 2, y + 3, l, a);
    f(x + 2, y + 4, l, a);
    f(x + 3, y, l, ' ');
    f(x + 3, y + 1, l, a);
    f(x + 3, y + 2, l, a);
    f(x + 3, y + 3, l, a);
    f(x + 3, y + 4, l, ' ');
    f(x + 4, y, l, ' ');
    f(x + 4, y + 1, l, a);
    f(x + 4, y + 2, l, ' ');
    f(x + 4, y + 3, l, a);
    f(x + 4, y + 4, l, ' ');
}

int main() {
    int n;
    char r[9770000];
    scanf("%d", &n);
    int x = pow(5, n);
    f(0, 0, n, '*');
    for (int i = 0, k = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            r[k++] = m[i][j];
        }
        r[k++] = '\n';
    }
    printf("%s", r);
}
