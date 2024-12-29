#include <stdio.h>

int main() {
    int n, a, p[5000001] = {};
    for (int i = 2; i * i <= 5000000; i++) {
        if (p[i]) continue;
        for (int j = i * 2; j <= 5000000; j += i) if (!p[j]) p[j] = i;
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        while (p[a]) printf("%d ", p[a]), a /= p[a];
        printf("%d\n", a);
    }
}
