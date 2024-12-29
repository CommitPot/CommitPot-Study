#include <stdio.h>

int main() {
    int n, m;
    long long int arr[1000001] = {0};
    scanf("%d", &n);
    for (int i = 1; i < 1000001; i++) {
        for (int j = i; j < 1000001; j += i) {
            arr[j] += i;
        }
        arr[i] += arr[i - 1];
    }
    while (n--){
        scanf("%d", &m);
        printf("%lld\n", arr[m]);
    }
    return 0;
}
