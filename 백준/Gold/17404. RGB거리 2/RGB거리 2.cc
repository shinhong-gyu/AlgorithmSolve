#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int rgb[1001][3];
int dp[1001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    int result = INT_MAX;

    // 첫 번째 집을 각각 빨강, 초록, 파랑으로 칠하는 경우를 모두 탐색
    for (int startColor = 0; startColor < 3; startColor++) {
        // dp 배열 초기화
        for (int i = 0; i < 3; i++) {
            if (i == startColor) {
                dp[0][i] = rgb[0][i];
            } else {
                dp[0][i] = 1000 * 1000 + 1; // 충분히 큰 값으로 초기화
            }
        }

        // 2번째 집부터 N번째 집까지 최소 비용 계산
        for (int i = 1; i < N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
        }

        // 마지막 집의 색이 첫 번째 집의 색과 다를 때만 결과에 포함
        for (int endColor = 0; endColor < 3; endColor++) {
            if (startColor != endColor) {
                result = min(result, dp[N - 1][endColor]);
            }
        }
    }

    cout << result << endl;

    return 0;
}