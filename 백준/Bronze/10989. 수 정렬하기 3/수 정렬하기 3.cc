#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> vec(10001);
    for (int i = 0; i < N; i++)
    {
        int index;
        cin >> index;
        vec[index]++;
    }
    for (int i=1;i<=10000;i++)
    {
        for (int j = 0; j < vec[i]; j++)
        {
            cout << i << '\n';
        }
    }
}

