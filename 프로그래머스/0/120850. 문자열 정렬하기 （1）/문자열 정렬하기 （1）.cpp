#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    sort(my_string.begin(),my_string.end());
    
    for(auto c : my_string)
    {
        if(isdigit(c) != 0)
        {
            answer.push_back(c-'0');
        }
    }
    return answer;
}