#include <stdio.h>

typedef struct element {
    int x, c;
} element;

int main() {
    element queue[100001];
    int n, s, d, f, b, k, a, fr = 0, re = 0, arr[100001] = {0};
    scanf("%d %d %d %d %d %d", &n, &s, &d, &f, &b, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a);
        arr[a] = 1;
    }
    queue[++re].x = s;
    queue[re].c = 0;
    arr[s] = 1;
    while (fr < re) {
        int x = queue[++fr].x;
        int c = queue[fr].c;
        if (x == d) {
            printf("%d", c);
            return 0;
        }
        if (x + f <= n && !arr[x + f]) {
            arr[x + f] = 1;
            queue[++re].x = x + f;
            queue[re].c = c + 1;
        }
        if (x - b >= 1 && !arr[x - b]) {
            arr[x - b] = 1;
            queue[++re].x = x - b;
            queue[re].c = c + 1;
        }
    }
    printf("BUG FOUND");
}
