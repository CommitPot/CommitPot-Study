#include <stdio.h>

int main() {
    int n, b, w, max = 0;
    char arr[300001];
    scanf("%d %d %d", &n, &b, &w);
    scanf("%s", arr);
    int i = 0, j = 0, w1 = 0, b1 = 0;
    while (j < n) {
        if (arr[j++] == 'W') w1++;
        else b1++;
        if (b1 <= b){
            if (w1 >= w && max < j - i) max = j - i;
        } else {
            if (arr[i++] == 'W') w1--;
            else b1--;
        }
    }
    printf("%d", max);
    return 0;
}