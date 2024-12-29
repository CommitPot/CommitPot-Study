#include <stdio.h>

typedef struct element {
    int w, c;
} element;
int n, s, arr[100001], vis[100001] = {0}, f = 0, r = 0;
element queue[100000];

void bfs(int a) {
    queue[++r].w = a;
    queue[r].c = arr[a];
    while (f < r) {
        int w = queue[++f].w;
        int c = queue[f].c;
        vis[w] = 1;
        if (w + c <= n) {
            queue[++r].w = w + c;
            queue[r].c = arr[w + c];
        }
        if (w - c > 0) {
            queue[++r].w = w - c;
            queue[r].c = arr[w - c];
        }
    }
}

int main() {
    int count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &s);
    bfs(s);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) count++;
    }
    printf("%d", count);
}