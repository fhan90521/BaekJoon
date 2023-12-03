// 1747.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<bool> bPrime;
int main()
{
	bPrime.resize(10000001, true);
	bPrime[1] = false;
	for (long long i = 2; i <= 10000000; i++)
	{
		if (bPrime[i])
		{
			for (long long j = i * 2; j <= 10000000; j+=i)
			{
				bPrime[j] = false;
			}
		}
	}
	long long n;
	cin >> n;
	for (long long i = n; i <= 10000000; i++)
	{
		if (bPrime[i])
		{
			string str = to_string(i);
			long long left = 0;
			long long right = str.length() - 1;
			bool bP = true;
			while (left <= right)
			{
				if (str[left] != str[right])
				{
					bP = false;
					break;
				}
				left++;
				right--;
			}
			if (bP)
			{
				cout << i << endl;
				break;
			}
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
