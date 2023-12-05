// 11049.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<pair<int, int>> Matrixs(501);
int dp[501][501];
int TopDown(int begin, int end)
{
    if (dp[begin][end] != INT_MAX)
    {
        return dp[begin][end];
    }
    if (begin == end)
    {
        return dp[begin][end]=0;
    }
    else if (begin + 1 == end)
    {
        return dp[begin][end]=Matrixs[begin].first * Matrixs[begin].second * Matrixs[end].second;
    }
    else
    {
        for (int i = begin; i <= end - 1; i++)
        {
            dp[begin][end] = min(dp[begin][end],
                TopDown(begin, i) + TopDown(i + 1, end) + Matrixs[begin].first*Matrixs[i].second*Matrixs[end].second);
        }
        return  dp[begin][end];
    }
}
int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Matrixs[i].first >> Matrixs[i].second;
    }
    fill(&dp[0][0], &dp[500][501], INT_MAX);
    cout << TopDown(1, N) << endl;
}

