#include <stdio.h>

int main() {
    int r = 0;
    char a[26] = "32123333113133122212112221", s[1000001];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        r = (r + a[s[i] - 65] - 48) % 10;
    }
    printf("%s", r & 1 ? "I'm a winner!" : "You're the winner?");
}
