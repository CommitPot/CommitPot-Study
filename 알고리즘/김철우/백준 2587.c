#include<stdio.h>
int main() {
	int arr[5];
	int tmp, sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (int i = 0; i <5; i++) {
		for (int j = 0; j < 5 - 1; j++) {
			if (arr[j + 1] < arr[j]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	printf("%d\n%d", sum / 5, arr[2]);
}
배열 for문 돌려서 입력 받는건 어렵지 않았다. 그리고 버블 정렬 사용해서 어차피 5개 입력 받는건 고정이니까 for문도 5까지 돌려줬다. 
정렬을 다 하고 출력문에서 다 더한 것을 5로 나눠주고, 중앙값은 arr에서 3번째에 있는 값을 출력 해줬다.
쉬운 알고리즘이었지만 계속 실패를 했던 이유는 입력문에 줄바꿈을 해줘서 시간초과가 떴다. 줄바꿈을 지워보니 해결됐다!
