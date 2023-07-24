#include<stdio.h>
#include<stdlib.h>
int main() {
	int n;
	int arr[1000] = { 0,1,2 };
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])% 10007;
	}
	printf("%d", arr[n]);
}
이 문제에서는 선생님께서 방향을 잡아주셔서 알고리즘을 이해하고 그걸 코드로 풀어써서 어려움은 딱히 없었다.
