#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Coordinate
{
	int x;
	int y;
	int distance;
};

int main() {
	Coordinate joo,baek;
	
	int TestCase;
	double between;
	scanf("%d",&TestCase);

	for (int i = 0; i < TestCase; i++) {
		scanf("%d %d %d %d %d %d",&joo.x,&joo.y,&joo.distance,&baek.x,&baek.y,&baek.distance);
		int longer = joo.distance > baek.distance ? joo.distance : baek.distance;
		int shorter = joo.distance > baek.distance ? baek.distance : joo.distance;
		// 조와 백 사이의 거리
		between = sqrt(pow((joo.x - baek.x), 2) + pow((joo.y - baek.y),2));
		//중심이 같은 경우
		if (between == 0) {
			if (joo.distance == baek.distance) printf("-1\n");
			else printf("0\n");
		}
		//중심이 다른 경우
		else {
			if (abs(joo.distance - baek.distance) < between && (joo.distance + baek.distance > between))  printf("2\n");
			else if ((joo.distance + baek.distance == between) || (between + joo.distance == baek.distance) || (between + baek.distance == joo.distance)) printf("1\n");
			else if ((joo.distance + baek.distance < between) || ((longer > between) && (shorter + between) < longer)) printf("0\n");
		}
	}
}