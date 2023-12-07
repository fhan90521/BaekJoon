// 1328.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#define DIVIDE_VAL 1000000007
long dp[102][101][101];
long combinationDP[101][101];
long combination(int n, int r)
{
	if (combinationDP[n][r] != 0)
	{
		return combinationDP[n][r];
	}
	if (n == r || r == 0)
		return 1;
	else
		return combinationDP[n][r] = (combination(n - 1, r - 1) + combination(n - 1, r))% DIVIDE_VAL;
}
long TopDown(long N, long left, long right)
{
	if (dp[N][left][right] != -1)
	{
		return dp[N][left][right];
	}
	
	if (left <= 0 || right <= 0 || N <= 0)
	{
		return 0;
	}

	if (left + right - 1 > N)
	{
		return dp[N][left][right] = 0;
	}

	if (left + right - 1 == N)
	{
		return dp[N][left][right] = combination(N - 1, left - 1);
	}
	else
	{
		long result = 0;
	
		result += TopDown(N-1, left - 1, right)%DIVIDE_VAL + TopDown(N-1, left, right - 1) % DIVIDE_VAL +(TopDown(N-1,left,right)*(N-2)) % DIVIDE_VAL;
		result %= DIVIDE_VAL;
		
		return dp[N][left][right] = result% DIVIDE_VAL;
	}
}
int main()
{
	int N, left, right;
	cin >> N >> left >> right;
	fill(&dp[0][0][0], &dp[101][0][0], -1);
	dp[1][1][1] = 1;
	cout << TopDown(N, left, right);
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
