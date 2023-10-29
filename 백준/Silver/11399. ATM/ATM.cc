#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += vec[i] * (n - i);
	}
	cout << sum << '\n';
}
