#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// BFS 함수: start_node에서 해킹할 수 있는 컴퓨터의 수를 반환
int bfs(int start_node, int N, const vector<vector<int>>& graph) {
    int count = 1;
    vector<bool> visited(N + 1, false);
    queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (int neighbor : graph[current_node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 그래프를 역방향으로 구성
    vector<vector<int>> trust(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        trust[B].push_back(A); // B를 해킹하면 A를 해킹할 수 있다.
    }

    int max_count = 0;
    vector<int> result(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        result[i] = bfs(i, N, trust);
        if (result[i] > max_count) {
            max_count = result[i];
        }
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] == max_count) {
            cout << i << " ";
        }
    }

    return 0;
}