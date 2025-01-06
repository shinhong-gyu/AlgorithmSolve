#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b)
{
	if(a.second < b.second) return false;
	else if (b.second < a.second) return true;
	else
	{
		return a.first < b.first;
	}
}

vector<int> solution(int N, vector<int> stages) {
   	vector<int> answer;
	map<int, int> m;
	vector<pair<int, float>> v;
	int pass;

	for (auto s : stages)
	{
		if (s <= N)
		{
			m[s]++;
		}
	}


	pass = stages.size();
	for (int i = 1; i <= N; i++)
	{
		int stuck = m[i];
		if (pass > 0)
		{
			v.push_back({i,static_cast<float>(stuck)/pass});
		}
		else
		{
			v.push_back({i,0});
		}
		pass -= stuck;
	}

	sort(v.begin(),v.end(),compare);


    for (auto& p : v) {
        answer.push_back(p.first);
    }

    return answer;
}