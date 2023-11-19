// 1219.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <limits.h>
#include <set>
using namespace std;

map<pair<int,int>,int> edgesMap;
vector<set<int>> endToStartMap;
vector<long long> distanceMap;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, startN, endN, M;
	cin >> N >> startN >> endN >> M;
	endToStartMap = vector<set<int>>(N);
	distanceMap = vector<long long>(N,INT_MAX);
	distanceMap[startN] = 0;
	for (int i = 0; i < M; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		endToStartMap[e].insert(s);
		auto tmp = make_pair(s, e);
		if (edgesMap.find(tmp) == edgesMap.end())
		{
			edgesMap[tmp] = cost;
		}
		else
		{
			if (edgesMap[tmp] > cost)
			{
				edgesMap[tmp] = cost;
			}
		}
	}

	for (int e = 0; e < N; e++)
	{
		int earn;
		cin >> earn;
		if (earn > 0)
		{
			if (e == startN)
			{
				distanceMap[startN] -= earn;
			}
			for (int s : endToStartMap[e])
			{
				edgesMap[make_pair(s, e)] -= earn;
			}
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (auto& tmp : edgesMap)
		{
			int s, e, cost;
			s = tmp.first.first;
			e = tmp.first.second;
			cost = tmp.second;
			if (distanceMap[s] != INT_MAX && distanceMap[e] > distanceMap[s] + cost)
			{
				distanceMap[e] = distanceMap[s] + cost;
			}
		}
	}

	bool minusLoop = false;
	for (int i = 0; i <M; i++)
	{
		for (auto& tmp : edgesMap)
		{
			int s, e, cost;
			s = tmp.first.first;
			e = tmp.first.second;
			cost = tmp.second;
			if (distanceMap[s] != INT_MAX && (distanceMap[e]==INT_MIN||
                                              distanceMap[e] > distanceMap[s] + cost))
			{
				distanceMap[e] = INT_MIN;
				if (e == endN)
				{
					minusLoop = true;
                    break;
				}
			}
		}
        if(minusLoop)
        {
            break;
        }
	}
	if (distanceMap[endN] == INT_MAX)
	{
		cout << "gg" << endl;
	}
	else
	{
		if (minusLoop)
		{
			cout << "Gee" << endl;
		}
		else
		{
			cout << distanceMap[endN] * -1 << endl;
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
