#include <iostream>
#include <string> // std::string 사용을 위해 포함

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    cin >> M;
    string S; 
    cin >> S;

    int answer = 0;
    int count_oi = 0; 

 
    for (int i = 0; i < M; ++i) 
    {
        if (S[i] == 'I') 
        {
            if (i + 2 < M && S[i+1] == 'O' && S[i+2] == 'I') 
            {
                count_oi++; 
                i++;
            } else 
                {
                if (count_oi >= N) 
                {
                    answer += (count_oi - N + 1);
                }
                count_oi = 0;
            }
        } 
        else 
        { 
            if (count_oi >= N) 
            {
                answer += (count_oi - N + 1);
            }
            count_oi = 0;
        }
    }


    if (count_oi >= N) 
    {
        answer += (count_oi - N + 1);
    }

    cout << answer << endl;

    return 0;
}