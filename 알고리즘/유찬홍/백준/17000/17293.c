#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i >= 0; i--) {
        if (i > 1)
            printf("%d bottles of beer on the wall, %d bottles of beer.\n"
                   "Take one down and pass it around, %d bottle%s of beer on the wall.", i, i, i - 1,
                   i - 1 == 1 ? "" : "s");
        else if (i == 1)
            printf("1 bottle of beer on the wall, 1 bottle of beer.\n"
                   "Take one down and pass it around, no more bottles of beer on the wall.");
        else
            printf("No more bottles of beer on the wall, no more bottles of beer.\n"
                   "Go to the store and buy some more, %d bottle%s of beer on the wall.", n, n == 1 ? "" : "s");
        printf("\n\n");
    }
}
