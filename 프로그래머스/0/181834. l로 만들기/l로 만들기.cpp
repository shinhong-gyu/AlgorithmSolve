#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto c : myString)
    {
        if(c < 'l')
        {
            answer += 'l';
        }
        else
        {
            answer += c;
        }
    }
    return answer;
}