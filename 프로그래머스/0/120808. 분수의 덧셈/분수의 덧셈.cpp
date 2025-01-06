#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int ShareDenom = denom1*denom2;
    numer1 = numer1*denom2;
    numer2 = numer2*denom1;
    int numer3 = numer1+numer2;
    for(int i = ShareDenom; i>=1; i--){
        if(ShareDenom%i == 0 && numer3%i ==0){
            ShareDenom /= i;
            numer3 /= i;
        }
    }
    answer.push_back(numer3);
    answer.push_back(ShareDenom);
    return answer;
}