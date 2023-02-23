#include <stdio.h>

int main() {

    int n = 0, count = 0;
    int score[101] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
    }

    for (int j = n - 1; j > 0; j--) {
        while (score[j] <= score[j - 1]) {
            score[j - 1]--;
            count++;
        }
    }

    printf("%d", count);
}
