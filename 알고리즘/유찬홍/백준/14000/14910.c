#include <stdio.h>

int main() {
    int a, b = -1000000000;
    while (scanf("%d", &a) != EOF) {
        if (a < b) {
            printf("Bad");
            return 0;
        }
        else b = a;
    }
    printf("Good");
}
