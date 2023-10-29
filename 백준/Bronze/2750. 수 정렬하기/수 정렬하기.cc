#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int v: vec)
    {
        cout << v << '\n';
    }
}
