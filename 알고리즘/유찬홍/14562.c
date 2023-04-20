#include <stdio.h>

typedef struct element {
    int sum, sum1, c;
} element;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int s, t, r = 0, f = 0;
        element queue[100001];
        scanf("%d %d", &s, &t);
        queue[++r].sum = s;
        queue[r].sum1 = t;
        queue[r].c = 0;
        while (f < r) {
            int sum = queue[++f].sum;
            int sum1 = queue[f].sum1;
            int c = queue[f].c;
            if (sum == sum1) {
                printf("%d\n", c);
                break;
            } else if (sum > sum1) {
                continue;
            } else {
                queue[++r].sum = sum + sum;
                queue[r].sum1 = sum1 + 3;
                queue[r].c = c + 1;
                queue[++r].sum = sum + 1;
                queue[r].sum1 = sum1;
                queue[r].c = c + 1;
            }
        }
    }
}
