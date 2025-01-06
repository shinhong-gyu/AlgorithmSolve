#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    int mode = 0;
    for(int i =0; i < code.length();i++){
        if(code[i] == '1') {
            if(mode == 1) mode = 0;
            else mode = 1;
            continue;
        }
        if(mode == 0){
            if(i%2 == 0) answer += code[i];
        }
        else {
            if(i%2 == 1) answer += code[i];
        }
    }
    if(answer.length() == 0) answer = "EMPTY";
    return answer;
}