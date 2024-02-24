#include <stdio.h>

int main() {
    int n, k, a = 0, b, c = 0, l[150];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &l[i]);
    while (a != k) {
        if (l[a] != -1) {
            b = l[a];
            l[a] = -1;
            a = b;
            c++;
        } else {
            c = -1;
            break;
        }
    }
    printf("%d", c);
}
