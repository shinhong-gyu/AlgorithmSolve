#include <stdio.h>

int main(void) {
	int arr[10] = { -1 }, cnt=0;
	int diff[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
		arr[i] = arr[i] % 42;
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i] != -1) {
			for (int j = i; j < 10; j++) {
				if (arr[i] == arr[j] && i!=j) arr[j] = -1;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i] != -1) cnt++;
	}
	printf("%d",cnt);
}