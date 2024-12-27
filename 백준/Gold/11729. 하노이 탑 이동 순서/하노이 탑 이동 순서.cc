#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		printf("%d %d\n",from,to);
	}
	else {
		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	int n;
	cin >> n;
	int k = pow(2, n) - 1;
	printf("%d\n",k);
	hanoi(n, 1, 2, 3);
}