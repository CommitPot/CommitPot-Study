#include <stdio.h>

int main() {
    long long int n, sum, key, v[100001], e[100001];
    scanf("%lld", &n);
    for (int i = 0; i < n - 1; i++) scanf("%lld", &v[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &e[i]);
    key = e[0];
    sum = v[0] * key;
    for (int i = 1; i < n; i++) {
        if (key <= e[i]) sum += key * v[i];
        else {
            key = e[i];
            sum += (e[i] * v[i]);
        }
    }
    printf("%lld", sum);
}
