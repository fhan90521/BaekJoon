// 17387.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
long GetCCW(long x1, long y1, long x2, long y2, long x3, long y3)
{
	long result = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	if (result > 0)
	{
		return 1;
	}
	else if (result == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int main()
{
	long line1x1, line1y1, line1x2, line1y2;
	long line2x1, line2y1, line2x2, line2y2;
	cin >> line1x1 >> line1y1 >> line1x2 >> line1y2;
	cin >> line2x1 >> line2y1 >> line2x2 >> line2y2;
	long a = GetCCW(line1x1, line1y1, line1x2, line1y2, line2x1, line2y1);
	long b = GetCCW(line1x1, line1y1, line1x2, line1y2, line2x2, line2y2);
	long c = GetCCW(line2x1, line2y1, line2x2, line2y2, line1x1, line1y1);
	long d = GetCCW(line2x1, line2y1, line2x2, line2y2, line1x2, line1y2);
	long answer = 0;
	if (a * b <= 0 && c * d <= 0)
	{
		answer = 1;
		if (a ==0 && b==0)
		{
			answer = 0;
			long bigXline1 = max(line1x1, line1x2);
			long smallXline1 = min(line1x1, line1x2);

			long bigYline1 = max(line1y1, line1y2);
			long smallYline1 = min(line1y1, line1y2);

			long bigXline2 = max(line2x1, line2x2);
			long smallXline2 = min(line2x1, line2x2);

			long bigYline2 = max(line2y1, line2y2);
			long smallYline2 = min(line2y1, line2y2);

			if (smallXline1 <= bigXline2 && smallXline2 <= bigXline1 && smallYline1 <= bigYline2 && smallYline2 <= bigYline1)
			{
				answer = 1;
			}
		}
	}
	cout << answer << endl;
}
