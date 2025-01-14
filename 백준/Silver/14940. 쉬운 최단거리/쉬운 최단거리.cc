#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[1001][1001];

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    Point target;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                target = {j, i};
            }
        }
    }

    vector<vector<int>> minDistance(N, vector<int>(M, -1));
    queue<Point> q;

    q.push(target);
    minDistance[target.y][target.x] = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] != 0 && minDistance[ny][nx] == -1) {
                minDistance[ny][nx] = minDistance[current.y][current.x] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                cout << 0 << ' ';
            } else {
                cout << minDistance[i][j] << ' ';
            }
        }
        cout << "\n";
    }
}