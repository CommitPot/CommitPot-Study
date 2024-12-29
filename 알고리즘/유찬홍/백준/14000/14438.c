#include <stdio.h>

#define min(a, b)  (((a) < (b)) ? (a) : (b))
int min = 1000000000;

void change(int nod, int val, int *arr) {
    arr[nod] = min(val, min(arr[nod * 2], arr[nod * 2 + 1]));
    if (nod == 1) return;
    change(nod / 2, val, arr);
}

void find(int s, int e, int *arr) {
    if (s % 2 == 1) min = min(min, arr[s]);
    s = (s + 1) / 2;
    if (e % 2 == 0) min = min(min, arr[e]);
    e = (e - 1) / 2;
    if (s > e) {
        printf("%d\n", min);
        min = 1000000000;
        return;
    }
    find(s, e, arr);
}

int main() {
    int n, m, a, b, c, arr[400001] = {0};
    scanf("%d", &n);
    for (int i = n + 1; i <= n + n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = n + n; i >= 1; i--) {
        arr[i / 2] = !arr[i / 2] ? arr[i] : min(arr[i / 2], arr[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            arr[b + n] = c;
            change((b + n) / 2, c, arr);
        } else find(b + n, c + n, arr);
    }
}
