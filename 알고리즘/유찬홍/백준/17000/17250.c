#include <stdio.h>

int f(int x, int *arr) {
    if (arr[x] == x) return x;
    return arr[x] = f(arr[x], arr);
}

void u(int x, int y, int *arr, int *arr1) {
    x = f(x, arr);
    y = f(y, arr);
    arr[x] = arr[y];
    arr1[y] += arr1[x];
}

int main() {
    int n, m, a, b, arr[100001], arr1[100001];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (f(a, arr) != f(b, arr)) {
            u(a, b, arr, arr1);
        }
        printf("%d\n", arr1[f(a, arr)]);
    }
}
