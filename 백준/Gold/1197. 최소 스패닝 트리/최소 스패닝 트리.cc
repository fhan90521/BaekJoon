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
    int V, E;
    cin >> V >> E;
    setMap = vector<int>(V + 1);
    for (int i = 1; i <= V; i++)
    {
        setMap[i] = i;
    }
    for (int i = 0; i < E; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        edges.push_back(make_tuple(cost,s,e));
    }
    sort(edges.begin(), edges.end());
    
    int totalCost = 0;
    int edgeCnt = 0;
    for (edge& tmp : edges)
    {
        int cost = get<0>(tmp);
        int s = get<1>(tmp);
        int e = get<2>(tmp);
        if (Find(s) != Find(e))
        {
            Union(s, e);
            totalCost += cost;
            edgeCnt++;
            if (edgeCnt >V-1 )
            {
                break;
            }
        }
    }
    cout << totalCost << endl;
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
