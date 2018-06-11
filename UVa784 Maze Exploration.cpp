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

vector<string> grid;
int n, m;
bool valid(int i, int j)
{
	return i < n && j < m && i >= 0 && j >= 0;
}

void DFS_Flood_fill(int i, int j)
{
	m = grid[i].size();

	grid[i][j] = '#';

	int x, y;
	for (int k = 0; k < 4; k++)
	{
		x = i + dx[k];
		y = j + dy[k];
		if (valid(x, y) && grid[x][y] == ' ')
			DFS_Flood_fill(x, y);
	}
}

int main()
{
	fast();
	int t;
	string s;
	cin >> t;
	for (int T = 1; T <= t; T++)
	{
		while (getline(cin, s) && s.find("_") == -1)
		if (s.size()) // getline can get empty string.... 
			grid.push_back(s);

		int x, y;

		n = grid.size();

		for (int i = 0; i < n; i++)
		for (int j = 0; j < grid[i].size(); j++)
		if (grid[i][j] == '*')
			x = i, y = j;

		DFS_Flood_fill(x, y);

		for (int i = 0; i < n; i++)
		{
			cout << grid[i] << endl;

			if (i == n - 1)
				cout << s << endl;
		}

		grid.clear();
	}

}