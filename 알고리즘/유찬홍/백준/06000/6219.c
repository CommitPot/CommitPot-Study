#include <stdio.h>
#include <math.h>

int main() {
    int a, b, d, cnt = 0, prime[4000001] = {0};
    prime[0] = prime[1] = 1;
    scanf("%d %d %d", &a, &b, &d);
    int s = sqrt(b) + 1;
    for (int i = 2; i <= s; i++) {
        if (!prime[i]) {
            for (int j = i * 2; j <= b; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (int i = a; i <= b; i++) {
        int v = i;
        if (!prime[v]) {
            while (v > 0) {
                if (v % 10 == d) {
                    cnt++;
                    break;
                }
                v /= 10;
            }
        }
    }
    printf("%d", cnt);
}
