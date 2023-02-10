#include <stdio.h>


int main() {
    int N = 0, A = 0, B = 0, C = 0, count = 0; // 치킨 수, 후 선호, 간 선호, 양 선호의 수

    scanf("%d %d %d %d", &N, &A, &B, &C);

    int chicken[3] = {A, B, C};

    for (int i = 0; i < 3; i++) {
        if (chicken[i] <= N) {
            count += chicken[i];
        } else {
            count += N;
        }
    }

    printf("%d", count);
}

