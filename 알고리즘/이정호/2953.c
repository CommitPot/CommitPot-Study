#include <stdio.h>

int main() {

    int max = 0, maxIndex = 0, k = 0;

    for (int j = 0; j < 5; j++) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%d", &k);
            sum += k;
            if (sum > max) {
                max = sum;
                maxIndex = j + 1;
            }
        }
    }

    printf("%d %d", maxIndex, max);

}
