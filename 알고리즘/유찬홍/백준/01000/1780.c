#include <stdio.h>

int arr[2187][2187], rs[3];

int check(int n, int x, int y, int a) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[i][j] != a) return 0;
        }
    }
    return 1;
}

void func(int n, int x, int y) {
    if (check(n, x, y, arr[x][y])) {
        switch (arr[x][y]) {
            case -1:
                rs[0]++;
                break;
            case 0:
                rs[1]++;
                break;
            case 1:
                rs[2]++;
                break;
        }
        return;
    }
    for (int i = x; i < x + n; i += n / 3) {
        for (int j = y; j < y + n; j += n / 3) {
            func(n / 3, i, j);
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
    for (int i = 0; i < 3; i++) printf("%d\n", rs[i]);
}
