// 2178.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


struct Node
{
	int x;
	int y;
	int moveLen;
	int remainLen;
};
int n, m;
vector<vector<int>> g_miro;
queue <Node*> g_queue;

void MakeNode(Node* pPrevNode, int x, int y)
{
	Node* pNewNode = new Node;
	pNewNode->moveLen = pPrevNode->moveLen + 1;
	pNewNode->x = x;
	pNewNode->y = y;
	pNewNode->remainLen = abs(n - pNewNode->y) + abs(m - pNewNode->x);
	g_miro[pNewNode->y][pNewNode->x] = 0;
	g_queue.push(pNewNode);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	g_miro = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			g_miro[i + 1][j + 1] = str[j] - '0';
		}
	}
	int answer = 0;
	Node* pStartNode = new Node;
	pStartNode->moveLen = 0;
	pStartNode->remainLen = n + m;
	pStartNode->x = 1;
	pStartNode->y = 1;
	g_queue.push(pStartNode);

	while (g_queue.size() > 0)
	{
		Node* pCurNode = g_queue.front();
		g_queue.pop();
		if (pCurNode->x == m && pCurNode->y == n)
		{
			answer = pCurNode->moveLen;
			break;
		}

		if (g_miro[pCurNode->y - 1][pCurNode->x])
		{
			MakeNode(pCurNode, pCurNode->x, pCurNode->y - 1);
		}
		if (g_miro[pCurNode->y + 1][pCurNode->x])
		{
			MakeNode(pCurNode, pCurNode->x, pCurNode->y + 1);
		}
		if (g_miro[pCurNode->y][pCurNode->x - 1])
		{
			MakeNode(pCurNode, pCurNode->x - 1, pCurNode->y);
		}
		if (g_miro[pCurNode->y][pCurNode->x + 1])
		{
			MakeNode(pCurNode, pCurNode->x + 1, pCurNode->y);
		}
	}
	cout << answer + 1 << '\n';

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
