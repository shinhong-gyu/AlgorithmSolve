#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C, N; // 목표 고객 수 C, 도시의 개수 N
    cin >> C >> N;


    vector<int> dp(C + 101, 1e9); 
    dp[0] = 0;

    vector<pair<int, int>> invest(N);
    
    for (int i = 0; i < N; i++) 
    {
        cin >> invest[i].first >> invest[i].second;
    }

    // 모든 도시에 대해 DP 테이블 업데이트
    for (int i = 0; i < N; i++)
    {
        int cost = invest[i].first;
        int effect = invest[i].second;

        // DP 테이블을 순회하며 최소 비용 갱신
        // j는 현재 확보하려는 고객의 수
        for (int j = effect; j <= C + 100; j++) 
        {
            // j명의 고객을 얻는 비용 = (j-effect)명의 고객을 얻는 비용 + 현재 도시의 비용
            dp[j] = min(dp[j], dp[j - effect] + cost);
        }
    }

    // C명 이상의 고객을 확보하는 최소 비용 찾기
    int result = 1e9;
    for (int i = C; i <= C + 100; i++) 
    {
        result = min(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}