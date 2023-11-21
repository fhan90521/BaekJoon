// 11403.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<long long>> distanceMap;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	distanceMap = vector<vector<long long>>(n + 1);
	for (int i = 1; i <= n; i++)
	{
		distanceMap[i] = vector<long long>(n + 1, INT_MAX);
	}
	for (int i = 1; i <= m; i++)
	{
		int s, e;
		cin >> s >> e;
		distanceMap[s][e] = 1;
		distanceMap[e][s] = 1;
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
	int min = INT_MAX;
	int min_s = 0;
	for (int s = 1; s <= n; s++)
	{
		int sum = 0;
		for (int e = 1; e <= n; e++)
		{
			sum += distanceMap[s][e];
		}
		if (sum < min)
		{
			min = sum;
			min_s = s;
		}
	}
	cout << min_s << endl;

}
