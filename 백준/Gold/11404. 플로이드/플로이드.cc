// 11404.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<long long>> distanceMap;
int main()
{
	int n,m;
	cin >> n >> m;
	distanceMap = vector<vector<long long>>(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		distanceMap[i] = vector<long long>(n + 1,INT_MAX);
	}
	for (int i = 1; i < n + 1; i++)
	{
		distanceMap[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		if (distanceMap[s][e] > cost)
		{
			distanceMap[s][e] = cost;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (distanceMap[s][e] > distanceMap[s][k] + distanceMap[k][e])
				{
					distanceMap[s][e] = distanceMap[s][k] + distanceMap[k][e];
				}
			}
		}
	}
	for (int s = 1; s <= n; s++)
	{
		for (int e = 1; e <= n; e++)
		{
			if (distanceMap[s][e] != INT_MAX)
			{
				cout << distanceMap[s][e] << ' ';
			}
			else
			{
				cout << 0 << ' ';
			}
		}
		cout << endl;
	}
}
