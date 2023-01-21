#include <stdio.h>

int main() {

    int a = 0, b = 0, sum = 0, max = 0; // 내린 사람, 탄 사람

    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &a, &b);
        sum += b - a;
        if (max < sum) {
            max = sum;
        }
    }

    printf("%d", max);

}
