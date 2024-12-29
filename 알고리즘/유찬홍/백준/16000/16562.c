#include <stdio.h>

int n, m, k, a, b, arr[10001], arr1[10001];

int f(int x) {
    if (arr1[x] == x) return x;
    return arr1[x] = f(arr1[x]);
}

void u(int x, int y) {
    x = f(x);
    y = f(y);
    arr1[arr[x] > arr[y] ? x : y] = arr[x] > arr[y] ? y : x;
}

int main() {
    int cnt = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr1[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        u(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (arr1[i] == i) {
            if (k >= arr[i]) {
                cnt += arr[i];
                k -= arr[i];
            } else {
                printf("Oh no");
                return 0;
            }
        }
    }
    printf("%d", cnt);
}
