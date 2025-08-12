#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define INF INT_MAX

using namespace std;

// 노드 정보를 담을 구조체
struct Node
{
    int city;
    int cost;
};

// 우선순위 큐를 위한 비교 연산자
struct Compare
{
    bool operator()(const Node& a, const Node& b)
    {
        return a.cost > b.cost;
    }
};

// 다익스트라 알고리즘 함수
vector<int> dijkstra(int start, int N, const vector<vector<pair<int, int>>>& graph)
{
    vector<int> dist(N + 1, INF);
    priority_queue<Node, vector<Node>, Compare> pq;

    dist[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty())
    {
        Node currentNode = pq.top();
        pq.pop();

        int currentCity = currentNode.city;
        int currentCost = currentNode.cost;

        if (dist[currentCity] < currentCost)
        {
            continue;
        }

        for (const auto& nextNode : graph[currentCity])
        {
            int nextCity = nextNode.first;
            int nextCost = nextNode.second;

            if (dist[nextCity] > dist[currentCity] + nextCost)
            {
                dist[nextCity] = dist[currentCity] + nextCost;
                pq.push({ nextCity, dist[nextCity] });
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> costs(N + 1);
    vector<vector<pair<int, int>>> reverseCosts(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        costs[a].push_back({ b, c });
        reverseCosts[b].push_back({ a, c }); // 역방향 그래프 생성
    }

    // K에서 각 도시로 가는 최단 거리 계산
    vector<int> KtoI = dijkstra(K, N, costs);

    // 각 도시에서 K로 가는 최단 거리 계산 (역방향 그래프 활용)
    vector<int> ItoK = dijkstra(K, N, reverseCosts);

    int maxTime = INT_MIN;

    for (int i = 1; i <= N; i++)
    {
        if (i == K)
        {
            continue;
        }

        if (KtoI[i] != INF && ItoK[i] != INF)
        {
            maxTime = max(maxTime, KtoI[i] + ItoK[i]);
        }
    }

    cout << maxTime;
}