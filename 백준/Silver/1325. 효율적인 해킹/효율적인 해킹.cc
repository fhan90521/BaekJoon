// 1325.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> g_graph;
vector<bool> g_visited;


int graph_size = 0;
int biggest_graph_size = 0;


vector<int> g_trust;

void dfs(int curN)
{
	g_visited[curN] = true;
	graph_size++;
	for (int neighbor : g_graph[curN])
	{
		if (g_visited[neighbor] == false)
		{
			dfs(neighbor);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	g_visited = vector<bool>(N + 1, false);
	g_trust = vector<int>(N + 1, 0);
	g_graph = vector<vector<int>>(N+1);
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		g_graph[n2].push_back(n1);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(g_visited.begin(), g_visited.end(), false);
		graph_size = 0;
		dfs(i);
		g_trust[i] = graph_size;
		if (biggest_graph_size < graph_size)
		{
			biggest_graph_size = graph_size;
		}
	}
	for (int i=1;i<=N;i++)
	{
		if (g_trust[i] == biggest_graph_size)
		{
			cout << i << ' ';
		}
	}
	cout << '\n';
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
