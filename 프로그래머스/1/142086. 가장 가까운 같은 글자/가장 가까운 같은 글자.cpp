#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> solution(string s)
{
    vector<int> answer;
    vector<int> checked(26,0);
    int idx;
    for(int i = 0 ; i < s.length();i++)
    {
        idx = s[i]-'a';
        if(s.find(s[i]) >= i)
        {
            answer.push_back(-1);
            checked[idx] = i;
        }
        else
        {
            answer.push_back(i-s.find(s[i],checked[idx]));
            checked[idx] = i;
        }
    }
    return answer;
}