#include <stdio.h>

int main() {
    int t;
    char a[2][1000001];
    scanf("%d", &t);
    while (t--) {
        int r[2] = {};
        scanf("%s %s", a[0], a[1]);
        for (int i = 0; a[0][i]; i++) {
            if (a[0][i] != a[1][i]) r[a[0][i] == 48]++;
        }
        printf("%d\n", r[0] > r[1] ? r[0] : r[1]);
    }
}
