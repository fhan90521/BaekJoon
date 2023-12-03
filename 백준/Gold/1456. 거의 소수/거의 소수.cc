// 1456.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<bool> bPrime;
int main()
{
    long long start, end;
    cin >> start >> end;
    long long arrSize;
    double tmp=sqrt(end);
    arrSize = tmp;
    if (arrSize != tmp)
    {
        arrSize++;
    }
        
    bPrime = vector<bool>(arrSize + 1,true);
    bPrime[1] = false;
    for (long long i = 2; i<= arrSize; i++)
    {
        if (bPrime[i])
        {
            for (long long j = i*2; j <= arrSize; j+= i)
            {
                if (j < 0)
                {
                    break;
                }
                bPrime[j] = false;
            }
        }
    }
    long long answer = 0;
    for (long long i = 2; i<= arrSize; i++)
    {
        if (bPrime[i])
        {
            long temp = i;
            while((double)(i)*(double)temp <= (double)end)
            {
                temp = temp * i;
                if (temp >= start)
                {
                    answer++;
                }
                
            }
        }
    }
    cout << answer << endl;

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않