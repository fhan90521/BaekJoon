// 11437.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> heightMap;
vector<vector<int>> parentMap;
vector<vector<int>> g_graph;
vector<bool> visited;
int maxHeight = 0;
int maxK = -1;
void dfs(int curN, int parentN,int height)
{
    heightMap[curN] = height;
    visited[curN] = true;
    parentMap[0][curN] = parentN;
    if (maxHeight < height)
    {
        maxHeight = height;
    }
    for (int neighbor : g_graph[curN])
    {
        if (visited[neighbor] == false)
        {
            dfs(neighbor, curN, height + 1);
        }
    }
}
int main()
{
    int N;
    cin >> N;
    heightMap = vector<int>(N+1);
    g_graph = vector<vector<int>>(N + 1);
    visited = vector<bool>(N + 1);
    parentMap = vector<vector<int>>(1);
    
    parentMap[0] = vector<int>(N + 1);
  
    for (int i = 0; i < N - 1; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        g_graph[n1].push_back(n2);
        g_graph[n2].push_back(n1);
    }
    dfs(1, 0, 1);
    int maxParentDiff = maxHeight - 1;
    while (maxParentDiff > 0)
    {
        maxParentDiff /= 2;
        maxK++;
    }

    parentMap.resize(maxK+1);
    for (int i = 1; i <= maxK; i++)
    {
        parentMap[i] = vector<int>(N + 1);
    }

    for (int k = 1; k <= maxK; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            parentMap[k][i] = parentMap[k - 1][parentMap[k - 1][i]];
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if(heightMap[n1] != heightMap[n2])
        {
            int heightDiff; 
            if (heightMap[n1] < heightMap[n2])
            {
                heightDiff = heightMap[n2] - heightMap[n1];
                while (heightDiff > 0)
                {
                    int k = -1;
                    int tmpDiff = heightDiff;
                    while (tmpDiff > 0)
                    {
                        tmpDiff /= 2;
                        k++;
                    }
                    n2 = parentMap[k][n2];
                    heightDiff = heightMap[n2] - heightMap[n1];
                }
            }
            else
            {
                heightDiff = heightMap[n1] - heightMap[n2];
                while (heightDiff > 0)
                {
                    int k = -1;
                    int tmpDiff = heightDiff;
                    while (tmpDiff > 0)
                    {
                        tmpDiff /= 2;
                        k++;
                    }
                    n1= parentMap[k][n1];
                    heightDiff = heightMap[n1] - heightMap[n2];
                }
            }
        }
        int k = maxK;
        while (k >= 0)
        {
            if (parentMap[k][n1] != parentMap[k][n2])
            {
                n1 = parentMap[k][n1];
                n2 = parentMap[k][n2];
            }
            k--;
        }
        if (n1 == n2)
        {
            cout << n1 << '\n';
        }
        else
        {
            cout << parentMap[0][n1] << '\n';
        }
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
