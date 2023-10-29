#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string N;
    cin >> N;
    sort(N.begin(), N.end(), greater<char>());
    cout << N << '\n';
}