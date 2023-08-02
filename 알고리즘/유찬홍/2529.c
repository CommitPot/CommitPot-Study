#include <stdio.h>

int n, vis[11] = {0};
char arr[11], min[11] = "9", max[11] = "-1";

void bt(char *sen, int cnt) {
    if (cnt + 1 == n) {
        if (min[0] == 57) {
            for (int i = 0; i < n; i++) {
                min[i] = sen[i];
            }
        }
        for (int i = 0; i < n; i++) {
            max[i] = sen[i];
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (!vis[i]) {
            if ((arr[cnt] == '<' && sen[cnt] < i + 48) || (arr[cnt] == '>' && sen[cnt] > i + 48)) {
                sen[++cnt] = i + 48;
                vis[i] = 1;
                bt(sen, cnt);
                vis[i] = 0;
                cnt--;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }
    n++;
    for (int i = 0; i < 10; i++) {
        vis[i] = 1;
        char arr1[10];
        arr1[0] = i + 48;
        bt(arr1, 0);
        vis[i] = 0;
    }
    printf("%s\n%s", max, min);
}
