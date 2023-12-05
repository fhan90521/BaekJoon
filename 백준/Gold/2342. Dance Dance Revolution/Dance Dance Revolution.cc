// 2342.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <climits>
using namespace std;
long long dp[100001][5][5];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&dp[0][0][0], &dp[100001][0][0], INT_MAX);
	dp[0][0][0] = 0;
	int i = 1;
	long long answer = INT_MAX;
	while (1)
	{
		int next;
		cin >> next;
		if (next == 0)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int j = 0; j < 5; j++)
				{
					answer = min(answer, dp[i - 1][k][j]);
				}
			}
			break;
		}
		else 
		{
			for (int right = 0; right < 5; right++)
			{
				dp[i][next][right] = min(dp[i][next][right], dp[i - 1][next][right] + 1);
				dp[i][next][right] = min(dp[i][next][right], dp[i - 1][0][right] + 2);
				if (next == 1)
				{
					dp[i][next][right] = min(dp[i][next][right], dp[i - 1][4][right] + 3);
				}
				else
				{
					dp[i][next][right] = min(dp[i][next][right], dp[i - 1][next - 1][right] + 3);
				}

				if (next == 4)
				{
					dp[i][next][right] = min(dp[i][next][right], dp[i - 1][1][right] + 3);
				}
				else
				{
					dp[i][next][right] = min(dp[i][next][right], dp[i - 1][next + 1][right] + 3);
				}
				if (next <= 2)
				{
					dp[i][next][right] = min(dp[i][next][right], dp[i - 1][next + 2][right] + 4);
				}
				else
				{
					dp[i][next][right] = min(dp[i][next][right], dp[i - 1][next -2][right] + 4);
				}
				
			}

			for (int left = 0; left < 5; left++)
			{
				dp[i][left][next] = min(dp[i][left][next], dp[i - 1][left][next] + 1);
				dp[i][left][next] = min(dp[i][left][next], dp[i - 1][left][0] + 2);
				if (next == 1)
				{
					dp[i][left][next] = min(dp[i][left][next], dp[i - 1][left][4] + 3);
				}
				else
				{
					dp[i][left][next] = min(dp[i][left][next], dp[i - 1][left][next-1] + 3);
				}

				if (next == 4)
				{
					dp[i][left][next] = min(dp[i][left][next], dp[i - 1][left][1] + 3);
				}
				else
				{
					dp[i][left][next] = min(dp[i][left][next], dp[i - 1][left][next+1] + 3);
				}
				if (next <= 2)
				{
					dp[i][left][next] = min(dp[i][left][next], dp[i - 1][left][next+2] + 4);
				}
				else
				{
					dp[i][left][next] = min(dp[i][left][next], dp[i - 1][left][next-2] + 4);
				}

			}
		}
		i++;
	}
	cout << answer << endl;
}