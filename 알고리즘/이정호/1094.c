#include <stdio.h>

int main() {
    int X = 0, count = 0, S = 64;

    scanf("%d", &X);

    while(X > 0) {
        if(S > X) {
            S /= 2;
        }
        else {
            count++;
            X -= S;
        }
    }

    printf("%d", count);
}
