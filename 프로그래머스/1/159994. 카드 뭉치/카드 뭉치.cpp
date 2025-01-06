#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idx1 = 0;
    int idx2 = 0;
    // 각 배열의 턴마다 무조건 하나씩은 사용해야됨
    for(int i = 0; i < goal.size(); i++)
    {
        // card1의 요소를 goal의 요소랑 비교
        if(cards1[idx1] == goal[i])
        {
            cout << cards1[idx1] <<endl;
            // 검사할 인덱스 증가
            idx1++;
            answer = "Yes";
            continue;
        }
        if(cards2[idx2] == goal[i])
        {   
            cout << cards2[idx2] <<endl;
            // 검사할 인덱스 증가
            idx2++;
            answer = "Yes";
            continue;
        }
    }
    if(idx1+idx2 != goal.size())
    {
        answer = "No";
    }
    else
    {
        answer = "Yes";
    }
    return answer;
}