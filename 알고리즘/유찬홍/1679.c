#include <stdio.h>

typedef struct element {
    int sum, c;
} element;
int n, k, arr[1001], vis[1001] = {0}, f = 0, r = 0;
element queue[100];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        queue[++r].sum = arr[i];
        queue[r].c = 1;
        vis[queue[r].sum] = 1;
    }
    scanf("%d", &k);
    vis[1] = 1;
    while (f < r) {
        int sum = queue[++f].sum;
        int c = queue[f].c;
        for (int i = 0; i < n; i++) {
            if (c + 1 <= k && !vis[sum + arr[i]]) {
                queue[++r].sum = sum + arr[i];
                queue[r].c = c + 1;
                vis[sum + arr[i]] = c + 1;
            }
        }
    }
    for (int i = 1; i < 1001; i++) {
        if (!vis[i]) {
            printf("%s win at %d", i % 2 == 0 ? "holsoon" : "jjaksoon", i);
            break;
        }
    }
}
