#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    // n(콜라병이) a 미만이 될 때까지 반복
    while(n >= a){
        // n을 a로 나눈거의 b배만큼 콜라병을 얻음
        answer += (n/a)*b;
        // n을 a로 나누고 나머지는 다음 번째 빈 병 수에 더해줌
        n = n/a*b + n%a;
    }
    return answer;
}