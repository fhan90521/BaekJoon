// 1717.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> setMap;
int Find(int curN)
{
    if (setMap[curN] == curN)
    {
        return curN;
    }
    else
    {
        return setMap[curN] = Find(setMap[curN]);
    }
}
void Union(int n1, int n2)
{
    int N1 = Find(n1);
    int N2 = Find(n2);
    setMap[N2] = N1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    setMap = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        setMap[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int connect;
            cin >> connect;
            if (connect)
            {
                Union(i, j);
            }
        }
    }
    vector<int> road;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        road.push_back(n);
    }
    int setN = Find(road[0]);
    for (int n : road)
    {
        if(setN!=Find(n))
        {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
