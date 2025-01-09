#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for(auto str : strArr)
    {
        if(str.find("ad") == string::npos)
        {
            answer.push_back(str);            
        }
    }
    return answer;
}