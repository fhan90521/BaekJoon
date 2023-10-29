#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> nums(N);
    unordered_map<int,vector<int>> originIndexMap;
    unordered_map<int, int> encountMap;
    int prevN=-1;
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        originIndexMap[nums[i]].push_back(i);
    }
    int answer = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < N; i++)
    {
        int indexDiff = originIndexMap[nums[i]][encountMap[nums[i]]++] - i;
        if (answer < indexDiff)
        {
            answer = indexDiff;
        }
    }
    
    cout << answer+1 << '\n';
}