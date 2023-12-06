// 11758.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int GetCCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (x1 * y2+x2 * y3+x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
}
int main()
{
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int CCW = GetCCW(x1, y1, x2, y2, x3, y3);
	if (CCW > 0)
	{
		cout << 1 << endl;
	}
	else if (CCW == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}
