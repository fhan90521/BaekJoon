// 1744.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long sum = 0;
	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> minusQueue;
	priority_queue<int, vector<int>,less<int>> plusQueue;
	int zeroCnt = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num > 0)
		{
			plusQueue.push(num);
		}
		else if (num == 0)
		{
			zeroCnt++;
		}
		else
		{
			minusQueue.push(num);
		}
	}
	while (minusQueue.size()>=2)
	{
		int n1, n2;
		n1 = minusQueue.top();
		minusQueue.pop();
		n2 = minusQueue.top();
		minusQueue.pop();
		sum += n1 * n2;
	}
	if (minusQueue.size() == 1&&zeroCnt==0)
	{
		sum += minusQueue.top();
	}
	while (plusQueue.size() >= 2)
	{
		int n1, n2;
		n1 = plusQueue.top();
		plusQueue.pop();
		n2 = plusQueue.top();
		plusQueue.pop();
		if (n1 == 1 && n2 == 1)
		{
			sum += 2;
			break;
		}
		else
		{
			if (n2 != 1)
			{
				sum += n1 * n2;
			}
			else
			{
				sum += n1 + n2;
			}
		}
	}
	while(plusQueue.size()>0)
	{
		int n = plusQueue.top();
		sum += n;
		plusQueue.pop();
	}

	cout << sum << '\n';

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
