#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> g_graph;
vector<int> D;
vector<bool> visited;
struct cmp
{
	bool operator()(pair<int, int>& a, pair<int, int>& b) const
	{
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> p_queue;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E;
	cin >> V >> E;
	g_graph = vector<vector<pair<int, int>>>(V + 1);
	D = vector<int>(V + 1, INT_MAX);
	visited = vector<bool>(V + 1);
	for (int i = 1; i <= E; i++)
	{
		int startN, endN, cost;
		cin >> startN >> endN >> cost;
		g_graph[startN].push_back(make_pair(endN, cost));

	}
	int startN,endN;
	cin >> startN>>endN;
	D[startN] = 0;
	p_queue.push(make_pair(startN, 0));
	while (!p_queue.empty())
	{
		auto curN_cost = p_queue.top();
		p_queue.pop();
		if (visited[curN_cost.first] == true)
		{
			continue;
		}
		visited[curN_cost.first] = true;
		for (auto next_cost : g_graph[curN_cost.first])
		{
			if (D[next_cost.first] > D[curN_cost.first] + next_cost.second)
			{
				D[next_cost.first] = D[curN_cost.first] + next_cost.second;
				p_queue.push(make_pair(next_cost.first, D[next_cost.first]));
			}
		}
	}

	cout << D[endN];
}

