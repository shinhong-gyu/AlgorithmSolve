#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(auto n: arr)
    {
        for(int i = 0 ; i < n; i ++)
        {
            answer.push_back(n);
        }
    }
    return answer;
}