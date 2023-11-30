// 9252.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <memory.h>
using namespace std;
int d[1005][1005];
list <char> answer;
string str1, str2;
int maxLen;
void getText(int iStr1, int iStr2, int findNum)
{
    if (findNum == maxLen)
    {
        return;
    }
    if (str1[iStr1-1] == str2[iStr2-1])
    {
        answer.push_front(str1[iStr1-1]);
        getText(iStr1 - 1, iStr2 - 1, findNum+1);
    }
    else
    {
        if (d[iStr2 - 1][iStr1] > d[iStr2][iStr1 - 1])
        {
            getText(iStr1, iStr2 - 1, findNum);
        }
        else
        {
            getText(iStr1 - 1, iStr2, findNum);
        }
    }
}
int main()
{
    cin >> str1 >> str2;
    for (int i = 1; i <= str2.length(); i++)
    {
        for (int j = 1; j <= str1.length(); j++)
        {
            if (str2[i-1] == str1[j-1])
            {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }


    maxLen = d[str2.length()][str1.length()];
    cout << maxLen << '\n';
    if (maxLen > 0)
    {
        getText(str1.length(), str2.length(), 0);
        for (char ch : answer)
        {
            cout << ch;
        }
    }
}

