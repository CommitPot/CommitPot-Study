#include <stdio.h>

int main() {
    int t = 0, sum = 0, a = 0;

    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        scanf("%d", &a);
        sum += a;
    }

    printf("%d", sum);
}
