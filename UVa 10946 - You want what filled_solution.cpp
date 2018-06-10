#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;
#define PI			3.14159265
#define OO			1e9
#define SS       	second
#define FF       	first  
#define Trace(n)  	cout<< #n <<" = "<< n << endl; 
#define ll			long long
#define endl		"\n"


int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

int n, m;
bool vis[100][100];
char grid[100][100];
int cnt;
vector<pair<char, int> >v;

bool valid(int i, int j)
{
	return i < n && j < m && i >= 0 && j >= 0;
}

void dfs(int i, int j, char c)
{
	vis[i][j] = true;
	cnt++;

	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if (valid(x, y) && !vis[x][y] && grid[x][y] == c)
		{
			dfs(x, y, c);
		}
	}
}

int main()
{
	fast();
	int T = 0;
	while (cin >> n >> m && (n > 0 && m > 0))
	{
		T++;
		memset(vis, 0, sizeof  vis);
		v.clear();

		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '.')
					continue;

				if (!vis[i][j])
				{
					cnt = 0;
					dfs(i, j, grid[i][j]);
					v.push_back({ grid[i][j], cnt });
				}
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[j].SS>v[i].SS || (v[j].SS == v[i].SS && v[j].FF < v[i].FF))
					swap(v[i], v[j]);
			}
		}
		cout << "Problem " << T << ":" << endl;
		for (int i = 0; i < v.size(); i++)
			cout << v[i].FF << " " << v[i].SS << endl;
	}
}
