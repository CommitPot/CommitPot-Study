#include <stdio.h>

int main() {
	int month, day = 0;

	scanf("%d %d", &month, &day);

	if (month == 2 && day == 18) {
		printf("Special");
	}
	
	if (month < 2) {
		printf("Before");
	}
	else if (month > 2) {
		printf("After");
	}
	else {
		if (day < 18)
			printf("Before");
		else if (day > 18) 
			printf("After");
	}
}
