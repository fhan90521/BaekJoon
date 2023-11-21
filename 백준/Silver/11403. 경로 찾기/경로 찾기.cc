// 11403.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<long long>> distanceMap;
int main()
{
	int n;
	cin >> n;
	distanceMap = vector<vector<long long>>(n);
	for (int i = 0; i < n; i++)
	{
		distanceMap[i] = vector<long long>(n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cost;
			cin >> cost;
			distanceMap[i][j] = cost;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int e = 0; e < n; e++)
			{
				if (distanceMap[s][k]&&distanceMap[k][e])
				{
					distanceMap[s][e] = 1;
				}
			}
		}
	}
	for (int s = 0; s < n; s++)
	{
		for (int e = 0; e < n; e++)
		{
			if (distanceMap[s][e]>0)
			{
				cout << 1 << ' ';
			}
			else
			{
				cout << 0 << ' ';
			}
		}
		cout << endl;
	}
}
