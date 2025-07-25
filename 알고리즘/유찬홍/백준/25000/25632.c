#include <stdio.h>

int main() {
    int a, b, c, d, e[1001] = {1, 1,}, f = 0, g = 0, h = 0;
    for (int i = 2; i < 315; i++) {
        if (e[i]) continue;
        for (int j = 2 * i; j < 1001; j += i) e[j] = 1;
    }
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (int i = a; i <= b; i++) f += !e[i];
    for (int i = c; i <= d; i++) g += !e[i];
    for (int i = a < c ? c : a; i <= (b < d ? b : d); i++) h += !e[i];
    printf("%s", f < g ? "yj" : f > g ? "yt" : h & 1 ? "yt" : "yj");
}
