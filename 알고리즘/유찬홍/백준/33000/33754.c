#include <stdio.h>
#define l == 48

int main() {
    int n, r = 1, w = 0;
    char a[2][200002];
    scanf("%d %[^\n] %[^\n]", &n, a[0], a[1]);
    w |= a[0][0]l || a[1][0]l;
    for (int i = 2; i < n * 2; i += 2) {
        if ((a[0][i]l && a[1][i - 2]l) || (a[1][i]l && a[0][i - 2]l) || (a[0][i]l && a[1][i]l)) r = 0;
        w |= a[0][i]l || a[1][i]l;
    }
    printf("%d", r ? w ? 1 : 2 : 0);
}
