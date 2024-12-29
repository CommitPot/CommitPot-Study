#include <stdio.h>

int main() {
    int a, b, n, m, f = 0, r = 0, arr[100001] = {0}, queue[100000];
    scanf("%d %d %d %d", &a, &b, &n, &m);
    queue[++r] = n;
    while (f < r) {
        int x = queue[++f];
        int c = arr[x];
        if (x == m) {
            printf("%d", c);
            break;
        }
        if (x * a <= 100000 && !arr[x * a]) {
            queue[++r] = x * a;
            arr[x * a] = c + 1;
        }
        if (x * b <= 100000 && !arr[x * b]) {
            queue[++r] = x * b;
            arr[x * b] = c + 1;
        }
        if (x + a <= 100000 && !arr[x + a]) {
            queue[++r] = x + a;
            arr[x + a] = c + 1;
        }
        if (x + b <= 100000 && !arr[x + b]) {
            queue[++r] = x + b;
            arr[x + b] = c + 1;
        }
        if (x + 1 <= 100000 && !arr[x + 1]) {
            queue[++r] = x + 1;
            arr[x + 1] = c + 1;
        }
        if (x - 1 >= 0 && !arr[x - 1]) {
            queue[++r] = x - 1;
            arr[x - 1] = c + 1;
        }
        if (x - a >= 0 && !arr[x - a]) {
            queue[++r] = x - a;
            arr[x - a] = c + 1;
        }
        if (x - b >= 0 && !arr[x - b]) {
            queue[++r] = x - b;
            arr[x - b] = c + 1;
        }
    }
}
