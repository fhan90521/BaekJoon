// 14425.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<set>
#include<string>
using namespace std;
set<string> setN;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        setN.insert(str);
    }
    int answer = 0;
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        if (setN.find(str) != setN.end())
        {
            answer++;
        }
    }
    cout << answer << endl;
}
