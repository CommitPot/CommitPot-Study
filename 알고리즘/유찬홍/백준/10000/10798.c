#include <stdio.h>
#include <string.h>

int main() {
    int len = 0;
    char arr[6][16] = {'\0'};
    for (int i = 0; i < 5; i++) {
        scanf("%s", &arr[i][0]);
        if (strlen((const char *) arr[i]) > len) len = strlen((const char *) arr[i]);
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 5; ++j) {
            if (arr[j][i] == NULL) continue;
            printf("%c", arr[j][i]);
        }
    }
    return 0;
}
