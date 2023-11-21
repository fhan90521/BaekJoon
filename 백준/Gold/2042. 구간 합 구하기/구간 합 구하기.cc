// 2042.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
vector<long long> sTreeVec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N, M, K;
	cin >> N >> M >> K;
	long long size = 1;
	while (1)
	{
		size *= 2;
		if (size >= N)
		{
			size *= 2;
			break;
		}
	}
	sTreeVec = vector<long long>(size,0);
	for (long long i = 0; i < N; i++)
	{
		long long n;
		cin >> n;
		sTreeVec[size / 2 + i] = n;
	}
	for (long long i = size/2 - 1; i >= 1; i--)
	{
		sTreeVec[i] = sTreeVec[i * 2] + sTreeVec[i * 2 + 1];
	}

	for (int i = 0; i < M+K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			long long index = size / 2 + b-1;
			sTreeVec[index] = c;
			index /= 2;
			while (index >= 1)
			{
				sTreeVec[index] = sTreeVec[index * 2] + sTreeVec[index * 2 + 1];
				index /= 2;
			}
		}
		else if(a==2)
		{
			long long sum = 0;
			long long start_index = size / 2 + b-1;
			long long end_index = size / 2 + c - 1;
			while (start_index <= end_index)
			{
				if (start_index % 2 == 1)
				{
					sum += sTreeVec[start_index];
				}
				start_index = (start_index + 1) / 2;
				if (end_index % 2 == 0)
				{
					sum += sTreeVec[end_index];
				}
				end_index = (end_index - 1) / 2;
			}
			cout << sum << '\n';
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
