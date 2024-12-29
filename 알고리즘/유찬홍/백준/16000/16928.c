#include <stdio.h>

typedef struct element {
    int c, sum;
} element;
int n, m, arr[101] = {0}, vis[101] = {0}, f = 0, r = 0;
element queue[600000];

int bfs() {
    queue[++r].c = 0;
    queue[r].sum = 1;
    while (f < r) {
        int c = queue[++f].c;
        int sum = queue[f].sum;
        for (int i = 1; i <= 6; i++) {
            int a = sum + i;
            if (a == 100) {
                return c + 1;
            } else if (a < 100) {
                while (arr[a] != 0) {
                    a = arr[a];
                }
                if (!vis[a]) {
                    queue[++r].c = c + 1;
                    queue[r].sum = a;
                    vis[a] = 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        arr[a] = b;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a] = b;
    }
    printf("%d", bfs());
    return 0;
}