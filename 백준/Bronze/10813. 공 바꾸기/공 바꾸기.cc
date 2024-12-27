#include <stdio.h>

int main(void) {
	int N, M, a, b,temp=0;
	int arr[100] = {0};
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a,&b);
		temp = arr[a-1];
		arr[a-1] = arr[b-1];
		arr[b-1] = temp;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ",arr[i]);
	}
}