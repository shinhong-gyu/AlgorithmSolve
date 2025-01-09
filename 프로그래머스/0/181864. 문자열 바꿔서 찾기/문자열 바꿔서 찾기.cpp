#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    string change = "";
    for(auto c: myString)
    {
        if(c == 'A')
            change += 'B';
        else
            change += 'A';
    }
    if(change.find(pat)!=string::npos)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}