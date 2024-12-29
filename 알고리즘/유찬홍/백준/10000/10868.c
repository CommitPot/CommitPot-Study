#include <stdio.h>

int n, m, a, b, min = 1000000001;
int arr[400001] = {0};

void find(int s, int e) {
    if (s % 2 == 1 && min > arr[s]) min = arr[s];
    s = (s + 1) / 2;
    if (e % 2 == 0 && min > arr[e]) min = arr[e];
    e = (e - 1) / 2;
    if (s > e) {
        printf("%d\n", min);
        min = 1000000001;
        return;
    }
    find(s, e);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = n + 1; i <= n * 2; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = n * 2; i >= 0; i--) {
        if (!arr[i / 2]) arr[i / 2] = arr[i];
        else {
            if (arr[i / 2] > arr[i]) arr[i / 2] = arr[i];
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (min > arr[a + n]) min = arr[a + n];
        if (min > arr[b + n]) min = arr[b + n];
        find(a + n, b + n);
    }
}
