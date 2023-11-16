#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;
vector<vector<pair<int,int>>> g_graph;
vector<unsigned int> D;
vector<bool> visited;
struct cmp
{
	bool operator()(pair<int, int>& a, pair<int, int>& b) const
	{
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> p_queue;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E;
	cin >> V >> E;
	int startN;
	cin >> startN;
	g_graph = vector<vector<pair<int,int>>>(V + 1);
	D = vector<unsigned int>(V + 1,INT32_MAX);
	visited = vector<bool>(V + 1);
	for (int i = 1; i <= E; i++)
	{
		int startN, endN, cost;
		cin >> startN >> endN >> cost;
		g_graph[startN].push_back(make_pair(endN, cost));
		
	}
	D[startN] = 0;
	int curN = startN;
	visited[curN] = true;
	
	for (int i = 0; i < V; i++)
	{
		for (auto neighbor : g_graph[curN])
		{
			D[neighbor.first] = MIN(D[neighbor.first],D[curN]+neighbor.second);
			p_queue.push(make_pair(neighbor.first, D[neighbor.first]));
		}
		while (!p_queue.empty())
		{
			auto n_cost = p_queue.top();
			p_queue.pop();
			if (visited[n_cost.first] == false)
			{
				curN = n_cost.first;
				visited[curN] = true;
				break;
			}
		}
	}

	for (int i =1 ;i<=V;i++)
	{
		if (D[i] == INT32_MAX)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << D[i] << '\n';
		}
	}
}

