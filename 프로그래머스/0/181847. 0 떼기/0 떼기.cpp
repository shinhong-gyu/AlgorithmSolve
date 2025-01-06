#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    bool bPass =  false;
    for(auto c : n_str)
    {
        if(c != '0')
        {
            bPass = true;
        }
        if(bPass)
        {
            answer+= c;    
        }
        
    }
    return answer;
}