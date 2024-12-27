#include <stdio.h>

int main(void) {
	int N, M,i,j,k;
	int a[100] = {0};
	scanf("%d %d", &N, &M);
	for (int h = 0; h < M; h++) {
		scanf("%d %d %d", &i, &j, &k);
		for (int l = i-1; l < j; l++) {
			a[l] = k;
		}
	}
	for (int h = 0; h < N; h++) {
		printf("%d " , a[h]);
	}
}