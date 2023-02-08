#include<stdio.h>
int main() {
    long long a,b;
    scanf("%lld %lld",&a,&b);
    
    if(a < b) {
        printf("%lld", (b-a));
    }
    else {
        printf("%lld",(a-b));
    }
}
