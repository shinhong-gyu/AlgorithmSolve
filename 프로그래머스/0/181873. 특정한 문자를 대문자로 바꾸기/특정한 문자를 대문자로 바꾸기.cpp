#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    char a = alp[0];
    for(auto c : my_string)
    {
        if(c == a)
        {
            answer += toupper(c);
        }
        else
        {
            answer += c;
        }
    }
    return answer;
}