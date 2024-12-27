#include <stdio.h>

int main() {
	int d1, d2, d3, reward, biggest = 0;
	scanf("%d %d %d", &d1,&d2,&d3);

	if (d1 == d2 && d2 == d3) reward = 10000 + d1 * 1000;
	else if (d1 == d2 || d1 == d3) reward = 1000 + d1 * 100;
	else if (d2 == d3) reward = 1000 + d2 * 100;
	else {
		biggest = d1;
		if (biggest < d2) biggest = d2;
		if (biggest < d3) biggest = d3;
		reward = biggest * 100;
	}
	printf("%d", reward);
}