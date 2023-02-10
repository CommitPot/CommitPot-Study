#include <stdio.h>

#define MAX_SIZE 50

int main() {
    int N = 0, K = 0; // 사람 수

    int x[MAX_SIZE + 1] = {0};
    int y[MAX_SIZE + 1] = {0};

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for (int i = 0; i < N; i++) {
        K = 0;
        for (int j = 0; j < N; j++) {
            if (x[i] < x[j] && y[i] < y[j]) {
                K++;
            }
        }
        printf("%d ", K + 1);
    }
}
