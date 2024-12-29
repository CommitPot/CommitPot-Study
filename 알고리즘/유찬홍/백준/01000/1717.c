#include <stdio.h>

int f(int x, int *arr) {
    if (arr[x] == x) return x;
    return arr[x] = f(arr[x], arr);
}

void u(int x, int y, int *arr) {
    x = f(x, arr);
    y = f(y, arr);
    arr[x] = arr[y];
}

int main() {
    int n, m, a, b, c, arr[1000001];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (!a) {
            if (f(b, arr) != f(c, arr)) {
                u(b, c, arr);
            }
        } else {
            printf("%s\n", f(b, arr) == f(c, arr) ? "YES" : "NO");
        }
    }
}
