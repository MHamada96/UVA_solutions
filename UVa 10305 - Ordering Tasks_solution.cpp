#include<iostream>

#include<fstream>
#include<istream>
#include<ostream>

#include<vector>
#include<deque>
#include<set>
#include<map>
#include<queue>

#include<string>
#include<cstring>
#include<sstream>

#include<cmath>
#include <stdlib.h>
#include<iomanip>
#include<algorithm>
#include<assert.h>

using namespace std;

#define PI		3.14159265
#define OO		1e9
#define S       second
#define F       first  


int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };

//fstream f("output.txt", ios::in | ios::out);
//#define cout f

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
bool vis[109];
vector<int>adj[109];
vector<int> TopoSort;

void clear()
{
	memset(vis, false, sizeof vis);
	TopoSort.clear();
	for (int i = 0; i < 109; i++)
		adj[i].clear();
}
void dfs(int u)
{
	vis[u] = true;

	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!vis[v])
			dfs(v);
	}

	TopoSort.push_back(u);
}
int main()
{

	int n, m;
	while (cin >> n >> m)
	{
		clear();

		if (n == 0 && m == 0)
			return 0;

		int u, v;
		while (m--)
		{
			cin >> u >> v;
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);
		cout << TopoSort[0];
		for (int i = 1; i < TopoSort.size(); i++)
			cout << " " << TopoSort[i];
		cout << endl;
	}

}
