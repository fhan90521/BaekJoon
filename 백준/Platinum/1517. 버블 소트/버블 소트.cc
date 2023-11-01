// 1377.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> A;
vector<int> tmp;
long result;
void merge_sort(int s, int e)
{
    if (e - s < 1)
    {
        return;
    }
    int m = s + (e - s) / 2;
    merge_sort(s, m);
    merge_sort(m + 1, e);
    for (int i = s; i <= e; i++)
    {
        tmp[i] = A[i];
    }
    int k = s;
    int index1 = s;
    int index2 = m + 1;

    while (index1 <= m && index2 <= e)
    {
        if (tmp[index1] > tmp[index2])
        {
            A[k] = tmp[index2];
            result = result + index2 - k;
            k++;
            index2++;
        }
        else
        {
            A[k] = tmp[index1];
            k++;
            index1++;
        }
    }

    while (index1 <= m)
    {
        A[k] = tmp[index1];
        k++;
        index1++;
    }

    while (index2 <= e)
    {
        A[k] = tmp[index2];
        k++;
        index2++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    A = vector<int>(N + 1, 0);
    tmp = vector<int>(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    result = 0;
    merge_sort(1, N);
    cout << result << '\n';
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
