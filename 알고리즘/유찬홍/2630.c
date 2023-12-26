#include <stdio.h>

int arr[129][129], rs[2];

int c(int n, int x, int y, int a) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (a != arr[i][j]) return 0;
        }
    }
    return 1;
}

void func(int n, int x, int y) {
    if (c(n, x, y, arr[x][y])) {
        rs[arr[x][y]]++;
        return;
    }
    for (int i = x; i < x + n; i += n / 2) {
        for (int j = y; j < y + n; j += n / 2) {
            func(n / 2, i, j);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    func(n, 0, 0);
    printf("%d\n%d", rs[0], rs[1]);
}
