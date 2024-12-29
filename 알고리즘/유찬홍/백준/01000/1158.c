#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[25000000], f = 0;
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        queue[i] = i + 1;
    }
    printf("<");
    int r = n - 1;
    while (abs(f - r)) {
        for (int i = 0; i < k - 1; i++) {
            queue[++r] = queue[f++];
        }
        printf("%d, ", queue[f++]);
    }
    printf("%d>", queue[f]);
    return 0;
}