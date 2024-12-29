#include <stdio.h>

typedef long long int llint;

int main() {
    llint arr[1000001] = {0};
    int count = 0;
    llint min, max;
    scanf("%lld %lld", &min, &max);
    for (llint i = 2; i * i <= max; i++) {
        llint s = i * i;
        llint a = min / s;
        if (min % s != 0) a++;
        for (llint j = a; j * s <= max; j++) {
            arr[j * s - min] = 1;
        }
    }
    for (llint i = 0; i <= max - min; i++) {
        if (!arr[i]) count++;
    }
    printf("%d", count);
    return 0;
}