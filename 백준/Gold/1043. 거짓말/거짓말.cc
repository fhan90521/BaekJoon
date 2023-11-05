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
    vector<vector<int>> partys(m);
    for (int i = 1; i <= n; i++)
    {
        setMap[i] = i;
    }
    int trueCnt;
    cin >> trueCnt;
    vector<int> trueN;
    for (int i = 0; i < trueCnt; i++)
    {
        int n;
        cin >> n;
        trueN.push_back(n);
    }

    if (trueCnt > 1)
    {
        for (int i = 0; i + 1 < trueCnt; i++)
        {
            Union(trueN[i], trueN[i + 1]);
        }
    }
    else if (trueCnt == 0)
    {
        cout << m << '\n';
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int nCnt;
        cin >> nCnt;
        int prevN;
        cin >> prevN;
        partys[i].push_back(prevN);
        for (int j = 1; j< nCnt; j++)
        {
            int n;
            cin >> n;
            Union(prevN, n);
            partys[i].push_back(n);
        }
    }
    int answer = m;
    for (vector<int>& party : partys)
    {
        for (int n : party)
        {
            if (Find(n) == Find(trueN[0]))
            {
                answer--;
                break;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
