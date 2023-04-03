#include <stdio.h>

typedef struct element {
    int x, y, c, sum;
} element;
int arr[6][6];

int vis[1000001] = {0}, f = 0, r = 0, count = 0;
element queue[1000001];

int bfs(int x, int y, int sum) {
    queue[++r].x = x;
    queue[r].y = y;
    queue[r].c = 0;
    queue[r].sum = sum;
    while (f < r) {
        int i = queue[++f].x;
        int j = queue[f].y;
        int c = queue[f].c;
        int sum1 = queue[f].sum;
        if (c == 5 && !vis[sum1]) {
            count++, vis[sum1] = 1;
        } else if (c == 6) break;
        else {
            if (i + 1 <= 5) {
                queue[++r].x = i + 1;
                queue[r].y = j;
                queue[r].c = c + 1;
                queue[r].sum = sum1 * 10 + arr[i + 1][j];
            }
            if (i - 1 > 0) {
                queue[++r].x = i - 1;
                queue[r].y = j;
                queue[r].c = c + 1;
                queue[r].sum = sum1 * 10 + arr[i - 1][j];
            }
            if (j + 1 <= 5) {
                queue[++r].x = i;
                queue[r].y = j + 1;
                queue[r].c = c + 1;
                queue[r].sum = sum1 * 10 + arr[i][j + 1];
            }
            if (j - 1 > 0) {
                queue[++r].x = i;
                queue[r].y = j - 1;
                queue[r].c = c + 1;
                queue[r].sum = sum1 * 10 + arr[i][j - 1];
            }
        }
    }
    return 0;
}

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            bfs(i, j, arr[i][j]);
            f = r = 0;
        }
    }
    printf("%d", count);
    return 0;
}