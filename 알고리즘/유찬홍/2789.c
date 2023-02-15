#include <stdio.h>
#include <string.h>

int main() {
    char arr[101], a[10] = {'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E'};
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i] == a[j]) arr[i] = '0';
        }
    }
    for (int i = 0; i < len; i++) {
        if (arr[i] != '0') printf("%c", arr[i]);
    }
    return 0;
}
