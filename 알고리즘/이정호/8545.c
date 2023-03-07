#include <stdio.h>
#include <string.h>

int main() {
    char S[20] = {0};

    for(int i=0; i<3; i++) {
        scanf("%c", &S[i]);
    }


    for(int i=strlen(S) -1; i>=0; i--) {
        printf("%c", S[i]);
    }
}
