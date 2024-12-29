#include <stdio.h>

typedef struct element {
    int n, k;
} element;

element queue[1000000];

int main() {
    int n, k, min = 1000000000, count = 0, f = 0, r = 0, vis[100001] = {0};
    scanf("%d %d", &n, &k);
    queue[++r].n = n;
    queue[r].k = 0;
    while (f < r) {
        int n1 = queue[++f].n;
        int k1 = queue[f].k;
        vis[n1] = 1;
        if (min < k1) break;

        if (n1 == k) {
            min = k1;
            count++;
            continue;
        }


        if (n1 < 100000 && !vis[n1 + 1]) {
            queue[++r].n = n1 + 1;
            queue[r].k = k1 + 1;
        }
        if (n1 > 0 && !vis[n1 - 1]) {
            queue[++r].n = n1 - 1;
            queue[r].k = k1 + 1;
        }
        if (n1 < 50001 && !vis[n1 * 2]) {
            queue[++r].n = n1 * 2;
            queue[r].k = k1 + 1;
        }
    }
    printf("%d\n%d", min, count);
}
