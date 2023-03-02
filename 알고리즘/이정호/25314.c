#include <stdio.h>

int main() {
    int N = 0;

    scanf("%d", &N);

    N /= 4;

    for(int i=1; i<=N; i++) {
        printf("long ");
    }
    printf("int");
}
