// 2251.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <list>
using namespace std;
int pickCase[3][2] = { {1,2},{0,2},{0,1} };
int basketSize[3];

struct Node
{
	int water[3];
	bool operator=(const Node& other) const
	{
		for (int i = 0; i < 3; i++)
		{
			if (other.water[i] != water[i])
			{
				return false;
			}
		}
		return true;
	}
};
unordered_set<int> g_visited;
Node CreateNode(Node curNode,int give, int recv)
{
	curNode.water[recv] = curNode.water[recv] + curNode.water[give];
	if (curNode.water[recv] > basketSize[recv])
	{
		curNode.water[give] = curNode.water[recv] - basketSize[recv];
		curNode.water[recv] = basketSize[recv];
	}
	else
	{
		curNode.water[give] = 0;
	}
	return curNode;
}
int main()
{
	cin >> basketSize[0] >> basketSize[1] >> basketSize[2];
	
	list<Node> queue;
	Node startN;
	startN.water[0] = 0;
	startN.water[1] = 0;
	startN.water[2] = basketSize[2];
	int key = (startN.water[0] << 16) + (startN.water[1] << 8) + startN.water[2];
	g_visited.insert(key);
	queue.push_back(startN);
	set<int> answers;
	while (queue.size() > 0)
	{
		Node curNode = queue.front();
		queue.pop_front();
		if (curNode.water[0] == 0)
		{
			answers.insert(curNode.water[2]);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				Node neighbor = CreateNode(curNode, i, pickCase[i][j]);
				int key = (neighbor.water[0] << 16) + (neighbor.water[1] << 8) + neighbor.water[2];
				if (g_visited.find(key) == g_visited.end())
				{
					g_visited.insert(key);
					queue.push_back(neighbor);
				}
			}
		}
	}
	for (int answer : answers)
	{
		cout << answer << ' ';
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
