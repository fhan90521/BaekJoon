// 1707.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;
vector<vector<int>> g_graph;
vector <int> g_visited;
bool bfs(int startN)
{
	list<int> queue;
	queue.push_back(startN);
	g_visited[startN] = 1;
	while (queue.size() > 0)
	{
		int curN = queue.front();
		queue.pop_front();
		for (int neighbor : g_graph[curN])
		{
			if (g_visited[neighbor] == 0)
			{
				g_visited[neighbor] = g_visited[curN] * -1;
				queue.push_back(neighbor);
			}
			else
			{
				if (g_visited[neighbor] == g_visited[curN])
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	int k, n, m;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n >> m;
		g_visited = vector<int>(n + 1);
		g_graph = vector<vector<int>>(n + 1);
		for (int i = 0; i < m; i++)
		{
			int n1, n2;
			cin >> n1 >> n2;
			g_graph[n1].push_back(n2);
			g_graph[n2].push_back(n1);
		}
		bool yes = true;
		for (int i = 1; i <= n; i++)
		{
			if (g_visited[i] == false)
			{
				if (!bfs(i))
				{
					yes = false;
					break;
				}
			}
		}
		if (yes)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
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
