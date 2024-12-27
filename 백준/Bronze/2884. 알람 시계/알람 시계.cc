#include <stdio.h>
struct time {
	int h, m;
};
time cal_time(time t) {
	if (t.m - 45 < 0) {
		if (t.h - 1 < 0) {
			t.h = 23;
		}
        else t.h--;
		t.m = 60 + (t.m - 45);
	}
	else t.m = t.m - 45;
	return t;
}
int main() {
	time t;
	scanf("%d %d", &t.h,&t.m);
	printf("%d %d", cal_time(t).h, cal_time(t).m);
}