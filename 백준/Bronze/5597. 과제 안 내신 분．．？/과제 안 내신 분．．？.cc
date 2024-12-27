#include <stdio.h>

int main(void) {
	int arr[30] = { 0 }, n, cnt = 1;
	for (int i = 0; i < 28; i++) {
		scanf("%d", &n);
		arr[n-1] = n;
	}
	for (int i = 0; i < 30; i++) {
		if (arr[i] == 0 && cnt != 2) {
			printf("%d\n", i + 1);
			cnt++;
		}
		else if (arr[i] == 0 && cnt == 2) {
			printf("%d", i + 1);
		}
	}
}