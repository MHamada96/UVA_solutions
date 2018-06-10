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

vector<string> v;
vector<vector<char> > grid;
vector<vector<bool> > vis;
vector<vector<int> > ans;
int n, m;

bool valid(int i, int j)
{
	return i < n && j < m && i >= 0 && j >= 0;
}

void DFS(int i, int j, int cnt, char ch)
{
	vis[i][j] = true;
	ans[i][j] = cnt;
	for (int k = 0; k < 8; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if (valid(x, y) && !vis[x][y] && grid[x][y] == ch)
		{
			DFS(x, y, cnt, ch);
		}
	}
}

int main()
{
	fast();
	int ok = 1;
	string s;
	while (true)
	{
		if (bool(getline(cin, s)) == false)
		{
			if (ok)
			{
				ok = false;
				s = "%";
			}
			else
				return 0;
		}
		if (s != "%")
			v.push_back(s);
		else
		{
			//prepare the grid...
			for (int i = 0; i < v.size(); i++)
			{
				grid.push_back(vector<char>());
				for (int j = 0; j < v[i].size(); j++)
				{
					if (v[i][j] != ' ')
						grid[i].push_back(v[i][j]);
				}

				vis.push_back(vector<bool>(grid[i].size(), 0));

				ans.push_back(vector<int>(grid[i].size(), -1));
			}

			int cnt = 0;
			n = grid.size();
			m = grid[0].size();

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (!vis[i][j])
					{
						cnt++;
						DFS(i, j, cnt, grid[i][j]);
					}
				}
			}

			vector<int> len(m);
			for (int j = 0; j < m; j++)
			{
				int mx = 0;
				for (int i = 0; i < n; i++)
					mx = max(mx, ans[i][j]);
				len[j] = log10(mx) + 1;
			}
			for (int i = 0; i < n; i++)
			{
				cout << setw(len[0]) << ans[i][0];
				for (int j = 1; j < m; j++)
					cout << setw(len[j] + 1) << right << ans[i][j];
				cout << endl;
			}
			cout << "%" << endl;

			v.clear();
			vis.clear();
			ans.clear();

			grid.clear();
		}

	}

}