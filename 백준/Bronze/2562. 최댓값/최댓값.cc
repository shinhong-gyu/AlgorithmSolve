#include <stdio.h>

int main() {
	int index=0,max = -1000001;
	int a[10000];


	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < 9; i++) {
		if (a[i] > max) {
			max = a[i];
			index = i+1;
		}
	}
	printf("%d\n%d", max, index);
}