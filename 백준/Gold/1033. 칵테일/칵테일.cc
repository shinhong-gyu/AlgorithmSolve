#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
	ll _a = a;

	ll _b = b;

	if (b > a)
	{
		ll temp = _b;
		_b = _a;
		_a = temp;
	}

	if (_a % _b == 0)
	{
		return _b;
	}

	return gcd(_b, _a % _b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<bool> visited(N, false);

	vector<tuple<int, int, int>> v[10];

	vector<ll> masses(N);

	stack<int> s;

	ll lcm = 1;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;

		v[a].push_back(make_tuple(b, p, q));
		v[b].push_back(make_tuple(a, q, p));

		lcm *= p * q / gcd(p, q);
	}

	s.push(0);
	int idx = 0;
	masses[0] = lcm;
	visited[0] = true;

	while (!s.empty())
	{
		int top = s.top();

		s.pop();

		for (auto t : v[top])
		{
			idx = get<0>(t);
			int p_val = get<1>(t);
			int q_val = get<2>(t);

			if (!visited[idx])
			{
				masses[idx] = (masses[top] * q_val) / p_val; 
				visited[idx] = true;
				s.push(idx);
			}
		}
	}

	ll GCD = masses[0];

	for (int i = 1; i < masses.size(); i++)
	{
		GCD = gcd(GCD, masses[i]);
	}

	for (ll mass : masses)
	{
		cout << mass/GCD << " ";
	}
}