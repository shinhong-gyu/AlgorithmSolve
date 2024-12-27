#include <stdio.h>
struct time {
	int h, m;
};

time minToTime(int min) {
	time t;
	t.h = min / 60;
	t.m = min - (min / 60) * 60;
	return t;
}
time cal_time(time t,time take) {
	if (t.m + take.m >= 60) {
		t.m = t.m + take.m - 60;
		t.h++;
	}
	else t.m = t.m + take.m;
	if (t.h + take.h >= 24) {
		t.h = t.h + take.h - 24;
	}
	else t.h = t.h + take.h;
	return t;
}
int main() {
	time t,take;
	int min;
	scanf("%d %d", &t.h,&t.m);
	scanf("%d", &min);
	take = minToTime(min);
	printf("%d %d", cal_time(t,take).h, cal_time(t,take).m);
}