#include <stdio.h>

typedef struct element {
    int in, idx;
} element;

int main() {
    int n, c = 0, bs[1000001] = {0}, print[1000001];
    element arr[1000001];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].in);
    }
    bs[0] = arr[0].in;
    for (int i = 1; i < n; i++) {
        if (arr[i].in > bs[c]) bs[++c] = arr[i].in, arr[i].idx = c;
        else {
            int s = 0, e = c;
            while (s < e) {
                int mid = (s + e) / 2;
                if (arr[i].in > bs[mid]) s = mid + 1;
                else e = mid;
            }
            bs[e] = arr[i].in;
            arr[i].idx = e;
        }
    }
    printf("%d\n", c + 1);
    int c1 = c;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i].idx == c) print[c--] = arr[i].in;
    }
    for (int i = 0; i <= c1; i++) {
        printf("%d ", print[i]);
    }
    return 0;
}