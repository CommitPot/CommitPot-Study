#include <stdio.h>

int main() {
    long long int S = 0, SUM = 0, count = 0;

    scanf("%lld", &S);

    while (1) {
        count++;
        SUM += count;
        if(SUM > S) {
            count--;
            break;
        }
    }

    printf("%d", count);
}
