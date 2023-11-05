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
         return setMap[curN]=Find(setMap[curN]);
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
    for (int i = 0; i < m; i++)
    {
        int oper, n1, n2;
        cin >> oper >> n1 >> n2;
        if (oper == 0)
        {
            Union(n1, n2);
        }
        else if (oper == 1)
        {
            if (Find(n1) == Find(n2))
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
}
