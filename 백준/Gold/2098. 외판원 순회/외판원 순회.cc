// 2098.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
vector<bool> visited;
long long graph[17][17];
vector<vector<long long>> dp;
int N;
int TopDown(int curN,int visitedBit)
{
	
	if (visitedBit == (1<<N) - 1)
	{
		if (graph[curN][0] != 0)
		{
			return graph[curN][0];
		}
		else
		{
			return INT_MAX;
		}
	}
	if (dp[curN][visitedBit] != 0)
	{
		return dp[curN][visitedBit];
	}
	long long Min = INT_MAX;
	for (int nextN = 0; nextN < N; nextN++)
	{
		if (graph[curN][nextN] != 0&& (visitedBit&1<<nextN)==0)
		{
			Min = min(Min, TopDown(nextN, visitedBit | 1 << nextN) + graph[curN][nextN]);
		}
	}
	return dp[curN][visitedBit]= Min;
}
int main()
{
	cin >> N;
	visited.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++)
	{
		dp[i].resize((1<<N));
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int cost;
			cin >> cost;
			graph[i][j] = cost;
		}
	}
	cout << TopDown(0, 1)<<endl;

}
