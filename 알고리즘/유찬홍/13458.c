#include <stdio.h>

int main() {
    int n, b, c, arr[1000001];
    long long co = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &b, &c);
    for (int i = 0; i < n; i++) {
        int a = arr[i] - b;
        if (a < 0){
            co += 1;
            continue;
        }
        if (a % c == 0) a /= c;
        else a = a / c + 1;
        co += a + 1;
    }
    printf("%lld", co);
    return 0;
}
