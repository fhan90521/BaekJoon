// 1197.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> edge;
vector<int> setMap;
vector<edge> edges;
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
    int N;
    cin >> N;
    setMap = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        setMap[i] = i;
    }
    int totalCost = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char cost;
            cin >> cost;
            if (cost != '0')
            {
                if (cost < 'a')
                {
                    totalCost += cost - 'A' + 27;
                    edges.push_back(make_tuple(cost - 'A' + 27, i, j));
                }
                else
                {
                    totalCost += cost - 'a' + 1;
                    edges.push_back(make_tuple(cost - 'a' + 1, i, j));
                }
            }
        }
    }
    sort(edges.begin(), edges.end());

    int minCost = 0;
    int edgeCnt = 0;
    for (edge& tmp : edges)
    {
        int cost = get<0>(tmp);
        int s = get<1>(tmp);
        int e = get<2>(tmp);
        if (Find(s) != Find(e))
        {
            Union(s, e);
            minCost += cost;
            edgeCnt++;
            if (edgeCnt > N - 1)
            {
                break;
            }
        }
    }
    if (edgeCnt < N - 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << totalCost - minCost << endl;
    }
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
