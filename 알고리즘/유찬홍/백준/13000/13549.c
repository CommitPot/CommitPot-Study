#include <stdio.h>

int n, m, f = 0, r = 0, queue[200000], vis[100001];

void add_rear(int item) {
    r = r + 1 % 100000;
    queue[r] = item;
}

int delete_front() {
    f = f + 1 % 100000;
    return queue[f];
}


void bfs() {
    add_rear(n);
    vis[n] = 1;
    while (f != r) {
        int search = delete_front();
        int cnt = vis[search];
        if (search == m) return;
        if (vis[search * 2] > vis[search] && search * 2 <= 100000) {
            add_rear(search * 2);
            vis[search * 2] = cnt;
        }
        if (vis[search - 1] > vis[search] && search - 1 >= 0) {
            add_rear(search - 1);
            vis[search - 1] = cnt + 1;
        }
        if (vis[search + 1] > vis[search] && search + 1 <= 100000) {
            add_rear(search + 1);
            vis[search + 1] = cnt + 1;
        }
    }
}

int main() {
    for (int i = 0; i < 100001; i++) {
        vis[i] = 100000000;
    }
    scanf("%d %d", &n, &m);
    bfs();
    printf("%d", vis[m] - 1);
    return 0;
}