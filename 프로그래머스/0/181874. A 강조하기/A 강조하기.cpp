#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto c: myString)
    {
        if(c == 'a' || c=='A')
        {
            answer+=toupper(c);
        }
        else
        {
            answer+=tolower(c);
        }      
    }
    return answer;
}