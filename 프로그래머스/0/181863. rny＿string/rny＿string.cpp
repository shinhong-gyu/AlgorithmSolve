#include <string>
#include <vector>
#include <string.h>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    for(auto c : rny_string){
        if(c == 'm') answer += "rn";
        else answer += c;
    }
    return answer;
}