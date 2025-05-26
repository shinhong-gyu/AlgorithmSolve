#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> lst(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> lst[i];
    }

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (lst[j] > lst[j + 1])
            {
                int temp = lst[j + 1];
                lst[j + 1] = lst[j];
                lst[j] = temp;
            }
        }
    }

    for (int num : lst)
    {
        cout << num << "\n";
    }
    return (0);
}