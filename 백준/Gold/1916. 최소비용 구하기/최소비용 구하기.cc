#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX

using namespace std;

// 노드 정보를 담을 구조체
struct Node {
    int city;
    int cost;
};

// 우선순위 큐의 비교 함수 정의
// cost가 작은 노드의 우선순위를 높게 설정
struct compare {
    bool operator()(const Node& a, const Node& b) {
        return a.cost > b.cost;
    }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;

	vector<vector<pair<int, int>>> costs(N + 1);

	// 1. 인접 그래프 구현
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		costs[a].push_back({ b, c });
	}

	int s, e;
	cin >> s >> e;

	// 2. 최단 거리 배열 초기화
	vector<int> mDistance(N + 1, INF);

	priority_queue<Node, vector<Node>, compare> pq;

	mDistance[s] = 0;
	pq.push({ s, 0 });

	// 3. 최단 거리 배열 업데이트
	while (!pq.empty())
	{
		Node currentNode = pq.top();
		pq.pop();

		int currentCity = currentNode.city;
		int currentCost = currentNode.cost;

		// 이미 더 짧은 경로를 찾았다면 건너뛰기
		if (mDistance[currentCity] < currentCost)
		{
			continue;
		}

		for (const auto& nextNode : costs[currentCity])
		{
			int nextCity = nextNode.first;
			int nextCost = nextNode.second;

			// 현재 도시를 거쳐 다음 도시로 가는 비용이 더 저렴하다면 업데이트
			if (mDistance[nextCity] > mDistance[currentCity] + nextCost)
			{
				mDistance[nextCity] = mDistance[currentCity] + nextCost;
				pq.push({ nextCity, mDistance[nextCity] });
			}
		}
	}

	cout << mDistance[e];

	return 0;
}