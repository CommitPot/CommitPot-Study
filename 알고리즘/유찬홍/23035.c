#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int r, c;
} element;

int comp(const void *a, const void *b) {
    element *a1 = (element *) a;
    element *b1 = (element *) b;
    if (a1->r == b1->r) {
        if (a1->c < b1->c) return -1;
        else if (a1->c == b1->c) return 0;
        else return 1;
    } else {
        if (a1->r < b1->r) return -1;
        else if (a1->r == b1->r) return 0;
        else return 1;
    }
}

int main() {
    int n, m, t, c = 0, rs = 0, bs[100001] = {0};
    element arr[100001];
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &arr[i].r, &arr[i].c);
        if (arr[i].r > n || arr[i].c > m) arr[i].r = 1000000001, c++;
    }
    qsort(arr, t, sizeof(arr[0]), comp);
    t -= c;
    bs[0] = arr[0].c;
    for (int i = 1; i < t; i++) {
        if (arr[i].c > bs[rs]) bs[++rs] = arr[i].c;
        else {
            int s = 0, e = rs;
            while (s < e) {
                int mid = (s + e) / 2;
                if (arr[i].c >= bs[mid]) s = mid + 1;
                else e = mid;
            }
            bs[e] = arr[i].c;
        }
    }
    printf("%d", rs + 1);
    return 0;
}