#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int a[5000010];
deque<pair<int, int>> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	// 벡터를 순회하면서
	for (int i = 0; i < N; i++) {

		// 만약 현재 d의 첫 번째 요소(검사 범위 내의 최솟값)가 검사 범위 밖으로 나가면 pop
		if (!d.empty() && d.front().second < i - L + 1) {
			d.pop_front();
		}
		// 지금 deque에 넣으려는 값보다 큰 값이 deque에 존재한다면 해당 값들을 pop하고 현재 값을 push
		while (!d.empty() && a[i] < d.back().first) d.pop_back();
		d.push_back(make_pair(a[i], i));


		// 범위 내 최솟값 출력
		cout << d.front().first << " ";
	}
}