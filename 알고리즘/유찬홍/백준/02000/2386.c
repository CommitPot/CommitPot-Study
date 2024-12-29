#include <stdio.h>
#include <string.h>

int main() {
    char a, arr[251];
    while (1){
        int count = 0;
        scanf("%c ", &a);
        if (a == '#') break;
        gets(arr);
        int len = strlen(arr);
        for (int i = 0; i < len; i++) {
            if (arr[i] == a || arr[i] + 32 == a) count++;
        }
        printf("%c %d\n", a, count);
    }
}