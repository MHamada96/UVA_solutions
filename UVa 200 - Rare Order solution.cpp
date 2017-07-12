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

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool vis[26], appeared[26];
vector<int> adj[26];
vector<int> TopoSort;

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

	string current, prev;

	cin >> prev;
	while (cin >> current && current != "#")
	{
		for (int i = 0; i < min(current.size(), prev.size()); i++)
		{
			if (current[i] != prev[i])
			{
				appeared[current[i] - 'A'] = true;
				appeared[prev[i] - 'A'] = true;

				adj[prev[i] - 'A'].push_back(current[i] - 'A');
				break;
			}
		}

		prev = current;
	}

	for (int i = 0; i < 26; i++)
	if (!vis[i] && appeared[i])
		dfs(i);


	for (int i = TopoSort.size() - 1; i >= 0; i--)
		cout << char(TopoSort[i] + 'A');

	cout << endl;
}s
