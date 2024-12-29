#include <stdio.h>

int n, m, a, b, arr[400001] = {0}, arr1[400001] = {0}, min, max;

int minV(int x, int y) { return x > y ? y : x; }

int maxV(int x, int y) { return x > y ? x : y; }

void findMax(int s, int e) {
    if (s % 2 == 1 && max < arr[s]) max = arr[s];
    s = (s + 1) / 2;
    if (e % 2 == 0 && max < arr[e]) max = arr[e];
    e = (e - 1) / 2;
    if (s > e) return;
    findMax(s, e);
}

void findMin(int s, int e) {
    if (s % 2 == 1 && min > arr1[s]) min = arr1[s];
    s = (s + 1) / 2;
    if (e % 2 == 0 && min > arr1[e]) min = arr1[e];
    e = (e - 1) / 2;
    if (s > e) return;
    findMin(s, e);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = n + 1; i <= n * 2; i++) {
        scanf("%d", &arr[i]);
        arr1[i] = arr[i];
    }
    for (int i = n * 2; i >= 1; i--) {
        arr[i / 2] = !arr[i / 2] ? arr[i] : maxV(arr[i / 2], arr[i]);
        arr1[i / 2] = !arr1[i / 2] ? arr1[i] : minV(arr1[i / 2], arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        min = minV(arr1[a + n], arr1[b + n]);
        max = maxV(arr[a + n], arr[b + n]);
        findMax(a + n, b + n);
        findMin(a + n, b + n);
        printf("%d %d\n", min, max);
    }
}
